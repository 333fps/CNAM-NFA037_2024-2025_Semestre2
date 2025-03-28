/*
 * 	Stack / LIFO
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM_NODE 10

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

typedef struct Stack Stack;
struct Stack
{
	Node* top;
};

void Push( Stack* stack, int value );
enum Result Pop( Stack* stack, int* out );
void PrintStack( const Stack* stack );
void PrintNode( const Node* node );
void Free( Stack* stack );

int main( void )
{
	Stack stack = { NULL };

	int i;
	for ( i = 0; i < NUM_NODE; ++i )
	{
		Push( &stack, i );
	}

	{
		int value;
		enum Result result = FAILURE;
		result = Pop( &stack, &value );
		if ( result == FAILURE )
		{
			printf( "Failed to pop element\n" );
		}
		else
		{
			printf( "Successfully popped value: %d\n", value );
		}
	}

	PrintStack( &stack );

	Free( &stack );

	return EXIT_SUCCESS;
}

void Push( Stack* stack, int value )
{
	Node* newNode = (Node*)malloc( sizeof( *newNode ) );
	if ( !newNode )
	{
		printf( "Memory allocation failed\n" );
		return;
	}

	newNode->value = value;
	newNode->next = stack->top;
	stack->top = newNode;
}

enum Result Pop( Stack* stack, int* out )
{
	Node* topNode = stack->top;

	if ( topNode == NULL )
	{
		printf( "Pop failed: Stack is empty\n" );
		return FAILURE;
	}

	*out = topNode->value;

	stack->top = topNode->next;

	free( topNode );
	topNode = NULL;

	return SUCCESS;
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

void PrintStack( const Stack* stack )
{
	if ( stack == NULL )
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
			current = stack->top;
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

		PrintStack( stack );
	}
}

void Free( Stack* stack )
{
	if ( stack == NULL )
	{
		return;
	}
	{
		Node* current = stack->top;
		Node* next;

		while ( current != NULL )
		{
			next = current->next;
			free( current );
			current = next;
		}

		stack->top = NULL;
	}
}
