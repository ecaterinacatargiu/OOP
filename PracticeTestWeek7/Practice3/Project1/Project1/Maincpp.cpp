#include "DynamicArray.h"
#include "Gene.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"

int main()
{
	Repository repository{};

	Gene g1{ "Gena1", "Organism1", "Sequence1" };
	Gene g2{ "Gena2", "Aldoileaorganism", "Sequence1" };
	Gene g3{ "Gena3", "Celdealtrieleaorganism", "Sequence1" };
	Gene g4{ "Gena4", "Bine", "Sequence1" };
	Gene g5{ "Gena5", "Organism2", "Sequence1" };

	repository.addGene(g1);
	repository.addGene(g2);
	repository.addGene(g3);
	repository.addGene(g4);
	repository.addGene(g5);

	Controller controller{ repository };
	UI ui{ controller };

	ui.Start();

	return 0;
}