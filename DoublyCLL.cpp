#include<iostream>
using namespace std;


template<class T>
struct node
{
   T data;
   struct node *next;
   struct node *prev;
};

template<class T>
class DoublyCLL
{
   private:
     struct node<T> *head;
     struct node<T>  *tail;
     int Count;

   public:
     DoublyCLL();
     void InsertFirst(T);
     void InsertLast(T);
     void InsertAtPos(T,int);
     void DeleteFirst();
     void DeleteLast();
     void DeleteAtPos(int);
     void Display();
     int CountNode();
};

template<class T>
DoublyCLL<T>::DoublyCLL()
{
    head=NULL;
    tail=NULL;
    Count=0;
}


template<class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn=NULL;

    newn= new node<T>;

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
    Count++;
}

template<class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn=NULL;

    newn=new node<T>;

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
  Count++;


}

template<class T>
void DoublyCLL<T>::InsertAtPos(T no,int ipos)
{
    
    if(ipos<0||ipos>Count+1)
    {
        cout<<"invalid\n";
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
        struct node<T> *temp=head;
        int iCnt=0;

        newn=new node<T>;

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
       Count++;
    }

}

template<class T>
void DoublyCLL<T>::DeleteAtPos(int ipos)
{
    
    if(ipos<0||ipos>Count)
    {
        cout<<"invalid\n";
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
        struct node<T> *temp=head;
        int iCnt=0;
       for(iCnt=1;iCnt<ipos-1;iCnt++)
       {
           temp=temp->next;
       }

        temp->next=temp->next->next;
        delete temp->next->prev;
        temp->next->prev=temp;
        Count--;
    }
}

template<class T>
void DoublyCLL<T>::DeleteFirst()
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
    Count--;

}

template<class T>
void DoublyCLL<T>::DeleteLast()
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
        struct node<T> *temp=head;
        struct node<T> *temp1=NULL;

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

template<class T>
void DoublyCLL<T>::Display()
{
    struct node<T> *temp=head;

    do
    {
     cout<<"|"<<temp->data<<"|->";
     temp=temp->next;
    } while (temp!=tail->next);
    cout<<"\n";
    
}

template<class T>
int DoublyCLL<T>::CountNode()
{
     
     return Count;
     
}


int main()
{
    int iRet=0;
   DoublyCLL  <int>obj;

   obj.InsertFirst(51);
   obj.InsertFirst(21);
   obj.InsertFirst(11);

   obj.InsertLast(101);
   obj.InsertLast(111);

   obj.InsertLast(121);
   obj.InsertLast(151);



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


   DoublyCLL <char>obj1;
    

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