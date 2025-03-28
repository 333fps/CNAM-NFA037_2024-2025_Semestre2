#include <stdio.h>
#include <stdlib.h>

#define NUM_NODE 5

enum Result
{
	SUCCESS = 0,
	FAILURE
};

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
void PrintNode( const Node* node );
void PrintQueue( const Queue* queue );
void Free( Queue* queue );

int main( void )
{
	Queue queue = { NULL, NULL };

	int i;
	for ( i = 0; i < NUM_NODE; ++i )
	{
		int integer;
		printf( "Enter an integer: " );
		if ( scanf( "%d", &integer ) != 1 )
		{
			printf( "Input error.\n" );
			return EXIT_FAILURE;
		}
		Enqueue( &queue, integer );
	}

	PrintQueue( &queue );

	Free( &queue );

	return EXIT_SUCCESS;
}

void Enqueue( Queue* queue, int value )
{
	if ( queue == NULL )
	{
		return;
	}

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
}

void PrintNode( const Node* node )
{
	if ( node == NULL )
	{
		printf( "NULL\n" );
		return;
	}
	else
	{
		printf( "%d", node->value );
	}
}

void PrintQueue( const Queue* queue )
{
	if ( queue == NULL )
	{
		printf( "NULL\n" );
		return;
	}
	{
		static int first = 1;
		static Node* current = NULL;

		if ( first )
		{
			first = 0;
			current = queue->head;
		}

		if ( current == NULL )
		{
			printf( "NULL\n" );
			first = 1;
			return;
		}

		PrintNode( current );
		printf( " -> " );

		current = current->next;

		PrintQueue( queue );
	}
}

void Free( Queue* queue )
{
	static int first = 1;
	static Node* current = NULL;
	static Node* next = NULL;

	if ( queue == NULL )
	{
		return;
	}

	if ( first )
	{
		first = 0;
		current = queue->head;

		if ( current == NULL )
		{
			first = 1;
			return;
		}
	}

	next = current->next;

	free( current );

	if ( next == NULL )
	{
		queue->head = NULL;
		queue->tail = NULL;

		first = 1;
		return;
	}

	current = next;

	Free( queue );
}
