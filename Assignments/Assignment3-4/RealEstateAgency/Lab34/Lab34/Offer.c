#include "Offer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Offer * create_offer(char * type, char * address, double surface, double price)
{
	//INPUT: Two strings(type, address) and two doubles(surface and price)
	//OUTPUT: A new Offer object with the given type, address, surface and price

	Offer * offer = (Offer*)malloc(sizeof(Offer)); //alocates memory for the offer that will be creted
	offer->type = (char*)malloc(sizeof(char)*(strlen(type) + 1)); //alocates memory for the given type
	strcpy(offer->type, type);

	offer->address = (char*)malloc(sizeof(char)*(strlen(address) + 1)); //alocates memory for the given address
	strcpy(offer->address, address);

	offer->surface = surface;

	offer->price = price;
	return offer;
}

void destroy_offer(Offer * offer)
{
	//destroys the given offer by freeing the memory occupied by it

	// free the memory which was allocated for the component fields
	free(offer->type);
	free(offer->address);
	// free the memory which was allocated for the offer structure
	free(offer);
}

char * get_address(Offer * offer)
{
	//Getter for the address of the oject Offer
	return offer->address;
}

char * get_type(Offer * offer)
{
	//Getter for the type of the oject Offer
	return offer->type;
}

double get_surface(Offer * offer)
{
	//Getter for the surface of the oject Offer
	return offer->surface;
}

double get_price(Offer * offer)
{
	//Getter for the price of the oject Offer
	return offer->price;
}

void set_type(Offer * offer, char* type)
{
	//Setter for the type of the oject Offer
	strcpy(offer->type, type);
}

void set_address(Offer * offer, char * address)
{
	//Setter for the address of the oject Offer
	strcpy(offer->address, address);
}

void set_surface(Offer * offer, double surface)
{
	//Setter for the surface of the oject Offer
	offer->surface = surface;
}

void set_price(Offer * offer, double price)
{
	//Setter for the price of the oject Offer
	offer->price = price;
}

Offer * copy_offer(Offer * o)
{
	if (o == NULL)
		return NULL;
	Offer* newOffer = create_offer(get_type(o), get_address(o), get_surface(o), get_price(o));
	return newOffer;
}

void toString(Offer * offer, char str[])
{
	//Transforms the given object into a string and then prints it
	sprintf(str, "%s, %s, %.2lf, %.2lf\n", offer->type, offer->address, offer->surface, offer->price);
}
