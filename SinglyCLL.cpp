
#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};


template<class T>
class SinglyCLL
{
    private:                    // Characteristics
        struct node<T> *Head;
        struct node<T>  *Tail;
        int Count;

    public:                     // Behaviours
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int CountNode();
};

template<class T>
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
    Count=0;
}

template<class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

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
    Count++;
}

template<class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;

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
    Count++;
}

template<class T>
void SinglyCLL<T>::InsertAtPos(T no, int ipos)
{
  
  int iCnt=0;
  

  if(ipos<1 || ipos>Count+1)
  {
      cout<<"invalid position\n";
      return;
  }

  if(ipos==1)
  {
      InsertFirst(no);
  }
  else if(ipos==Count+1)
  {
      InsertLast(no);
  }
  else
  {
      struct node<T> *newn=NULL;
      struct node<T> *temp=NULL;
      temp=Head;

      newn= new node<T>;


      newn->data=no;
      newn->next=NULL;

      for(iCnt=1;iCnt<ipos-1;iCnt++)
      {
          temp=temp->next;
      }

      newn->next=temp->next;
      temp->next=newn;
      Count++;

      
  }

}

template<class T>
void SinglyCLL<T>::DeleteFirst()
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

   Count--;
  

}

template<class T>
void SinglyCLL<T>::DeleteLast()
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
         struct node<T> *temp=Head;
         while(temp->next!=Tail)
         {
             temp=temp->next;
         }

         delete Tail;
         Tail=temp;

         Tail->next=Head;

   }
   Count--;


}

template<class T>
void SinglyCLL<T>::DeleteAtPos(int ipos)
{
  
  int iCnt=0;
  

  if(ipos<1 || ipos>Count)
  {
      cout<<"invalid position\n";
      return;
  }

  if(ipos==1)
  {
      DeleteFirst();
  }
  else if(ipos==Count)
  {
      DeleteLast();
  }
  else
  {
      
      struct node<T> *temp=NULL;
      temp=Head;
      struct node<T> *temp1=NULL;

      for(iCnt=1;iCnt<ipos-1;iCnt++)
      {
          temp=temp->next;
      }

      temp1=temp->next;
      temp->next=temp->next->next;
      delete temp1;  
      Count--;
  }
}

template<class T>
void SinglyCLL<T>::Display()
{
    struct node<T> *temp = Head;

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

template<class T>
int SinglyCLL<T>::CountNode()
{
    return Count;
}

int main()
{
    SinglyCLL <int>obj;
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

    iRet=obj.CountNode();
    cout<<"nodes are:"<<iRet<<endl;

    obj.InsertAtPos(75,4);
    obj.Display();

    iRet=obj.CountNode();
    cout<<"nodes are:"<<iRet<<endl;

    obj.DeleteAtPos(4);
    obj.Display();

    iRet=obj.CountNode();
    cout<<"nodes are:"<<iRet<<endl;



    SinglyCLL <char>obj1;
    

    obj1.InsertFirst('A');
    obj1.InsertFirst('B');
    obj1.InsertFirst('C');
    obj1.InsertLast('D');
    obj1.InsertLast('E');
    obj1.InsertLast('F');
    


    obj1.Display();

    
    cout<<"nodes are:"<<obj1.CountNode()<<endl;

    return 0;
}