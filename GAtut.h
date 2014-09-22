/*Gordon Stangler
Header for simple genetic algorithm.
Contains class definitions for Individuals, Population, Fitness*/

class Individual
{
private:
	int fitness = 0;
	static int defaultGeneLength = 64;
	byte genes[] = new byte genes[defaultGeneLength];

public:
	void generate();

	/*Use the below functions to create your own individuals*/
	void setLength(int length);
	byte getGene(int index);
	void setGene(int, int);

	/*Methods*/
	int size();
	int getFitness();
};

class Population
{
private:
	individual[] Individuals;
public:
	Population(int, bool);
	Individual getIndividual(int);
	Individual getFitnest();
	int size();
};

class Algorithm
{
private:
	static double uniformRate = 0.15;
	static double mutationRate = 0.05;
	static int tournament = 5;
	static bool elite = true;
	static Individual crossover(Individual, Individual);
	static void mutate(Individual);
	static Individual tournamentSelect(Population);
public:
	static Population evolvePopulation(Population pop);

}
class Fitness
{
private:
	static byte solution[] = new byte[64];
public:
	static void setSolution(byte newSolution[]);
	static int getFitness(Individual individual);
	static int getMaxFitness();
};
