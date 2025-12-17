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


//Display perfect number from singly 
void Display(PNODE Head)
{
    PNODE temp =  Head;

    int i = 0, iSum = 0;

    while(temp != NULL)
    {
        iSum = 0;

        for(i = 1; i <= (temp -> Data / 2); i++)
        {
            if((temp-> Data % i) == 0)
            {
                iSum = iSum + i;
            }
        }

        if(iSum == temp -> Data)
        {
            printf("%d is a perfect number \n",temp-> Data);
        }

        temp = temp -> Next;
    }

}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,28);
    InsertFirst(&First,51);
    InsertFirst(&First,6);
    InsertFirst(&First,11);

    Display(First);

    return 0;
}