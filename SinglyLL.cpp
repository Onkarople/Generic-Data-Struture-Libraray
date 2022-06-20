#include<iostream>

using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

template<class T>
class SinglyLL
{
   public:
      struct node<T> *Head;
      int Count;


      SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
    Head=NULL;
    Count=0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
   struct node<T> *newn=NULL;

   newn= new node<T>;

   newn->data=No;
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


template<class T>
void SinglyLL<T>::InsertLast(T No)
{
   struct node<T> *newn=NULL;

   newn= new node<T>;

   newn->data=No;
   newn->next=NULL;


   if(Head==NULL)
   {
      Head=newn;
   }
   else
   {
     struct node<T> *temp=Head;
      while(temp->next!=NULL)
      {
         temp=temp->next;
      }

      temp->next=newn;


   }
   Count++;
}


template<class T>
void SinglyLL<T>::DeleteFirst()
{
   if(Head==NULL)
   {
      return;
   }
   else
    {
        struct node<T> *temp=Head;
        Head=temp->next;
        free(temp);
    }
  
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    struct node<T> *temp=NULL;

    if(Head==NULL)
    {
        return;
    }
    else if((Head)->next==NULL)
    {
        free(Head);
        Head=NULL;
    }
    else
    { 
        temp=Head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }

        free(temp->next);
        temp->next=NULL;
        
    }
}

template<class T>
void SinglyLL<T>::InsertAtPos(T No,int iPos)
{
   struct node<T> *temp=NULL;
   struct node<T> *newn=NULL;
   



   if((iPos<1)||(iPos>(Count+1)))
   {
       cout<<"invalid input\n";
       return;
   }


   if(iPos==1)
   {
       InsertFirst(No);
   }
   else if(iPos==Count+1)
   {
       InsertLast(No);
   }
   else
   {  
       newn= new node<T>;

       newn->data=No;
       newn->next=NULL;


       temp=Head;
       for(int iCnt=1;iCnt<iPos-1;iCnt++)
       {
          temp=temp->next;
       }

       newn->next=temp->next;
       temp->next=newn;

   }

   Count++;
  

}

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
  
    struct node<T> *temp=NULL;
    struct node<T> *tempDelete=NULL;
    

    if(iPos<1||iPos>Count)
    {
        return;
    }

    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==Count)
    {
        DeleteLast();
    }
    else
    {
         temp=Head;
       for(int iCnt=1;iCnt<iPos-1;iCnt++)
       {
          temp=temp->next;
       }

       tempDelete=temp->next;
       temp->next=temp->next->next;
       delete(tempDelete);
}
}




template<class T>
void SinglyLL<T>::Display()
{
    cout<<"Elements are \n";
    struct node<T> *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}



int main()
{
  SinglyLL <int>obj1; 

  obj1.InsertFirst(21);
  obj1.InsertFirst(11);
  obj1.InsertLast(51);
  obj1.InsertLast(101);
  obj1.InsertAtPos(75,3);

  obj1.Display();

  obj1.DeleteAtPos(3);

  obj1.Display();

  cout<<"Count is:"<<obj1.CountNode()<<endl;

  SinglyLL <float>obj2; 

  obj2.InsertFirst(21.11);
  obj2.InsertFirst(11.31);
  obj2.InsertLast(51.44);
  obj2.InsertLast(101.21);

  obj2.Display();

  cout<<"Count is"<<obj2.CountNode()<<endl;


  SinglyLL <char>obj3;
  obj3.InsertFirst('A');
  obj3.InsertLast('B');
  obj3.InsertAtPos('C',2);

  obj3.Display();

  cout<<"Count is"<<obj3.CountNode()<<endl;

  obj3.DeleteAtPos(2);

  obj3.Display();

    return 0;
}