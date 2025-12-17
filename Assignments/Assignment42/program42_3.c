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

// addition of all elements from singly linear linked list
// Input linked list |10|->|20|->|30|->|40|->|50|->|30|->|70|
 
int Addition(PNODE Head)
{
    PNODE temp =  Head;
    int iSum = 0;

    while(temp != NULL)
    {
        iSum = iSum + temp -> Data;
        temp = temp -> Next;
           
    }
    return iSum;

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

    iRet = Addition(First);

    printf("Addition of element is %d\n",iRet);

    return 0;
}