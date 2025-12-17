///////////////////////////////////////////////////////////////////////////////////////////
//
//  Required header files
//
///////////////////////////////////////////////////////////////////////////////////////////

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

/*------------------------------------------------------------------
        Old Name                    New Name
--------------------------------------------------------------------
        struct Node                 NODE
        struct Node*                PNODE
        struct Node**               PPNODE              
--------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////
//  Function name : InsertFirst
//  Description   : Used to insert at first position of Linked List
//  Parameters    : Address of First pointer & data of node
//  Return Value  : void
//////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////
//  Function name : SearchFirstOcc
//  Description   : Used to check occurence of position of Linked List
//  Parameters    : Address of First pointer & data of node
//  Return Value  : int
//////////////////////////////////////////////////////////////////////
 
int SearchFirstOcc(PNODE Head, int no)
{
    PNODE temp = Head;

    int iCheck = 1;

    while(temp != NULL)
    {
        if( temp -> Data == no)
        {
            return iCheck;
        }
        iCheck++;
        temp = temp -> Next;
        
    }
    return -1;
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

    iRet = SearchFirstOcc(First, 30);

    printf("Position of 30 is %d\n",iRet);

    return 0;
}