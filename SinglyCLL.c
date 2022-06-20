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


void InsertFirst(PPNODE head,PPNODE tail,int No)
{
   PNODE newn=NULL;                    //struct node * newn;

   newn=(PNODE)malloc(sizeof(NODE));  // (struct Node *) malloc(sizeof(struct node));


   newn->data=No;
   newn->next=NULL;

   if(*head==NULL && *tail==NULL)
   {
       (*head)=newn;
       (*tail)=newn;
   }
   else
   {
       newn->next=(*head);
       (*head)=newn;
      
   }
    (*tail)->next=(*head);
   
  
}

///////////////////////////////////////////////////

void InsertLast(PPNODE head,PPNODE tail,int No)
{
   PNODE newn=NULL;                    //struct node * newn;
   PNODE temp=NULL;
   
   newn=(PNODE)malloc(sizeof(NODE));  // (struct Node *) malloc(sizeof(struct node));


   newn->data=No;
   newn->next=NULL;

   if(*head==NULL)
   {
       *head=newn;
       *tail=newn;
   }
   else
   {
        (*tail)->next=newn;
        *tail=newn;
   }
   (*tail)->next=*head;


}
///////////////////////////////////////

void Display(PNODE head,PNODE tail)
{
    printf("Elemnts are \n");
    do
    {
        printf("|%d|->",head->data);
        head=head->next;
    }while(head!=tail->next);
    printf("NULL\n");
}

/////////////////////////////////////////////

int Count(PNODE head,PNODE tail)
{
    int iCnt=0;
   do
    {
        iCnt++;
        head=head->next;
    } while(head!=tail->next);

    return iCnt;
}

///////////////////////////////////////////////


void DeleteFirst(PPNODE head,PPNODE tail)
{
    PNODE temp=NULL;

    if(*head==NULL&&*tail==NULL)
    {
        return;
    }
    else if(*head==*tail)
    {
        free (*head);
        *head=NULL;
        *tail=NULL;
    }
    else
    {
          *head= (*head)->next;
          free((*tail)->next);

          (*tail)->next=*head;
    }

}
///////////////////////////////////////////////

void DeleteLast(PPNODE head,PPNODE tail)
{
    PNODE temp=NULL;

    if(*head==NULL && *tail==NULL)
    {
        return;
    }
    else if(*head==*tail)
    {
        free(*head);
        *head=NULL;
        *tail=NULL;
    }
    else
    { 
        temp=*head;
        while(temp->next!=*tail)
        {
            temp=temp->next;
        }

        free(*tail);
        (*tail)->next=*head;
        
    }

}
///////////////////////////////////////////

void InsertAtPos(PPNODE head,PPNODE tail,int no,int pos)
{
   int size=0,iCnt=0;
   PNODE temp=NULL;
   PNODE newn=NULL;
   size=Count(*head,*tail);



   if((pos<1)||(pos>(size+1)))
   {
       printf("Invalid input\n");
       return;
   }


   if(pos==1)
   {
       InsertFirst(head,tail,no);
   }
   else if(pos==size+1)
   {
       InsertLast(head,tail,no);
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

void DeleteAtPos(PPNODE head,PPNODE tail,int pos)
{
   int size=0,iCnt=0;
   PNODE temp=NULL;
   PNODE tempDelete=NULL;
   size=Count(*head,*tail);



   if((pos<1)||(pos>(size)))
   {
       printf("Invalid input\n");
       return;
   }


   if(pos==1)
   {
       DeleteFirst(head,tail);
   }
   else if(pos==size)
   {
       DeleteLast(head,tail);
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
  PNODE Last=NULL;
  int iRet=0;

  InsertFirst(&First,&Last,101);
  InsertFirst(&First,&Last,51);
  InsertFirst(&First,&Last,21);
  InsertFirst(&First,&Last,11);


  Display(First,Last);

  iRet=Count(First,Last);

  printf("Enterd node are: %d\n",iRet);

  InsertLast(&First,&Last,121);
  Display(First,Last);
  InsertAtPos(&First,&Last,151,4);
  Display(First,Last);

  DeleteFirst(&First,&Last);
  DeleteLast(&First,&Last);
  DeleteAtPos(&First,&Last,2);
  Display(First,Last);

  







    return 0;
}