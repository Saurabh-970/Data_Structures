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


//return second maximum
int SecMaximum(PNODE Head)
{
    PNODE temp =  Head;
    int iMax = 0, iMax2 = 0;

    while(temp != NULL)
    {
        if(temp -> Data > iMax)
        {
            iMax2 = iMax;
            iMax = temp -> Data;
        }
        else if((temp->Data > iMax2) && (temp->Data < iMax))
        {
            iMax2 = temp->Data;
        }
        temp = temp->Next;

    }

    return iMax2;

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

    iRet = SecMaximum(First);

    printf("Second Maximum element is : %d",iRet);

    return 0;
}