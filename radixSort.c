#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct ptrNode {
    int element;
    struct ptrNode *next;
}Node;

typedef Node Head;
typedef Node *List;

void printList(List L)
{
    if(L == NULL) {
        printf("Null List\n");
        return;
    }

    List p;
    p = L;

    while(p->next != NULL)
    {
        printf("%d ", p->next->element);
        p = p->next;
    }
    printf("\n\n");
}

void radixSort(List L, int n)
{
    int r, i, j;
    List p, b;

    /*定义10个桶*/
    Node N[10];

    for(j = 0; j < n; j++ )
    {
        /*桶初始化为空*/
        for( i = 0; i < 10; i++)
            N[i].next = NULL;

        p = L->next;
        while( p != NULL )
        {
            /*获取个,十,百位*/
            r = (int)(p->element / pow(10, j)) % 10;

            /*将b指向对应桶的链表尾端*/
            b = &N[r];
            while( b->next != NULL )
                b = b->next;

            b->next = p;            //链接到对应桶最末尾元素
            p = p->next;            //p指向下一个链表元素
            b->next->next = NULL;   //对应桶中末尾元素指向NULL
        }

        /*将桶中元素链接回List, 注意只要将首节点链接过去
         * 即可,之后定位到末尾元素再链接下一个桶*/
        p = L;
        for( i = 0; i < 10; i++ )
        {
            /*如果桶不为空*/
            if( N[i].next != NULL )
            {
                p->next = N[i].next;

                /*将p指向链表尾端*/
                while( p->next != NULL )
                    p = p->next;
            }
        }
    }
}

    int
main(int argc, char **argv)
{
    List tmp;       //指向新申请内存指针
    Head head;      //此为结构体变量，不是指针，作为头部
    List p = &head; //p 为指针，时刻指向链表末尾

    srand(time(NULL));

    p->next = NULL;
    /*随机生成10个3位数的整数*/
    for( int i = 0; i < 10; i++ )
    {
        tmp = malloc(sizeof(struct ptrNode));
        tmp->element = rand() % 1000;
        tmp->next = NULL;
        printf("Get element = %d\n", tmp->element);

        p->next = tmp;      //链接结构体到链表
        p = tmp;            //p移动至链表末尾
    }

    printf("\nBefore sort:\n");
    printList(&head);

    radixSort(&head, 3);

    printf("After radixSort:\n");
    printList(&head);

    p = head.next;
    while( p != NULL )
    {
        tmp = p->next;
        free(p);
        p = tmp;
    }

    return 0;
}
