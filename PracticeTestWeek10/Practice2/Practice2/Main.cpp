#include "Controller.h"
#include "UI.h"

int main() 
{
	Controller ctrl{};
	UI ui{ ctrl };

	ui.start();

	return 0;
}