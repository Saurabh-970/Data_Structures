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


//Addition of all even elements
int AdditionEven(PNODE Head)
{
    PNODE temp =  Head;
    int iSum = 0 ;

    while(temp != NULL)
    {
     
        if((temp -> Data) % 2 == 0)
        {
           iSum = iSum + temp -> Data;
        }
        temp = temp -> Next;
    }
    return iSum;

}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,20);
    InsertFirst(&First,17);
    InsertFirst(&First,41);
    InsertFirst(&First,89);
    InsertFirst(&First,28);
    InsertFirst(&First,20);
    InsertFirst(&First,6);
    InsertFirst(&First,11);

    iRet = AdditionEven(First);

    printf("Addition of all even  numbers are %d",iRet);

    return 0;
}