#include<iostream>

using namespace std;


struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;


class Queue
{
   public:
      PNODE Head;
      int Count;


      Queue();
      void Enqueue(int);    //Insertlast
      void  Dequeue();      //deletefirst
      void Display();
      int CountNode();

};


Queue::Queue()
{
    Head=NULL;
    Count=0;
}




void Queue::Enqueue(int No)
{
   PNODE newn=NULL;

   newn= new NODE;

   newn->data=No;
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



void Queue::Dequeue()
{
    int no;      //int no
   if(Count==0)
   {
      cout<<"Queue is Empty";
      return;
    
   }
   
   
    no=Head->data;
    PNODE temp=Head;
    Head=temp->next;
    delete(temp);
    
    Count--;
    cout<<"Removed element is:"<<no<<endl;
   
  
}



void Queue::Display()
{
    cout<<"Elements from Queue are \n";
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int Queue::CountNode()
{
    return Count;
}



int main()
{ 
    Queue obj1;

    obj1.Enqueue(11);
    obj1.Enqueue(21);
    obj1.Enqueue(51);
    obj1.Enqueue(101);

    obj1.Display();

    cout<<"Count of elements are :"<<obj1.CountNode()<<endl;


    obj1.Dequeue();
    obj1.Dequeue();
    obj1.Dequeue();


    obj1.Display();

    cout<<"Count of elements are :"<<obj1.CountNode()<<endl;

    obj1.Dequeue();
    obj1.Dequeue();



       
       

  

    return 0;
}