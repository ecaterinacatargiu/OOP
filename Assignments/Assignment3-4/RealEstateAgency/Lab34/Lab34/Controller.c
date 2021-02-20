#include "Controller.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

Controller * create_controller(OfferRepo * repo, OperationsStack* undoS, OperationsStack* redoS)
{
	Controller * ctrl = (Controller*)malloc(sizeof(Controller));
	ctrl->repo = repo;
	ctrl->undoStack = undoS;
	ctrl->redoStack = redoS;

	return ctrl;
}

void destroy_controller(Controller * ctrl)
{
	destroy_repo(ctrl->repo);
	destroyStack(ctrl->undoStack);
	destroyStack(ctrl->redoStack);
	free(ctrl);
}

int add_offer_controller(Controller * ctrl, char * type, char * address, double surface, double price)
{
	Offer* o = create_offer(type, address, surface, price);
	int res = add_repo_offer(o, ctrl->repo);
	if (res == 1)
	{
		Operation* oper = createOperation(o, "add");
		push(ctrl->undoStack, oper);
		// once added, the operation can be destroyed (a copy of the operation was added)
		destroyOperation(oper);
	}

	destroy_offer(o);
	return res;
}

int delete_offer_controller(Controller * ctrl, char* address)
{

	Offer* o = find(ctrl->repo, address);
	Offer* offer = copy_offer(o);
	int res = delete_offer_repo(ctrl->repo, address);

	if (res == 1)
	{

		Operation* oper = createOperation(offer, "delete");
		push(ctrl->undoStack, oper);
		destroyOperation(oper);

	}
	destroy_offer(offer);
	return res;
}

int update_offer_controller(Controller * ctrl, char * type, char* address, double surface, double price)
{

	Offer* o = find(ctrl->repo, address);
	Offer* old = copy_offer(o);
	int res = update_offer_repo(ctrl->repo, type, address, surface, price);
	if (res == 1)
	{
		Operation* oper = createOperation(old, "update");
		push(ctrl->undoStack, oper);
		destroyOperation(oper);
	}
	destroy_offer(old);
	return res;

}

int undo(Controller * c)
{
	if (isEmpty(c->undoStack))
	{
		return 0;
	}

	Operation* operation = pop(c->undoStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Offer* o = getOfferOperation(operation);
		char address[50];
		strcpy(address, get_address(o));

		Operation* oper = createOperation(find(c->repo, address), "add");
		push(c->redoStack, oper);
		destroyOperation(oper);

		delete_offer_repo(c->repo, address);
	}
	else if (strcmp(getOperationType(operation), "delete") == 0)
	{
		Offer* o = getOfferOperation(operation);
		Offer* offer = copy_offer(o);

		char address[50], type[50];
		double surface, price;

		strcpy(type, get_type(o));
		strcpy(address, get_address(o));
		surface = get_surface(o);
		price = get_price(o);

		Operation* oper = createOperation(offer, "delete");
		push(c->redoStack, oper);
		destroyOperation(oper);

		Offer* o1 = create_offer(type, address, surface, price);

		add_repo_offer(o1, c->repo);

		destroy_offer(offer);
		destroy_offer(o1);

	}
	else if (strcmp(getOperationType(operation), "update") == 0) {
		Offer* o = getOfferOperation(operation);
		char address[50], type[50];
		double surface, price;

		strcpy(type, get_type(o));
		strcpy(address, get_address(o));
		surface = get_surface(o);
		price = get_price(o);

		Operation* oper = createOperation(find(c->repo, address), "update");
		push(c->redoStack, oper);
		destroyOperation(oper);

		update_offer_repo(c->repo, type, address, surface, price);
	}

	destroyOperation(operation);

	return 1;
}

int redo(Controller * c) {
	if (isEmpty(c->redoStack))
	{
		return 0;
	}

	Operation* operation = pop(c->redoStack);

	if (strcmp(getOperationType(operation), "add") == 0)
	{
		Offer* o = getOfferOperation(operation);
		Operation* oper = createOperation(o, "add");
		push(c->undoStack, oper);
		destroyOperation(oper);
		add_repo_offer(o, c->repo);
	}
	else if (strcmp(getOperationType(operation), "delete") == 0)
	{
		Offer* o = getOfferOperation(operation);
		Operation* oper = createOperation(o, "delete");
		push(c->undoStack, oper);
		destroyOperation(oper);
		delete_offer_repo(c->repo, get_address(o));
	}
	else if (strcmp(getOperationType(operation), "update") == 0) {
		Offer* o = getOfferOperation(operation);
		char address[50];
		strcpy(address, get_address(o));
		Operation* oper = createOperation(find(c->repo, address), "update");
		push(c->undoStack, oper);
		destroyOperation(oper);
		update_offer_repo(c->repo, get_type(o), get_address(o), get_surface(o), get_price(o));

	}

	destroyOperation(operation);

	return 1;
}

OfferRepo * getRepo(Controller * ctrl)
{

	return ctrl->repo;
}

OfferRepo * filter_by_address(Controller * ctrl, char address[])
{

	OfferRepo* repo = create_repo_offer();
	if (strcmp(address, "null") == 0)
	{
		int aux = get_length_repo(ctrl->repo) + 1;
		for (int i = 0; i < get_length_repo(ctrl->repo); i++)
		{
			Offer* o = get_offer_on_pos(ctrl->repo, i); //"o" is the object found on the given position
			Offer* new = create_offer(o->type, o->address, o->surface, o->price); //create the offer and add it to the new repository
			add_repo_offer(new, repo);
		}
		//after the new repo is created, it will be sorted ascending by their price
		sort_by_price(repo);
	}
	else
	{
		for (int i = 0; i < get_length_repo(ctrl->repo); i++)
		{
			Offer* o = get_offer_on_pos(ctrl->repo, i);
			if (strstr(get_address(o), address) != NULL)
			{
				Offer* new = create_offer(o->type, o->address, o->surface, o->price);
				add_repo_offer(new, repo);
			}
		}
		sort_by_price(repo);
	}
	return repo;
}

OfferRepo * filter_by_type(Controller * ctrl, char type[])
{
	OfferRepo* repo = create_repo_offer();
	for (int i = 0; i < get_length_repo(ctrl->repo); i++)
	{
		Offer* o = get_offer_on_pos(ctrl->repo, i);
		if (strstr(get_type(o), type) != NULL)
		{
			Offer* new = create_offer(o->type, o->address, o->surface, o->price);
			add_repo_offer(new, repo);
		}
	}
	sort_by_address(repo);

	return repo;
}

OfferRepo * filter_by_surface(Controller * ctrl, char type[], int surface)
{
	OfferRepo* repo = create_repo_offer();
	for (int i = 0; i < get_length_repo(ctrl->repo); i++)
	{
		Offer* o = get_offer_on_pos(ctrl->repo, i);
		if (strstr(get_type(o), type) != NULL && get_surface(o) > surface)
		{
			Offer* new = create_offer(o->type, o->address, o->surface, o->price);
			add_repo_offer(new, repo);
		}
	}

	return repo;
}

OfferRepo * filter_by_price(Controller * ctrl, char type[], int price)
{
	OfferRepo* repo = create_repo_offer();
	for (int i = 0; i < get_length_repo(ctrl->repo); i++)
	{
		Offer* o = get_offer_on_pos(ctrl->repo, i);
		if (strstr(get_type(o), type) != NULL && get_price(o) < price)
		{
			Offer* new = create_offer(o->type, o->address, o->surface, o->price);
			add_repo_offer(new, repo);
		}
	}
	sort_by_price(repo);

	return repo;
}


