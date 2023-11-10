#include "DifferentialEvolution.h"

/// <summary>
/// Le constructeur par défault
/// </summary>
DifferentialEvolution::DifferentialEvolution() :
	mParameters{DEParameters()},
	mCurrentGeneration{0},
	mX{DEPopulation()},
	mM{ DEPopulation() },
	mT{ DEPopulation() },
	mStatistics { DEStatistics()},
	mSamplingTool{ThreeSamplesWithOneExclusion(4)} 
{
}

/// <summary>
/// Retourne les parametres
/// </summary>
/// <returns>Les paramtres</returns>
DEParameters DifferentialEvolution::parameters() const
{
	return mParameters;
}

/// <summary>
/// Si les parametre sont correctement configurées reourne vrai
/// </summary>
/// <returns>Si les parametre sont correctement configurées</returns>
bool DifferentialEvolution::isReadyToEvolve() const
{
	return mParameters.isReady();
}

/// <summary>
/// Retourne le nombre associé à la génération en cours
/// </summary>
/// <returns>le nombre associé à la génération en cours</returns>
size_t DifferentialEvolution::currentGeneration() const
{
	return mCurrentGeneration;
}

/// <summary>
/// Retourne vrai si nous avons atteint la taille maximum de la génération
/// </summary>
/// <returns>si nous avons atteint la taille maximum de la génération</returns>
bool DifferentialEvolution::isMaximumGenerationReached() const
{
	return mCurrentGeneration >= mParameters.maximumGenerationCount();
}

/// <summary>
/// Retourne la meilleur solution présente dans la liste statistiques
/// </summary>
/// <returns>la meilleur solution présente dans la liste statistiques</returns>
DESolution DifferentialEvolution::bestSolution() const
{
	return mStatistics.bestSolution();
}


/// <summary>
/// Prépare les différentes population et les parametre pour commencer l'évolution différentiel
/// </summary>
/// <param name="parameters">Les parametres à utiliser</param>
void DifferentialEvolution::setup(DEParameters const& parameters)
{
	mParameters = parameters;
	mX.setup(mParameters.populationSize(), mParameters.domain());
	mM.setup(mParameters.populationSize(), mParameters.domain());
	mT.setup(mParameters.populationSize(), mParameters.domain());
	mX.randomize(mParameters.domain());
	mSamplingTool = ThreeSamplesWithOneExclusion(mParameters.populationSize());
}

/// <summary>
/// Réinitialise les populations
/// </summary>
void DifferentialEvolution::reset()
{
	mX.setup(mParameters.populationSize(), mParameters.domain());
	mM.setup(mParameters.populationSize(), mParameters.domain());
	mT.setup(mParameters.populationSize(), mParameters.domain());
}

/// <summary>
/// Effectue l'evolution différentiel dès que le nombre de génération atteint le maximum
/// </summary>
/// <returns>Vrai lorsque terminé et faux si il n'était pas possible d'évoluer/returns>
bool DifferentialEvolution::evolve()
{
	while (mCurrentGeneration < mParameters.maximumGenerationCount())
	{
		evolveOne();
	}
	return true;
}

/// <summary>
/// Effectue une passe d'évolution
/// </summary>
void DifferentialEvolution::evolveOne()
{
	processMutation();
	processCrossover();
	processSelection();
	processStatistics();
	mCurrentGeneration++;
}
/// <summary>
/// Retourne une valeur aleatoire de R
/// </summary>
/// <returns>une valeur aleatoire de R</returns>
size_t DifferentialEvolution::randomR()
{
	return Random::integer(0, mParameters.domain().size() - 1);
}

/// <summary>
/// Retourne une valeur aléatoire entre 0 et 1
/// </summary>
/// <returns>une valeur aléatoire entre 0 et 1</returns>
DifferentialEvolution::real DifferentialEvolution::randomCR()
{
	return Random::real(0, 1);
}

/// <summary>
/// Effectue l'évaluation de la fitness des solutions
/// </summary>
/// <param name="population">La population à evaluer</param>
void DifferentialEvolution::processFitness(DEPopulation& population)
{
	for (size_t i = 0; i < mParameters.populationSize(); i++) {
		mX[i].evaluate(mParameters.objectiveFunction(), mParameters.fitnessFunction());
	}
}

/// <summary>
/// Effectue la passe de mutation pour l'évolution différentiel
/// </summary>
void DifferentialEvolution::processMutation()
{
	mSamplingTool.prepare(mParameters.populationSize());

	for (size_t i = 0; i < mParameters.populationSize() ; i++){
		size_t s1, s2, s3;
		mSamplingTool.select(i, s1, s2, s3);
		for (size_t p = 0; p < mParameters.domain().size(); p++) {
			mM[i][p] = mX[s1][p] + mParameters.f() * (mX[s2][p] - mX[s3][p]);
			if (mM[i][p] > mParameters.domain()[p].higher()) {
				mM[i][p] = mParameters.domain()[p].higher();
			}
			
			if (mM[i][p] < mParameters.domain()[p].lower()) {
				mM[i][p] = mParameters.domain()[p].lower();
			}
		}
	}
}

/// <summary>
/// Effectue la passe de croisement pour l'évolution différentiel
/// </summary>
void DifferentialEvolution::processCrossover()
{
	for (size_t i = 0; i < mParameters.populationSize(); i++) {
		size_t r = randomR();

		for (size_t p = 0; p < mParameters.domain().size(); p++) {
			if (r == i && randomCR() < mParameters.cR())
			{
				mT[i][p] = mM[i][p];
			}
			else
			{
				mT[i][p] = mX[i][p];
			}
		}
	}
}

/// <summary>
/// Effectue la passe de selection pour l'évolution différentiel
/// </summary>
void DifferentialEvolution::processSelection()
{
	for (size_t i = 0; i < mParameters.populationSize(); i++) {
		mX[i].evaluate(mParameters.objectiveFunction(), mParameters.fitnessFunction());
		mT[i].evaluate(mParameters.objectiveFunction(), mParameters.fitnessFunction());
		if (mT[i].fitnessValue() > mX[i].fitnessValue()) {
			mX[i] = mT[i];
		}
	}
}

/// <summary>
/// Effectue l'evaltion des statistiques et determine la meilleur solution
/// </summary>
void DifferentialEvolution::processStatistics()
{
	mStatistics.reset();
	for (size_t i = 0; i < mParameters.populationSize(); i++) {
		mStatistics.add(mX[i]);
	}

	mStatistics.bestSolution();
}


