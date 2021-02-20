#pragma once
#include "Offer.h"
#include "DynamicArray.h"

typedef struct
{
	DynamicArray* offers;

}OfferRepo;

/*
	Creates a new repository(array). Firstly it allocates space in memory and then the length(of the created array) is set to 0
*/
OfferRepo * create_repo_offer();

/*
	Destroys the repository by freeing the memory occupied by it
*/
void destroy_repo(OfferRepo * o);

/*
	INPUT: The offer that is going to be added to the array and a pointer to OfferRepo
	OUTPUT: 0 if the address of the offer already exists and 1 if the proccess of adding the offer has succeeded
*/
int add_repo_offer(Offer * o, OfferRepo * offerRepo);

/*
	INPUT: A pointer to OfferRepo and the address of the object that is going to be removed
	OUTPUT: 1 if the given address was found and the offer was removed and 0 otherwise
*/
int delete_offer_repo(OfferRepo * offerRepo, char* address);

/*
	INPUT: A pointer to OfferRepo, the new type, surface, price and the position of the offer that will be updated
	All the attributes of the offer found on position "pos" will be replaced with the new given attributes
*/
int update_offer_repo(OfferRepo* repo, char* type, char * address, double surface, double price);

/*
	INPUT: A pointer to the OfferRepo and the address(string)
	OUTPUT: The object with the given address if this was found and NULL otherwise
*/
Offer* find(OfferRepo* repo, char* address);

/*
	INPUT: A pointer to the OfferRepo and the address(string)
	OUTPUT: The position where given address was found and -1 otherwise
*/
int find_position(OfferRepo *repo, char* address);

/*
	Getter for the length of the array
*/
int get_length_repo(OfferRepo * o);

/*
	INPUT: A pointer to OfferRepo and a position
	OUTPUT: The offer found at the given position
*/
Offer* get_offer_on_pos(OfferRepo* repo, int pos);

/*
	Sorts the array ascendingly by the address
*/
void sort_by_address(OfferRepo* repo);

/*
	Sorts the array ascendingly by the price
*/
void sort_by_price(OfferRepo* repo);

//void test_offer_r#pragma once
