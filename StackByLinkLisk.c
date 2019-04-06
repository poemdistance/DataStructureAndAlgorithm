/*头文件部分*/
#ifndef __stack_h__
#define __stack_h__

struct Node;
typedef struct Node *ptrToNode;
typedef ptrToNode stack ;

int isEmpty(stack s);
stack CreateStack();
void MakeEmpty(stack s);
void push(int x, stack s);
void pop(stack s);
int top(stack s);

struct Node {
    int element;
    ptrToNode next;
};

#endif

#include <stdio.h>
#include <stdlib.h>

/*判断栈是否为空*/
int isEmpty(stack s)
{
    return s->next == NULL;
}

/*释放栈*/
void MakeEmpty(stack s)
{
    if( s == NULL ) {
        printf("Must use CreateStack first\n");
        return;
    }
    else 
        while( ! isEmpty(s) )
            pop(s);
}

/*初始化栈,返回链表头*/
stack CreateStack()
{
    stack Head = NULL;
    Head = malloc(sizeof(struct Node));
    if( Head == NULL ) {
        printf("malloc failed\n");
        exit(1);
    }

    MakeEmpty(Head);
    return Head;
}

/*将栈顶元素释放掉,并将头指针
 * 指向释放元素的下一个节点*/
void pop(stack s)
{
    ptrToNode p;

    if(isEmpty(s)) {
        printf("Empty stack\n");
        return;
    }

    p = s->next;
    s->next = p->next;
    free(p);
}

/*返回栈顶元素*/
int top(stack s)
{
    if( ! isEmpty(s) )
        return s->next->element;

    printf("Empty stack\n");
    return 1 << 31; /*给个返回值防止报错*/
}

/*插入新元素到链表头*/
void push(int x, stack s)
{
    ptrToNode p;
    p = malloc(sizeof(struct Node));
    if( p == NULL ) {
        printf("Malloc failed\n");
        exit(1);
    }

    p->element = x;
    p->next = s->next;
    s->next = p;
}

int main(int argc, char **argv)
{
    stack s = CreateStack();

    int i = 0;

    /*测试代码*/
    for( ; i < 8; i++ ) {
        push(i, s);
    }

    for( i = 0; i < 8; i++ ) {
        pop(s);
        printf("top=%d\n", top(s));
    }

    MakeEmpty(s);
    
    return 0;
}
    
