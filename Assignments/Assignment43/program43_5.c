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


//addition of digits of element
void SumDigit(PNODE Head)
{
    PNODE temp =  Head;
    int iSum = 0, iNo = 0;

    while(temp != NULL)
    {
       iNo = temp->Data;
       iSum = 0;

       while(iNo != 0)
       {
            iSum = iSum + (iNo % 10);
            iNo = iNo / 10;
       }

       printf("%d\t",iSum);

       temp = temp->Next;
    }

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

    SumDigit(First);

    return 0;
}