#include "DynamicArray.h"
#include "Project.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include "Tests.h"

int main()
{	
	//Tests test{};
	//test.runTests();

	Repository repository{};

	EHF ehf1{ "Isabelle Gullden", "SWE", "CSM Bucuresti", 80 };
	EHF ehf2{ "Cristina Neagu", "ROU", "Buducnost", 63 };
	EHF ehf3{ "Allison Pineau", "RUS", "HGM Baiamare", 82 };
	EHF ehf4{ "Ilina Ekaterina", "FRA", "Rostov-Don", 82 };

	repository.addEhf(ehf1);
	repository.addEhf(ehf2);
	repository.addEhf(ehf3);
	repository.addEhf(ehf4);

	Controller controller{ repository };
	UI ui{ controller };

	ui.startApp();

	return 0;
}