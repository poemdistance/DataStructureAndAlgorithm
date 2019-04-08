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
    int capacity;   /*栈容量*/
    int topOfStack; /*值指向栈顶元素*/
    int *array;     /*实际容纳变量的数组指针*/
};

void makeEmpty( stack s )
{
    /*值置-1, 表示栈为空*/
    s->topOfStack = emptyTOS;
}

stack createStack( int MaxSize )
{
    stack s;
    if( MaxSize < minStackSize ) {
        printf("stack size is too small\n");
        exit(1);
    }

    /*创建栈指针*/
    s = malloc( sizeof(struct stackRecord) );
    if( s == NULL ) {
        printf("Malloc failed\n");
        exit(1);
    }

    /*分配实际容纳变量的数组空间*/
    s->array = malloc( sizeof(int) * MaxSize );
    if( s->array == NULL ) {
        printf("s->array: Malloc failed\n");
        exit(1);
    }

    /*记录用户申请的栈空间大小*/
    s->capacity = MaxSize;
    makeEmpty( s );

    /*返回栈指针*/
    return s;
}

void disposeStack( stack s )
{
    /*释放内存空间*/
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
    /*栈顶值到达容量表示满栈了*/
    return s->topOfStack == s->capacity - 1;
}

void push( int x, stack s )
{
    if( isFull( s ) ) {
        printf("Full stack\n");
        exit(1);
    }

    /*赋值然后让栈顶指示元素+1*/
    s->array[++s->topOfStack] = x;
}

int topAndPop( stack s )
{
    /*返回栈顶元素,
     *并让栈顶指示元素-1表示释放了对应的栈元素空间*/
    if( ! isEmpty(s) )
        return s->array[s->topOfStack--];

    printf("topAndPop: Empty stack\n");
    return 0;
}

void pop( stack s )
{
    /*直接让栈顶指示变量-1表示弹出,对应空间被释放*/
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

    /*创建栈, 空间大小9个int*/
    s = createStack( 9 );

    /*以下为测试用例*/
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

    /*释放栈空间*/
    disposeStack(s);

    return 0;
}
