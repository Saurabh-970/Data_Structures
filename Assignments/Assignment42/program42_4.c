#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

struct node
{
    int Data;
    struct node *Next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> Next = NULL;
    newn -> Data = no;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn -> Next = *Head;
        *Head = newn;
    }
}

// largest element  from singly linear linked list
// Input linked list |10|->|20|->|30|->|40|->|50|->|30|->|70|
 
int Max(PNODE Head)
{
    PNODE temp =  Head;
    int iMax = 0;

    while(temp != NULL)
    {
        if(temp -> Data > iMax)
        {
            iMax = temp -> Data;
        }
        temp = temp ->Next;
    }
    return iMax;

}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,70);
    InsertFirst(&First,30);
    InsertFirst(&First,50);
    InsertFirst(&First,40);
    InsertFirst(&First,30);
    InsertFirst(&First,20);
    InsertFirst(&First,10);

    iRet = Max(First);

    printf("Largest number of all element is %d\n",iRet);

    return 0;
}