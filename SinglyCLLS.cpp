
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyCLL
{
    private:                    // Characteristics
        PNODE Head;
        PNODE Tail;

    public:                     // Behaviours
        SinglyCLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};

SinglyCLL::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
}

void SinglyCLL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))    // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else        // If LL constains atleast one node
    {
        newn -> next = Head;
        Head = newn;
    }
    Tail -> next = Head;
}

void SinglyCLL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = no;
    newn->next = NULL;

    if((Head == NULL) && (Tail == NULL))    // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else        // If LL constains atleast one node
    {
        Tail -> next = newn;
        Tail = newn;
    }
    Tail -> next = Head;
}

void SinglyCLL::InsertAtPos(int no, int ipos)
{
  int iSize=0;
  int iCnt=0;
  iSize=Count();

  if(ipos<1 || ipos>iSize+1)
  {
      cout<<"invalid position\n";
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
      PNODE temp=NULL;
      temp=Head;

      newn= new NODE;


      newn->data=no;
      newn->next=NULL;

      for(iCnt=1;iCnt<ipos-1;iCnt++)
      {
          temp=temp->next;
      }

      newn->next=temp->next;
      temp->next=newn;

      
  }

}

void SinglyCLL::DeleteFirst()
{
   
   if(Head==NULL && Tail==NULL)    //if LL is empty
   {
        return;
   }
   else if(Head==Tail)     //if LL conatins one node
   {
      delete Head;
      Head=NULL;
      Tail=NULL;
   }
   else                     //if LL conatins more tahn one node
   {
         Head=Head->next;
         delete Tail->next;

         Tail->next=Head;

   }
  

}

void SinglyCLL::DeleteLast()
{
     if(Head==NULL && Tail==NULL)    //if LL is empty
   {
        return;
   }
   else if(Head==Tail)     //if LL conatins one node
   {
      delete Head;
      Head=NULL;
      Tail=NULL;
   }
   else                     //if LL conatins more tahn one node
   {
         PNODE temp=Head;
         while(temp->next!=Tail)
         {
             temp=temp->next;
         }

         delete Tail;
         Tail=temp;

         Tail->next=Head;

   }


}

void SinglyCLL::DeleteAtPos(int ipos)
{
  int iSize=0;
  int iCnt=0;
  iSize=Count();

  if(ipos<1 || ipos>iSize)
  {
      cout<<"invalid position\n";
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
      
      PNODE temp=NULL;
      temp=Head;
      PNODE temp1=NULL;

      for(iCnt=1;iCnt<ipos-1;iCnt++)
      {
          temp=temp->next;
      }

      temp1=temp->next;
      temp->next=temp->next->next;
      delete temp1;  
  }
}

void SinglyCLL::Display()
{
    PNODE temp = Head;

     if(Head==NULL && Tail==NULL)    //if LL is empty
     {
         return;
     }

     do
     {
       cout<<"|"<<temp->data<<"|-> ";
       temp = temp -> next;
     }while(temp != Tail->next);
    
    cout<<endl;
}

int SinglyCLL::Count()
{
    PNODE temp = Head;
    int iCnt=0;

     if(Head==NULL && Tail==NULL)    //if LL is empty
     {
         return 0;
     }

     do
    {
      iCnt++;
      temp = temp -> next;
    }while(temp != Tail->next);
    
    return iCnt;
}

int main()
{
    SinglyCLL obj;
    int iRet=0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(201);


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