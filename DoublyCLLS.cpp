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


class DoublyCLL
{
   private:
     PNODE head;
     PNODE tail;

   public:
     DoublyCLL();
     void InsertFirst(int no);
     void InsertLast(int no);
     void InsertAtPos(int no,int ipos);
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int ipos);
     void Display();
     int Count();
};

DoublyCLL::DoublyCLL()
{
    head=NULL;
    tail=NULL;
}

void DoublyCLL::InsertFirst(int no)
{
    PNODE newn=NULL;

    newn= new NODE;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

   
   if(head==NULL && tail==NULL)
   {
       head=newn;
       tail=newn;
   }
   else
   {
       newn->next=head;
       head->prev=newn;
       head=newn;
       
      
   }
    head->prev=tail;
    tail->next=head;

}

void DoublyCLL::InsertLast(int no)
{
    PNODE newn=NULL;

    newn=new NODE;

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

     if(head==NULL && tail==NULL)
   {
       head=newn;
       tail=newn;
   }
   else
   {
       tail->next=newn;
       newn->prev=tail;
       tail=newn;

   }
  tail->next=head;
  head->prev=tail;


}

void DoublyCLL::InsertAtPos(int no,int ipos)
{
    int iSize=Count();
    if(ipos<0||ipos>iSize+1)
    {
        cout<<"invalid\n";
        return;
    }
    
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==iSize+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn=NULL;
        PNODE temp=head;
        int iCnt=0;

        newn=new NODE;

       newn->data=no;
       newn->next=NULL;
       newn->prev=NULL;

       for(iCnt=1;iCnt<ipos-1;iCnt++)
       {
           temp=temp->next;
       }

       newn->next=temp->next;
       newn->next->prev=newn;
       temp->next=newn;
       newn->prev=temp;
    }

}

void DoublyCLL::DeleteAtPos(int ipos)
{
    int iSize=Count();
    if(ipos<0||ipos>iSize)
    {
        cout<<"invalid\n";
        return;
    }
    
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==iSize)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp=head;
        int iCnt=0;
       for(iCnt=1;iCnt<ipos-1;iCnt++)
       {
           temp=temp->next;
       }

        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
    }
}

void DoublyCLL::DeleteFirst()
{
    if(head==NULL && tail==NULL)
    {
        return;
    }
    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        head=head->next;
        delete head->prev;
        head->prev=tail;
        tail->next=head;
    }

}

void DoublyCLL::DeleteLast()
{
   if(head==NULL && tail==NULL)
    {
        return;
    }
    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        PNODE temp=head,temp1=NULL;

        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        delete temp1;
        temp->next=head;
        tail=temp;
    }
}

void DoublyCLL::Display()
{
    PNODE temp=head;

    do
    {
     cout<<"|"<<temp->data<<"|->";
     temp=temp->next;
    } while (temp!=tail->next);
    cout<<"\n";
    
}

int DoublyCLL::Count()
{
     PNODE temp=head;
     int iCnt=0;

    do
    {
      iCnt++;
     temp=temp->next;
    } while (temp!=tail->next);

    return iCnt;
     
}


int main()
{
    int iRet=0;
   DoublyCLL obj;

   obj.InsertFirst(51);
   obj.InsertFirst(21);
   obj.InsertFirst(11);

   obj.InsertLast(101);
   obj.InsertLast(111);

   obj.InsertLast(121);
   obj.InsertLast(151);



   obj.Display();

   iRet=obj.Count();

   cout<<"nodes are:"<<iRet<<endl;

   obj.InsertAtPos(75,4);

   obj.Display();

   iRet=obj.Count();

   cout<<"nodes are:"<<iRet<<endl;

   obj.DeleteAtPos(4);
   obj.Display();

   iRet=obj.Count();

   cout<<"nodes are:"<<iRet<<endl;


    return 0;
}