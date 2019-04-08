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

#define emptyTOS  ( -1 )
#define minStackSize ( 5 )

struct stackRecord {
    int capacity;
    int topOfStack;
    int *array;
};
