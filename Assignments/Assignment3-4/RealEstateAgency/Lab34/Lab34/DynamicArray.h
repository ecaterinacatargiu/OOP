#pragma once
#include "Offer.h"
#define CAPACITY 10

typedef Offer* TElement;

typedef struct
{
	TElement* elems;
	int length;
	int capacity;
}DynamicArray;

DynamicArray* create_da(int capacity);
void destroy_da(DynamicArray* arr);
void add_in_da(DynamicArray* arr, TElement t);
void delete_from_da(DynamicArray* arr, int pos);
int get_length_da(DynamicArray* arr);
int resize_da(DynamicArray* arr);
TElement get(DynamicArray* arr, int pos);

//void tests_da();#pragma once
