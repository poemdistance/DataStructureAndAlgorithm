/*头文件部分*/

#ifndef __STACKBYARRAY__
#define __STACKBYARRAY__

struct stackRecord;
typedef struct stackRecord *stack;

int isEmpty(stack s);
int isFull( stack s );
stack createStack( int MaxSize );
void disposeStack( stack s );
void makeEmpty( stack s );
void push(int x, stack s);
void pop(stack s);
int topAndPop(stack s);

#endif

#include <stdio.h>
#include <stdlib.h>

#define emptyTOS  ( -1 )
#define minStackSize ( 5 )

struct stackRecord {
    int capacity;
    int topOfStack;
    int *array;
};

void makeEmpty( stack s )
{
    s->topOfStack = emptyTOS;
}

stack createStack( int MaxSize )
{
    stack s;
    if( MaxSize < minStackSize ) {
        printf("stack size is too small\n");
        exit(1);
    }

    s = malloc( sizeof(struct stackRecord) );
    if( s == NULL ) {
        printf("Malloc failed\n");
        exit(1);
    }

    s->array = malloc( sizeof(int) * MaxSize );
    if( s->array == NULL ) {
        printf("s->array: Malloc failed\n");
        exit(1);
    }

    s->capacity = MaxSize;
    makeEmpty( s );
    return s;
}

void disposeStack( stack s )
{
    if( s != NULL ) {
        free( s->array );
        free( s );
    }
}

int isEmpty( stack s )
{
    return s->topOfStack == emptyTOS;
}

int isFull( stack s )
{
    return s->topOfStack == s->capacity - 1;
}

void push( int x, stack s )
{
    if( isFull( s ) ) {
        printf("Full stack\n");
        exit(1);
    }

    s->array[++s->topOfStack] = x;
}

int topAndPop( stack s )
{
    if( ! isEmpty(s) )
        return s->array[s->topOfStack--];

    printf("topAndPop: Empty stack\n");
    return 0;
}

void pop( stack s )
{
    if( ! isEmpty(s) )
        s->topOfStack--;
    else {

        printf("Pop: Empty stack\n");
        exit(1);
    }
}

int main()
{
    stack s;
    int i ;
    int ret;

    s = createStack( 9 );

    for( i = 0; i < s->capacity; i++)
        push(i, s);

    printf("isFull: %d\n", isFull(s));

    for( i = 0; i < s->capacity - 3; i++) {
        ret = topAndPop( s );
        printf("ret = %d\n", ret);
    }

    printf("topOfStack=%d\n", s->topOfStack);

    pop(s);
    pop(s);
    pop(s);

    printf("After pop(s): topOfStack=%d\n", s->topOfStack);
    printf("isEmpty: %d\n", isEmpty(s));

    disposeStack(s);

    return 0;
}
