#pragma once
#include "Repository.h"
#include "OperationsStack.h"

typedef struct
{
	OfferRepo * repo;
	OperationsStack* undoStack;
	OperationsStack* redoStack;

}Controller;

/*
	Creates a controller by allocating memory on the heap
*/
Controller * create_controller(OfferRepo* repo, OperationsStack* undoS, OperationsStack* redoS);

/*
	Deallocates the memmory of the repo(array) and freeing the space occupied by the controller
*/
void destroy_controller(Controller* ctrl);

/*
	INPUT: A pointer to Controller, the type, address, surface and  price of the offer that will be added
	If res is 0 it means that the procces of addition didn't take place so the offer created with the given attributes will be destroyed
*/
int add_offer_controller(Controller * ctrl, char* type, char* address, double surface, double price);

/*
	INPUT: A pointer to Controller and the address of the object that will be deleted
	OUTPUT: The value of res (1 if the deleting procces took place and 0 otherwise)
*/
int delete_offer_controller(Controller * ctrl, char* address);

/*
	INPUT: A pointer to Controller, the type, address, surface and  price of the offer that will be updated
	If res is 0 it means that the procces of updating didn't take place so the offer created with the given attributes will be destroyed
*/
int update_offer_controller(Controller * ctrl, char* type, char* address, double surface, double price);

/*
	INPUT: A pointer to Controller and the adrress that is going to be searched in the list of offers;
			the list will be sorted ascendingly by their price
	OUTPUT: in case the user typed null all offers will be considered sorted ascending by their price
			otherwise the offers that match the given string
*/
OfferRepo* filter_by_address(Controller* ctrl, char address[]);

/*
	Returns offers with a given type, sorted ascending by their address
*/
OfferRepo * filter_by_type(Controller * ctrl, char type[]);

/*
	Returns all offers having a given type and a surface greater than a given value.
*/
OfferRepo * filter_by_surface(Controller * ctrl, char type[], int surface);

/*
	Returns all offers having a given type and a price less than a given value, sorted ascending by price
*/
OfferRepo * filter_by_price(Controller * ctrl, char type[], int  price);

/*
	It will undo the add, delete and update functions
*/
int undo(Controller* ctrl);

/*
	It will redo the add, delete and update functions
*/
int redo(Controller* ctrl);

/*
	Getter for the repo
*/
OfferRepo* getRepo(Controller* ctrl);
