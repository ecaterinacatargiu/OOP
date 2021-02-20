#include "Repository.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

OfferRepo * create_repo_offer()
{
	OfferRepo * o = (OfferRepo *)malloc(sizeof(OfferRepo));
	o->offers = create_da(CAPACITY);

	return o;
}

void destroy_repo(OfferRepo * o)
{
	if (o == NULL)
		return;

	destroy_da(o->offers);

	free(o);
}

int find_position(OfferRepo * repo, char* address)
{
	if (repo == NULL)
		return -1;
	int len = get_length_da(repo->offers);
	for (int i = 0; i < get_length_da(repo->offers); i++)
	{
		Offer* o = get(repo->offers, i);
		if (strcmp(o->address, address) == 0)
			return i;
	}
	return -1;
}

Offer * find(OfferRepo * repo, char* address)
{
	if (repo == NULL)
		return NULL;

	int pos = find_position(repo, address);
	if (pos == -1)
		return NULL;
	return get(repo->offers, pos);
}

int add_repo_offer(Offer * o, OfferRepo * repo)
{
	if (repo == NULL)
		return 0;

	if (find(repo, o->address) != NULL)
		return 0;

	Offer* copy = copy_offer(o);

	add_in_da(repo->offers, copy);

	return 1;
}

int delete_offer_repo(OfferRepo * repo, char* address)
{
	if (repo == NULL)
		return 0;

	int pos = find_position(repo, address);

	if (pos == -1)
		return 0;

	Offer* o = get(repo->offers, pos);

	delete_from_da(repo->offers, pos);

	return 1;
}

int update_offer_repo(OfferRepo* repo, char* type, char * address, double surface, double price)
{
	if (repo == NULL)
		return 0;

	int pos = find_position(repo, address);
	if (pos == -1)
		return 0;

	Offer* o = get(repo->offers, pos);
	set_type(o, type);
	set_surface(o, surface);
	set_price(o, price);
	return 1;

}

int get_length_repo(OfferRepo* repo)
{
	if (repo == NULL)
		return -1;

	return get_length_da(repo->offers);
}

Offer * get_offer_on_pos(OfferRepo * repo, int pos)
{
	if (repo == NULL)
		return NULL;

	if (pos < 0 || pos >= get_length_da(repo->offers))
		return NULL;
	return get(repo->offers, pos);
}

void sort_by_price(OfferRepo * repo)
{
	Offer* aux;
	for (int i = 0; i < get_length_repo(repo) - 1; i++)
	{
		for (int j = i + 1; j < get_length_repo(repo); j++)
		{
			if (get_price(repo->offers->elems[i]) > get_price(repo->offers->elems[j]))
			{
				aux = repo->offers->elems[i];
				repo->offers->elems[i] = repo->offers->elems[j];
				repo->offers->elems[j] = aux;
			}
		}
	}
}

void sort_by_address(OfferRepo* repo)
{
	//The function sorts the array stored  in repo ascendingly by the address
	int i, j, res, len;
	char str1[50];
	char str2[50];
	Offer* aux;
	len = get_length_repo(repo);
	for (i = 0; i < get_length_repo(repo) - 1; i++)
		for (j = i + 1; j < get_length_repo(repo); j++)
		{
			Offer* o1 = get_offer_on_pos(repo, i);
			Offer* o2 = get_offer_on_pos(repo, j);
			strcpy(str1, get_address(o1));
			strcpy(str2, get_address(o2));
			res = strcmp(str1, str2);
			if (res > 0)
			{
				aux = repo->offers->elems[i];
				repo->offers->elems[i] = repo->offers->elems[j];
				repo->offers->elems[j] = aux;
			}
		}
}

