#pragma once

typedef struct
{
	//Each Offer has type(can be house, apartment or penthouse), 
	//an address, a surface and a price.
	char * type;
	char * address;
	double surface;
	double price;

}Offer;

Offer * create_offer(char* type, char* address, double surface, double price);
void destroy_offer(Offer* offer);

char* get_address(Offer * offer);
char* get_type(Offer* offer);
double get_surface(Offer* offer);
double get_price(Offer* offer);

void set_type(Offer* offer, char* type);
void set_address(Offer* offer, char* address);
void set_surface(Offer* offer, double surface);
void set_price(Offer* offer, double price);
Offer* copy_offer(Offer* o);

void toString(Offer* offer, char str[]);


#pragma once
