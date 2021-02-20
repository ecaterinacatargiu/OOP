#include "OperationsStack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Operation* createOperation(Offer* o, char* operationType)
{
	Operation* oper = (Operation*)malloc(sizeof(Operation));
	oper->offer = copy_offer(o);

	if (operationType != NULL)
	{
		oper->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
		strcpy(oper->operationType, operationType);
	}
	else
		oper->operationType = NULL;

	return oper;
}

void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;

	destroy_offer(o->offer);
	free(o->operationType);
	free(o);
}

Operation* copyOperation(Operation * o)
{
	if (o == NULL)
		return NULL;

	Operation* newOp = createOperation(o->offer, o->operationType);
	return newOp;
}

char* getOperationType(Operation* o)
{
	return o->operationType;
}

Offer* getOfferOperation(Operation* o)
{
	return o->offer;
}


OperationsStack* createStack()
{
	OperationsStack* s = (OperationsStack*)malloc(sizeof(OperationsStack));
	s->length = 0;

	return s;
}

void destroyStack(OperationsStack* s)
{
	if (s == NULL)
		return;

	for (int i = 0; i < s->length; i++)
		destroyOperation(s->operations[i]);


	free(s);
}

void push(OperationsStack* s, Operation* o)
{
	if (isFull(s))
		return;

	s->operations[s->length++] = copyOperation(o);
}

Operation* pop(OperationsStack* s)
{
	if (isEmpty(s))
		return NULL;
	s->length--;
	return s->operations[s->length];
}

int isEmpty(OperationsStack* s)
{
	return (s->length == 0);
}

int isFull(OperationsStack* s)
{
	return s->length == 100;
}


// Tests
/*
void testsStack()
{
	OperationsStack* s = createStack();

	Offer* offer1 = create_offer("House", "Zagreb/25", 22.000, 36.000);
	Offer* offer2 = create_offer("House", "Sun", 50.000, 72.000);
	Operation* o1 = createOperation(offer1, "add");
	Operation* o2 = createOperation(offer2, "add");
	Operation* o3 = createOperation(offer1, "remove");


	destroy_offer(offer1);
	destroy_offer(offer2);

	push(s, o1);
	push(s, o2);
	push(s, o3);

	// the operations may be destroyed, as the stack contains copies of these operations
	destroyOperation(o1);
	destroyOperation(o2);
	destroyOperation(o3);

	assert(isFull(s) == 0);
	assert(isEmpty(s) == 0);
	Operation* o = pop(s);
	assert(strcmp(o->operationType, "remove") == 0);
	// after each pop, the operations must be destroyed
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	o = pop(s);
	assert(strcmp(o->operationType, "add") == 0);
	destroyOperation(o);

	assert(isEmpty(s) == 1);

	// destroy the stack
	destroyStack(s);
}
*/