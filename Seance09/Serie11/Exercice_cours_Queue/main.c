/*
 * 	Queue / FIFO
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_NODE 5

typedef struct Node Node;
struct Node
{
	int value;
	Node* next;
};

typedef struct Queue Queue;
struct Queue
{
	Node* head;
	Node* tail;
};

void Enqueue( Queue* queue, int value );
int Dequeue( Queue* queue );
void Free( Queue* queue );

int main( void )
{
	Queue queue = { NULL, NULL };
	Node* cursor = NULL;

	int i;
	for ( i = 0; i < NUM_NODE; ++i )
	{
		Enqueue( &queue, i );
	}

	Dequeue( &queue );

	cursor = queue.head;
	while ( cursor != NULL )
	{
		printf( "%d -> ", cursor->value );
		cursor = cursor->next;
	}
	printf( " NULL" );

	Free( &queue );

	return EXIT_SUCCESS;
}

void Enqueue( Queue* queue, int value )
{
	Node* newNode = (Node*)malloc( sizeof( *newNode ) );
	if ( !newNode )
	{
		printf( "Memory allocation failed\n" );
		return;
	}

	newNode->value = value;
	newNode->next = NULL;

	if ( queue->tail == NULL )
	{
		queue->head = newNode;
		queue->tail = newNode;
	}
	else
	{
		queue->tail->next = newNode;
		queue->tail = newNode;
	}
}

int Dequeue( Queue* queue )
{
	if ( queue->head == NULL )
	{
		printf( "Dequeue failed: Queue is empty\n" );
		return -1;
	}

	Node* frontNode = queue->head;
	int value = frontNode->value;

	queue->head = frontNode->next;

	if ( queue->head == NULL )
	{
		queue->tail = NULL;
	}

	free( frontNode );

	return value;
}

void Free( Queue* queue )
{
	Node* current = queue->head;
	Node* next;

	while ( current != NULL )
	{
		next = current->next;
		free( current );
		current = next;
	}

	queue->head = NULL;
	queue->tail = NULL;
}
