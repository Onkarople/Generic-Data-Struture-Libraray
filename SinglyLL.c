#include<stdio.h>
#include<stdlib.h>
////////////////////////////////////////

struct node
{
   int data;
   struct node * next;
};

////////////////////////////////////////


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

/////////////////////////////////////////


void InsertFirst(PPNODE head,int No)
{
   PNODE newn=NULL;                    //struct node * newn;

   newn=(PNODE)malloc(sizeof(NODE));  // (struct Node *) malloc(sizeof(struct node));


   newn->data=No;
   newn->next=NULL;

   if(*head==NULL)
   {
       *head=newn;
   }
   else
   {
       newn->next=*head;
       *head=newn;
   }


}

///////////////////////////////////////////////////

void InsertLast(PPNODE head,int No)
{
   PNODE newn=NULL;                    //struct node * newn;
   PNODE temp=NULL;
   
   newn=(PNODE)malloc(sizeof(NODE));  // (struct Node *) malloc(sizeof(struct node));


   newn->data=No;
   newn->next=NULL;

   if(*head==NULL)
   {
       *head=newn;
   }
   else
   {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newn;


   }


}
///////////////////////////////////////

void Display(PNODE head)
{
    printf("Elemnts are \n");
    while(head!=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

/////////////////////////////////////////////

int Count(PNODE head)
{
    int iCnt=0;
    while(head!=NULL)
    {
        iCnt++;
        head=head->next;
    }

    return iCnt;
}

///////////////////////////////////////////////


void DeleteFirst(PPNODE head)
{
    PNODE temp=NULL;

    if(*head==NULL)
    {
        return;
    }
    else
    {
        temp=*head;
        *head=temp->next;
        free(temp);
    }

}
///////////////////////////////////////////////

void DeleteLast(PPNODE head)
{
    PNODE temp=NULL;

    if(*head==NULL)
    {
        return;
    }
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    { 
        temp=*head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }

        free(temp->next);
        temp->next=NULL;
        
    }

}
///////////////////////////////////////////

void InsertAtPos(PPNODE head,int no,int pos)
{
   int size=0,iCnt=0;
   PNODE temp=NULL;
   PNODE newn=NULL;
   size=Count(*head);



   if((pos<1)||(pos>(size+1)))
   {
       printf("Invalid input\n");
       return;
   }


   if(pos==1)
   {
       InsertFirst(head,no);
   }
   else if(pos==size+1)
   {
       InsertLast(head,no);
   }
   else
   {  
       newn=(PNODE)malloc(sizeof(NODE));

       newn->data=no;
       newn->next=NULL;


       temp=*head;
       for(iCnt=1;iCnt<pos-1;iCnt++)
       {
          temp=temp->next;
       }

       newn->next=temp->next;
       temp->next=newn;


   }
  

}
//////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE head,int pos)
{
   int size=0,iCnt=0;
   PNODE temp=NULL;
   PNODE tempDelete=NULL;
   size=Count(*head);



   if((pos<1)||(pos>(size)))
   {
       printf("Invalid input\n");
       return;
   }


   if(pos==1)
   {
       DeleteFirst(head);
   }
   else if(pos==size)
   {
       DeleteLast(head);
   }
   else
   {  
       temp=*head;
       for(iCnt=1;iCnt<pos-1;iCnt++)
       {
          temp=temp->next;
       }

       tempDelete=temp->next;
       temp->next=temp->next->next;
       free(tempDelete);

      
   }
  

}



int main()
{
  PNODE First=NULL;
  int iRet=0;

  InsertFirst(&First,101);
  InsertFirst(&First,51);
  InsertFirst(&First,21);
  InsertFirst(&First,11);


  Display(First);

  iRet=Count(First);

  printf("Enterd node are: %d\n",iRet);


  InsertLast(&First,111);
  InsertLast(&First,121);

  Display(First);


  iRet=Count(First);

  printf("Enterd node are: %d\n",iRet);

  DeleteFirst(&First);
  DeleteLast(&First);

  Display(First);

  iRet=Count(First);

  printf("Enterd node are: %d\n",iRet);

  InsertAtPos(&First,75,3);
  DeleteAtPos(&First,3);

  Display(First);

  iRet=Count(First);

  printf("Enterd node are: %d\n",iRet);









    return 0;
}