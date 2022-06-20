#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;


class DoublyLL
{
    public:
       PNODE Head;
       int Count;

       DoublyLL();
       void InsertFirst(int no);
       void Insertlast(int no);
       void InsertAtPos(int no,int pos);
       void DeleteFirst();
       void DeleteLast();
       void DeleteAtPos(int pos);
       void Display();
       int CountNode();


};


DoublyLL::DoublyLL()
{
    Head=NULL;
    Count=0;
}

 void DoublyLL::InsertFirst(int no)
 {
     PNODE newn=NULL;
     newn= new NODE;

     newn->data=no;
     newn->next=NULL;
     newn->prev=NULL;


     if(Head==NULL)
     {
        Head=newn;
     }
     else
     {
        newn->next=Head;
        Head->prev=newn;
        Head=newn;
     }
     Count++;

 }

void DoublyLL::Insertlast(int no)
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
        newn->prev=temp;

     }
     Count++;
}


void DoublyLL::DeleteFirst()
{
    if(Head==NULL)
    {
        return;
    }
    else
    {
       
        Head=Head->next;
        delete Head->prev;
        Head->prev=NULL;
    }
    Count--;
}

void DoublyLL::DeleteLast()
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

void DoublyLL::InsertAtPos(int no,int pos)
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
        newn->prev=NULL;

        for(iCnt=1;iCnt<pos-1;iCnt++)
        {
           temp=temp->next;
        }

        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
        Count++;

        
    }
}

void DoublyLL::DeleteAtPos(int pos)
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
       
         temp->next=temp->next->next;
         delete temp->next->prev;
         temp->next->prev=temp;
        
    }
}

void DoublyLL::Display()
{
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<"<-|"<<temp->data<<"|->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}


int DoublyLL::CountNode()
{
    return Count;
}

int main()
{
   DoublyLL obj;

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

