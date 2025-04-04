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

int Count( const Queue* queue );
void Enqueue( Queue* queue, int value );
enum Result Dequeue( Queue* queue, int* out );
void PrintNode( const Node* node );
void PrintQueue( const Queue* queue );
void Free( Queue* queue );

int main( void )
{
	Queue queue = { NULL, NULL };

	int i;
	for ( i = 0; i < NUM_NODE; ++i )
	{
		int j;
		printf( "Enter an integer: " );
		if ( scanf( "%d", &j ) != 1 )
		{
			printf( "Input error.\n" );
			return EXIT_FAILURE;
		}
		Enqueue( &queue, j );
	}

	{
		int value;
		enum Result result = FAILURE;
		result = Dequeue( &queue, &value );
		if ( result == FAILURE )
		{
			printf( "Failed to dequeue element\n" );
		}
		else
		{
			printf( "Successfully dequeued value: %d\n", value );
		}
	}

	printf( "The queue contains %d elements\n", Count( &queue ) );

	PrintQueue( &queue );

	Free( &queue );

	return EXIT_SUCCESS;
}

int Count( const Queue* queue )
{
	static int first = 1;
	static Node* current = NULL;

	if ( queue == NULL )
	{
		return 0;
	}

	if ( first )
	{
		first = 0;
		current = queue->head;
	}
	else
	{
		current = current->next;
	}

	if ( current == NULL )
	{
		first = 1;
		return 0;
	}
	else
	{
		return ( Count( queue ) + 1 );
	}
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

enum Result Dequeue( Queue* queue, int* out )
{
	if ( queue == NULL || out == NULL )
	{
		return FAILURE;
	}
	{
		Node* cursor = queue->head;

		if ( cursor == NULL )
		{
			printf( "Dequeue failed: Queue is empty\n" );
			return FAILURE;
		}

		*out = cursor->value;

		queue->head = cursor->next;

		if ( queue->head == NULL )
		{
			queue->tail = NULL;
		}

		free( cursor );
		cursor = NULL;

		return SUCCESS;
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
	if ( queue == NULL )
	{
		return;
	}

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
}
