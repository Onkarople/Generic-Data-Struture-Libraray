#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;


class SinglyLL
{
    public:
       PNODE Head;
       int Count;

       SinglyLL();
       void InsertFirst(int no);
       void Insertlast(int no);
       void InsertAtPos(int no,int pos);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int pos);
       void Display();
       int CountNode();


};


SinglyLL::SinglyLL()
{
    Head=NULL;
    Count=0;
}

 void SinglyLL::InsertFirst(int no)
 {
     PNODE newn=NULL;
     newn= new NODE;

     newn->data=no;
     newn->next=NULL;


     if(Head==NULL)
     {
        Head=newn;
     }
     else
     {
        newn->next=Head;
        Head=newn;
     }
     Count++;

 }

void SinglyLL::Insertlast(int no)
{
    PNODE newn=NULL;
    newn= new NODE;

     newn->data=no;
     newn->next=NULL;


     if(Head==NULL)
     {
        Head=newn;
     }
     else
     {
        PNODE temp=Head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;

     }
     Count++;
}


void SinglyLL::DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }
    else
    {
        PNODE temp=Head;
        Head=Head->next;
        delete temp;
    }
    Count--;
}

void SinglyLL::DeleteLast()
{
    if(Head==NULL)
    {
        return;
    }

    if(Count==1)
    {
        delete Head;
        Head=NULL;
    }
    else
    {
       PNODE temp=Head;
       while(temp->next->next!=NULL)
       {
         temp=temp->next;
       }
       delete temp->next;
       temp->next=NULL;
    }
    Count--;
}

void SinglyLL::InsertAtPos(int no,int pos)
{
    if(pos<1||pos>Count+1)
    {
        return;
    }

    if(pos==1)
    {
        InsertFirst(no);
    }
    else if(pos==Count+1)
    {
        Insertlast(no);
    }
    else
    {
        int iCnt=0;
        PNODE temp=Head;
        
        PNODE newn=NULL;

        newn=new NODE;

        newn->data=no;
        newn->next=NULL;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
           temp=temp->next;
        }

        newn->next=temp->next;
        temp->next=newn;
        Count++;

        
    }
}

void SinglyLL::DeleteAtPos(int pos)
{
    if(pos<1||pos>Count)
    {
        return;
    }

    if(pos==1)
    {
        DeleteFirst();
    }
    else if(pos==Count)
    {
        DeleteLast();
    }
    else
    {
        int iCnt=0;
        PNODE temp=Head;
        PNODE tempDelete=NULL;
        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
           temp=temp->next;
        }
       
         tempDelete=temp->next;
         temp->next=temp->next->next;
         delete tempDelete;
         Count--;
        
    }
}

void SinglyLL::Display()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}


int SinglyLL::CountNode()
{
    return Count;
}

int main()
{
   SinglyLL obj;

   obj.InsertFirst(11);
   obj.InsertFirst(21);
   obj.Insertlast(51);
   obj.Insertlast(101);
   obj.InsertAtPos(75,4);


   obj.Display();

   cout<<"Count Is:"<<obj.CountNode()<<endl;

   obj.DeleteFirst();
   obj.DeleteLast();


   obj.Display();

   cout<<"Count Is:"<<obj.CountNode()<<endl;

   obj.DeleteAtPos(2);

   obj.Display();



    return 0;
}