class Individual()
{
	void generateIndividual()
	{
		for (int i = 0; i < defaultGeneLength; i++)
		{
			gene[i] = rand() % 2;
		}
	}
	void setLength(int length)
	{
		defaultGeneLength = length;
	}
	byte getGene(int index)
	{
		if (index < defaultGeneLength)
			return gene[index];
		else cout << "Not a valid index\n";
	}
	void setGene(int index, int set)
	{
		gene[index] = set;
	}

	/*Methods*/
	int size()
	{
		return this.length;
	}
	int getFitness()
	{
		if (0 == fitness)
			fitness = FitnessCalc.getFitness(this);
		return fitness;
	}
};

class Population()
{
	Population(int popsize, bool initialize)
	{
		individuals = new Individual[popsize];
		if (initialize)
		{
			for (int i = 0; i < popsize; i++)
			{
				Individual newindividual = new Individual();
				newIndividual.generateIndividual();
				saveIndividual(i, newIndividual);
			}
		}
	}
	Individual getIndividual(int index)
	{
		return individuals[index];
	}
	Individual getFittest()
	{
		Individual fittest = individuals[0];
		for (int i = 0; i < popsize; i++)
		{
			if (individual[i].getFitness() > fittest.getFitness())
				fittest = getIndividual(i);
		}
		return fittest;
	}
	int size()
	{
		return individuals.length;
	}
	void saveIndividual(int index, Individual indy)
	{
		individuals[index] = indy;
	}
}

class Algorithm
{
	static Population evolvePopulation(Population pop)
	{
		Population newPopulation = new Population(pop.size(), false);

		if (elitism)
		{
			newPopulation.saveIndividual(0, pop.getFittest());
		}

		//Crossover individual
		int elitismOffset;
		if (elitism)
			elitismOFfset = 1;
		else
			elitismOffset = 0;

		for (int i = elitismOffset; i < pop.size(); i++)
		{
			Individual indiv1 = tournamentSelect(pop);
			Individual indiv2 = tournamentSelect(pop);
			Individual newIndiv = crossover(indiv1, indiv2);
			newPopulation.saveIndividual(i, newIndiv);
		}

		//Mutate
		for (int i = elitismOffset; i < newPopulation.size(); i++)
		{
			mutate(newPopulation.getIndividual(i));
		}

		return newPopulation;
	}

	static Individual crossover(Individual indiv1, Individual indiv2)
	{
		Individual newSol = new Individual();
		for (int i = 0; i < indiv1.size(); i++)
		{
			if (((rand() % 100) / 100) <= uniformRate)
			{
				newSol.setGene(i, indiv1.getGene(i));
			}
			else
			{
				newSol.setGene(i, indiv2.getGene(i));
			}
		}
		return newSol;
	}

	static void mutate(Individual indiv1)
	{
		for (int i = 0; i < indiv1.size(); i++)
		{
			if (((rand() % 100) / 100) <= mutationRate)
			{
				byte gene = byte rand % 2;
				indiv1.setGene(i, gene);
			}
		}
	}

	static Individual tournamentSelect(Population pop)
	{
		//create tournament population
		Population tournament = new Population(tournament, false);
		int randID;
		//place a random individual
		for (int i = 0; i < tournament; i++)
		{
			randomID = (int)rand()*pop.size();
			tournament.saveIndividual(i, pop.getIndividual(randID));
		}
		Individual fittest = tournament.getfittest();
		return fittest;
	}
};

class Fitness()
{
	static void setSolution(byte newSolution[])
	{
		solution = newSolution;
	}
	static int getFitness(Individual individual)
	{
		int fitness = 0;
		for (int i = 0; i < individual.size() && i < solution.length(); i++)
		{
			if (indiviual.getGene(i) == solution[i])
			{
				fitness++;
			}
		}
		return fitness;
	}
	static int getMaxFitness()
	{
		return solution.length();
	}
};

int main(char args[])
{
	if (args[] == "")
		args = "1111000000000000000000000000000000000000000000000000000000001111";
	if (sizeof(args) > (sizeof(char) * 64))  //this conflicts with Individual.setLength()
	{
		std::cout << "Your string is too large.  Using default string.\n";
		args = "1111000000000000000000000000000000000000000000000000000000001111";
	}
	Fitness.setSolution(args);

	Population myPop = new Population(50, true);

	int generationCount = 0;
	while (myPop.getFittest().getFitness() < FitnessCalc.getMaxfitness())
	{
		generationCount++;
		std::cout << "Generation " << generationCount << "has a fitness of " << myPop.getFittest().getFitness() << "\n";
		myPop = Algorithm.evolvePopultion(myPop);
	}
	std::cout << "Success!\n";
	std::cout << "Generation: " << generationCount << "Genes: " << myPop.getFittest() << "\n";

	return 0;
}