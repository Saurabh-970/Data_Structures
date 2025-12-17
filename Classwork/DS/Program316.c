#include<stdlib.h>
#include<stdio.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE first,int no)
{
   PNODE newn = NULL;

   newn = (PNODE)malloc(sizeof(NODE));

   newn -> data = no;
   newn -> next = NULL;

   if (*first == NULL) // LL is empty
   {
     (*first) = newn;
   }
   else     // LL contains atleast one node
   {
        newn -> (*first);

        (*first) = newm;
   }

}

void InsertLast(PPNODE first,int no)
{
   PNODE newn = NULL:

   newn = (PNODE)malloc(sizeof(NODE));

   newn -> data = no;
   newn -> next = NULL;

   if (*first == NULL) // LL is empty
   {
    *first = newn;
   }
   else     // LL contains atleast one node
   {

   }

}

int main()
{
    PNODE head = NULL;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11); 

    return 0;
}