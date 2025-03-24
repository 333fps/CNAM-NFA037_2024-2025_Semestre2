/*
 * 	Stack / LIFO
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

typedef struct Stack Stack;
struct Stack
{
	Node* top;
};

void Push( Stack* stack, int value );
int Pop( Stack* stack );
void Free( Stack* stack );

int main( void )
{
	Stack stack;
	Node* cursor = NULL;

	int i;
	for ( i = 0; i < NUM_NODE; ++i )
	{
		Push( &stack, i );
	}

	Pop( &stack );

	cursor = stack.top;
	while ( cursor != NULL )
	{
		printf( "%d -> ", cursor->value );
		cursor = cursor->next;
	}
	printf( " NULL" );

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

int Pop( Stack* stack )
{
	if ( stack->top == NULL )
	{
		printf( "Pop failed: Stack is empty\n" );
		return -1;
	}

	Node* topNode = stack->top;
	int value = topNode->value;

	stack->top = topNode->next;

	free( topNode );

	return value;
}

void Free( Stack* stack )
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
