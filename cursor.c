#include <stdio.h>
#include <stdlib.h>

typedef int ptrNode; 

struct Node {
    int element;
    ptrNode next;
};

#define SIZE ( 10 )
struct Node cursorSpace[SIZE];

ptrNode cursorSpaceInit()
{
    int i;
    for(i = 0; i < SIZE-1; i++ )
        cursorSpace[i].next = i + 1;

    cursorSpace[i].next = 0;
}

ptrNode cursorAlloc()
{
    ptrNode p;
    p = cursorSpace[0].next;
    cursorSpace[0].next = cursorSpace[p].next;

    return p;
}

void cursorFree(ptrNode n)
{
    cursorSpace[n].next = cursorSpace[0].next;
    cursorSpace[0].next = n;
}

int isEmpty(ptrNode n)
{
    return cursorSpace[n].next == 0;
}

int isLast(ptrNode n, ptrNode L)
{
    /*判断第n个数是否为最后一位*/
    return cursorSpace[n].next == 0;
}

ptrNode find(int element, ptrNode L)
{
    ptrNode p;

    p = cursorSpace[L].next;

    while(p && cursorSpace[p].element != element)
        p = cursorSpace[p].next;

    return p;
}

ptrNode findPrevious(int x, ptrNode L)
{
    ptrNode p;

    /*获取查找元素的下标*/
    ptrNode target = find(x, L); 

    /*Not found*/
    if(target == 0)
        return -1;

    p = cursorSpace[L].next;

    while( p && cursorSpace[p].next != target )
        p = cursorSpace[ p ].next;

    return p;
}

void delete(int x, ptrNode L)
{
    ptrNode p, tmp;

    if((p = findPrevious(x, L))  == -1) {
        printf("Delete %d? element not found .\n", x);
        return;
    }

    if(!isLast( p, L ))
    {
        tmp = cursorSpace[p].next;
        cursorSpace[p].next = cursorSpace[tmp].next;
        cursorFree(tmp);
    }
}

void Error(char *str)
{
    printf("%s\n", str);
    exit(1);
}

void printLink(ptrNode L)
{
    ptrNode p =L;
    printf("List: ");
    while( ( p = cursorSpace[p].next ) != 0)
        printf("%d  ", cursorSpace[p].element);
    printf("\n");
}

/*x插入到p之后*/
void insert(int x, ptrNode L, ptrNode p)
{
    ptrNode tmp;

    tmp = cursorAlloc();
    if( tmp == 0 )
        Error("Out of space");

    cursorSpace[ tmp ].element = x;
    cursorSpace[ tmp ].next = cursorSpace[ p ].next;
    cursorSpace[ p ].next = tmp;
}

int
main(int argc, char **argv)
{
    ptrNode L;

    cursorSpaceInit();

    /*Header*/
    L = cursorAlloc();

    /*开始没有元素,头指针指向空(0)*/
    cursorSpace[L].next = 0;

    printf("\nInsert 1, 2, 3, 4\n");
    insert(1, L, 1);
    insert(2, L, 2);
    insert(3, L, 3);
    insert(4, L, 4);

    printLink(L);

    printf("\nAfter insert 6 into second index of List:\n");
    insert(6, L, 2);

    printLink(L);


    ptrNode res = findPrevious(5, L);
    if( res < 0 )
        printf("\nNot found element 5\n\n");
    else
        printf("\nfindPrevious(5, L) return index: %d\n\n", res);

    printf("isEmpty(L): %d\n", isEmpty(L));
    printf("isLast(4, L): %d\n\n", isLast(4, L)); 

    delete(5, L);
    printf("After delete(5, L), find(5, L): %d\n", find(5, L));

    printf("\nfind(2, L) return index: %d\n\n", find(2, L));

    printf("After delete element: 2\n");
    delete(2, L);
    printf("find(2, L): %d\n", find(2, L));
    printLink(L);

    return 0;
}
