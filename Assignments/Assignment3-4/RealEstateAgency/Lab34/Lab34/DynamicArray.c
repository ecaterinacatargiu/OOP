#pragma once
#include "DynamicArray.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray * create_da(int capacity)
{
	DynamicArray* da = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (da == NULL)  //if the space was not allocated, NULL will be returned
		return NULL;
	da->capacity = capacity;
	da->length = 0;

	da->elems = (TElement*)malloc(capacity * sizeof(TElement)); //allocate space for the elements of the array
	if (da->elems == NULL)
		return NULL;

	return da;
}

void destroy_da(DynamicArray * arr)
{
	if (arr == NULL)
		return;

	for (int i = 0; i < arr->length; i++)
		destroy_offer(arr->elems[i]);

	free(arr->elems);
	arr->elems = NULL;

	free(arr);
	arr = NULL;
}

int resize_da(DynamicArray * arr)
{
	if (arr == NULL)
		return;

	arr->capacity *= 2;

	TElement* aux = (TElement*)malloc(arr->capacity * sizeof(TElement));
	if (aux == NULL)
		return -1;
	for (int i = 0; i < arr->length; i++)
		aux[i] = arr->elems[i];
	free(arr->elems);
	arr->elems = aux;

	return 0;
}

void add_in_da(DynamicArray * arr, TElement t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (arr->length == arr->capacity)
		resize_da(arr);
	arr->elems[arr->length++] = t;
}

void delete_from_da(DynamicArray * arr, int pos)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	if (pos < 0 || pos >= arr->length)
		return;

	for (int i = pos; i < arr->length - 1; i++)
		arr->elems[i] = arr->elems[i + 1];

	arr->length--;
}

int get_length_da(DynamicArray * arr)
{
	if (arr == NULL)
		return -1;

	return arr->length;
}

TElement get(DynamicArray * arr, int pos)
{
	return arr->elems[pos];
}
/*
void tests_da()
{
	DynamicArray* da = create_da(2);
	if (da == NULL)
		assert(0);

	assert(da->capacity == 2);
	assert(da->length == 0);

	Offer* o1 = create_offer("House", "Zagreb/25", 22.000, 36.000);
	add_in_da(da, o1);
	assert(da->length == 1);

	Offer* o2 = create_offer("House", "Sun", 50.000, 72.000);
	add_in_da(da, o2);
	assert(da->length == 2);

	// capacity must double
	Offer* o3 = create_offer("Penthouse", "Lemon", 12.000, 32.000);
	add_in_da(da, o3);
	assert(da->length == 3);
	assert(da->capacity == 4);

	// delete offer on position 0
	Offer* o = get(da, 0);
	delete_from_da(da, 0);
	destroy_offer(o);

	o = get(da, 0);
	assert(strcmp(get_address(o), "Sun") == 0);
	assert(da->length == 2);

	// destroy the dynamic array
	destroy_da(da);
}
*/