#include "UI.h"
//#include "Repository.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

UI * createUI(Controller * c)
{
	//Creates the UI by allocating memory on the heap

	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

void destroyUI(UI * ui)
{
	//Frees the memory occupied by the UI

	destroy_controller(ui->ctrl);
	free(ui);
}

void printMenu()
{
	//Prints the commands that will guide the user

	printf("\n");
	printf("1 - List all offers.\n");
	printf("2 - Add an offer.\n");
	printf("3 - Remove an offer.\n");
	printf("4 - Update an offer.\n");
	printf("5 - List offers with a given address, sorted ascending by their price.\n");
	printf("6 - List offers with a given type, sorted ascending by their address.\n");
	printf("7 - List offers with a given type, having the surface greater than a given value.\n");
	printf("8 - List all offers having a given type and a price less than a given value, sorted ascending by price.\n");
	printf("9 - Undo.\n");
	printf("10 - Redo.\n");
	printf("0 - Exit.\n");
	printf("\n");
}

int validCommand(int command)
{
	//Validator for the inputed commands

	if (command >= 0 && command <= 10)
		return 1;
	return 0;
}

int readIntegerNumber(const char* message)
{
	// Reads data from s and stores them as integer, if possible; returns 1 if successful

	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	fgets(str, maxStrSize, stdin);
	// the newline is also read so we must eliminate it from the string
	int size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

int addOfferUI(UI* ui)
{
	// read the offer's data and call the adding fuction

	char type[50], address[50];
	double surface = 0;
	double price = 0;

	printf("Input the type: ");
	scanf("%49s", type);
	printf("Input the address: ");
	scanf("%49s", address);
	printf("Input the surface: ");
	scanf("%lf", &surface);
	printf("Input the price: ");
	scanf("%lf", &price);
	return add_offer_controller(ui->ctrl, type, address, surface, price);
}

int deleteOfferUI(UI* ui)
{
	char address[50];
	printf("Input the address of the offer that you want to delete: ");
	scanf("%49s", address);
	return delete_offer_controller(ui->ctrl, address);
}

int updateOfferUI(UI * ui)
{
	char address[50];
	printf("Give the address of the offer that you want to update: \n");
	scanf("%s", address);

	char type[50];
	double surface = 0;
	double price = 0;

	printf("Input the new type: ");
	scanf("%49s", type);
	printf("Input the new surface: ");
	scanf("%lf", &surface);
	printf("Input the new price: ");
	scanf("%lf", &price);
	return update_offer_controller(ui->ctrl, type, address, surface, price);
}

void listAllOffers(UI* ui)
{
	//Lists all existing offers

	OfferRepo* repo = getRepo(ui->ctrl);
	int length = get_length_repo(repo);

	if (length == 0)
	{
		char* str = "There are no stored offers.\n";
		printf("%s \n", str);
	}

	for (int i = 0; i < get_length_repo(repo); i++)
	{
		char str[200];
		toString(get_offer_on_pos(repo, i), str);
		printf("%s\n", str);
	}
}

void listOffersByAddress(UI* ui)
{
	//Lists all offers with the given address

	char address[50];
	printf("Input the address; enter 'null' for no address: ");
	scanf("%s", address);

	OfferRepo* res = filter_by_address(ui->ctrl, address);
	int i, length = get_length_repo(res);
	if (length == 0)
	{
		printf("There are no offers having the given address.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(get_offer_on_pos(res, i), str);
			printf("%s\n", str);
		}
	}

	destroy_repo(res);
}

void listOffersByType(UI* ui)
{
	char type[50];
	printf("Input the type: ");
	scanf("%7s", type);

	OfferRepo* res = filter_by_type(ui->ctrl, type);
	int i, length = get_length_repo(res);
	if (length == 0)
	{
		printf("There are no offers having the given type.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(get_offer_on_pos(res, i), str);
			printf("%s\n", str);
		}
	}

	destroy_repo(res);
}

void listOffersBySurface(UI* ui)
{
	char type[50];
	double surface;
	printf("Input the type: ");
	scanf("%7s", type);
	printf("Input the surface: ");
	scanf("%lf", &surface);

	OfferRepo* res = filter_by_surface(ui->ctrl, type, surface);
	int i, length = get_length_repo(res);
	if (length == 0)
	{
		printf("There are no offers having the given type.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(get_offer_on_pos(res, i), str);
			printf("%s\n", str);
		}
	}

	destroy_repo(res);
}

void listOffersByPrice(UI* ui)
{
	char type[50];
	double price;
	printf("Input the type: ");
	scanf("%7s", type);
	printf("Input the price: ");
	scanf("%lf", &price);

	OfferRepo* res = filter_by_price(ui->ctrl, type, price);

	int i, length = get_length_repo(res);
	if (length == 0)
	{
		printf("There are no offers having the given type.\n");
	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			char str[200];
			toString(get_offer_on_pos(res, i), str);
			printf("%s\n", str);
		}
	}

	destroy_repo(res);
}

void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			listAllOffers(ui);
			break;
		}
		case 2:
		{
			int res = addOfferUI(ui);
			if (res != 1)
				printf("Error! There is already an offer with this address!\n");
			break;
		}
		case 3:
		{
			int i = deleteOfferUI(ui);
			if (i == 0)
				printf("Address not found! \n");
			break;
		}
		case 4:
		{

			int res = updateOfferUI(ui);
			if (res != 1)
				printf("Address not found!!!!!\n");
			//updateOfferUI(ui);
			break;
		}
		case 5:
		{
			listOffersByAddress(ui);
			break;
		}
		case 6:
		{
			listOffersByType(ui);
			break;
		}
		case 7:
		{
			listOffersBySurface(ui);
			break;
		}
		case 8:
		{
			listOffersByPrice(ui);
			break;
		}
		case 9:
		{
			int res = undo(ui->ctrl);
			if (res == 1)
				printf("Undo was successful.\n");
			else
				printf("No more undos to be made.\n");
			break;
		}
		case 10:
		{

			int res = redo(ui->ctrl);
			if (res == 1)
				printf("Redo was successful.\n");
			else
				printf("No more redos to be made.\n");
			break;
		}
		}
	}
}