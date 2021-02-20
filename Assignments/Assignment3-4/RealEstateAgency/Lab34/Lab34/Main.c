#include "Repository.h"
#include "UI.h"
#include <stdio.h>
#include <Windows.h>
#include <crtdbg.h>
//#define _CRT_SECURE_NO_WARNINGS

int main()
{
	//system("color f4");

	//tests_da();
	//test_offer_repo();
	//testsStack();

	OfferRepo* repo = create_repo_offer();
	OperationsStack* operationsStackUndo = createStack();
	OperationsStack* operationsStackRedo = createStack();
	Controller* ctrl = create_controller(repo, operationsStackUndo, operationsStackRedo);

	add_offer_controller(ctrl, "House", "Cluj/30", 20000, 45000);
	add_offer_controller(ctrl, "Appartment", "Budapest/45", 12000, 30000);
	add_offer_controller(ctrl, "Penthouse", "Hawaii/23", 30000, 50000);
	add_offer_controller(ctrl, "House", "London/80", 25000, 70000);
	add_offer_controller(ctrl, "Appartment", "Berlin/61", 40000, 10000);
	add_offer_controller(ctrl, "Penthouse", "Ibiza/12", 9000, 26000);
	add_offer_controller(ctrl, "House", "Moscow/26", 43000, 40000);
	add_offer_controller(ctrl, "Appartment", "Madrid/92", 36000, 56000);
	add_offer_controller(ctrl, "Penthouse", "Reykjavik/700", 50000, 20000);
	add_offer_controller(ctrl, "House", "NY/100", 48000, 150000);

	UI* ui = createUI(ctrl);

	startUI(ui);

	destroyUI(ui);

	_CrtDumpMemoryLeaks();

	system("pause");

	return 0;
}