//TESTS
/*
void testAdd()
{
	OfferRepo* repo = create_repo_offer();

	Offer* o1 = create_offer("House", "Dubai, 20", 13.000, 45.000);
	Offer* o2 = create_offer("Penthouse", "Malta,78", 12.000, 32.000);
	assert(add_repo_offer(o2, repo) == 1);
	assert(add_repo_offer(o1, repo) == 1);
	assert(get_length_repo(repo) == 2);

	// now try to add the same offer again -> add must return 0
	assert(add_repo_offer(o2, repo) == 0);

	// destroy the test repository
	destroy_repo(repo);
	destroy_offer(o1);
	destroy_offer(o2);
}

void testDelete()
{
	OfferRepo* repo = create_repo_offer();
	//initOfferRepoForTests(repo);
	//assert(get_length(repo) == 1);

	Offer* o = create_offer("Penthouse", "Malta,78", 12.000, 32.000);
	Offer* o1 = create_offer("House", "Dubai, 20", 13.000, 45.000);
	Offer* o2 = create_offer("House", "Zagreb/25", 22.000, 36.000);

	assert(add_repo_offer(o, repo) == 1);
	assert(add_repo_offer(o1, repo) == 1);
	assert(add_repo_offer(o2, repo) == 1);

	assert(delete_offer_repo(repo, "Malta,78") == 1);

	assert(get_length_repo(repo) == 2);
	// now try to delete an offer on an inexisting address -> delete must return 0
	assert(delete_offer_repo(repo, "Milano") == 0);

	destroy_repo(repo);
	destroy_offer(o);
	destroy_offer(o1);
	destroy_offer(o2);
}

void testUpdate()
{
	OfferRepo* repo = create_repo_offer();

	Offer* o = create_offer("Penthouse", "Malta,78", 12000, 32000);
	assert(add_repo_offer(o, repo) == 1);
	update_offer_repo(repo, "Mansion", 60000, 80000, 0);
	assert(strcmp(get_type(o), "Mansion") == 0);
	int a = get_surface(o);
	int b = get_price(o);
	assert(get_surface(o) == 12000);

	update_offer_repo(repo, "Appartment", 9000, 2000, 1);
	assert(strcmp(get_type(o), "Appartment") == 0);

	update_offer_repo(repo, "Penthouse", 24000, 62000, 2);
	assert(strcmp(get_type(o), "Penthouse") == 0);
	destroy_repo(repo);
}

void testFind()
{
	OfferRepo* repo = create_repo_offer();

	Offer* o = create_offer("Penthouse", "Malta,78", 12.000, 32.000);
	Offer* o1 = create_offer("House", "Zagreb/25", 22.000, 36.000);
	Offer* o2 = create_offer("House", "Sun", 50.000, 72.000);
	Offer* o3 = create_offer("Penthouse", "Lemon", 12.000, 32.000);
	add_repo_offer(o, repo);
	add_repo_offer(o1, repo);
	add_repo_offer(o2, repo);
	add_repo_offer(o3, repo);
	assert(find(repo, "Something") == NULL);
	assert(find(repo, "London") == NULL);
	assert(find(repo, "Sun") == repo->offers->elems[2]);
	assert(find(repo, "Malta,78") == repo->offers->elems[0]);

	destroy_repo(repo);
	destroy_offer(o);
	destroy_offer(o1);
	destroy_offer(o2);
	destroy_offer(o3);
}

void testFindPosition()
{
	OfferRepo* repo = create_repo_offer();

	Offer* o = create_offer("Penthouse", "Malta,78", 12.000, 32.000);
	Offer* o1 = create_offer("House", "Zagreb/25", 22.000, 36.000);
	Offer* o2 = create_offer("House", "Sun", 50.000, 72.000);
	Offer* o3 = create_offer("Penthouse", "Lemon", 12.000, 32.000);
	add_repo_offer(o, repo);
	add_repo_offer(o1, repo);
	add_repo_offer(o2, repo);
	add_repo_offer(o3, repo);

	assert(find_position(repo, "Sun") == 2);
	assert(find_position(repo, "Lemon") == 3);
	assert(find_position(repo, "Else") == -1);
	destroy_repo(repo);
	destroy_offer(o);
	destroy_offer(o1);
	destroy_offer(o2);
	destroy_offer(o3);
}

void sortTest()
{
	OfferRepo* repo = create_repo_offer();

	Offer* o = create_offer("Penthouse", "Malta,78", 12.000, 32.000);
	Offer* o1 = create_offer("House", "Zagreb/25", 22.000, 36.000);
	Offer* o2 = create_offer("House", "Sun", 50.000, 72.000);
	Offer* o3 = create_offer("Penthouse", "Lemon", 12.000, 32.000);
	add_repo_offer(o, repo);
	add_repo_offer(o1, repo);
	add_repo_offer(o2, repo);
	add_repo_offer(o3, repo);
	//aasert( sort(repo) = "");
	//destroy_repo(repo);
}

void test_offer_repo()
{
	testAdd();
	testDelete();
	//testUpdate();
	testFind();
	testFindPosition();
}
*/