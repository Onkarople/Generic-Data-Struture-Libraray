#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;

};


typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void EnQueue(PPNODE Head,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    PNODE temp=*Head;

    newn->data=no;
    newn->next=NULL;


    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
       while (temp->next!=NULL)
       {
           temp=temp->next;
       }

       temp->next=newn;
       
    }

}


void Dqueue(PPNODE Head)
{
    PNODE temp=*Head;
    int no=0;
    
    if(*Head==NULL)
    {
        return;
    }

    else
    {
        
        temp=*Head;
        no=temp->data;
        *Head=temp->next;
        free(temp);
        printf("Removed data is:%d\n",no);
        
    }
}


void Display(PNODE head)
{
    printf("Elemnts from queue are \n");
    while(head!=NULL)
    {
        printf("|%d|->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

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



int main()
{
   PNODE First=NULL;
   int iRet=0;

   EnQueue(&First,11);
   EnQueue(&First,21);
   EnQueue(&First,51);

   Display(First);

   
   iRet=Count(First);
   printf("Count is:%d",iRet);



   Dqueue(&First);

   Display(First);



    return 0;
}