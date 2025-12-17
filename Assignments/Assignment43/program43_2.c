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


//Display prime number from singly 
void DisplayPrime(PNODE Head)
{
    PNODE temp =  Head;

    int i = 0, iCnt = 0;

    while(temp != NULL)
    {
      if(temp -> Data > 1)
      {
        iCnt = 0;

        for(i = 1; i <= (temp -> Data / 2); i++)
        {
            if((temp-> Data % i) == 0)
            {
                iCnt++;
            }
        }
        if(iCnt == 1)
        {
            printf("%d is a prime number\n", temp->Data);
        }
      } 

        temp = temp -> Next;
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
    InsertFirst(&First,51);
    InsertFirst(&First,6);
    InsertFirst(&First,11);

    DisplayPrime(First);

    return 0;
}