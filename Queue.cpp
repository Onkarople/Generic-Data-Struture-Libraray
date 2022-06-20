#include<iostream>

using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

template<class T>
class Queue
{
   public:
      struct node<T> *Head;
      int Count;


      Queue();
      void Enqueue(T);    //Insertlast
      void  Dequeue();      //deletefirst
      void Display();
      int CountNode();

};

template<class T>
Queue<T>::Queue()
{
    Head=NULL;
    Count=0;
}



template<class T>
void Queue<T>::Enqueue(T No)
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
void Queue<T>::Dequeue()
{
    T no;      //int no
   if(Count==0)
   {
      cout<<"Queue is Empty";
      return;
    
   }
   
   
    no=Head->data;
    struct node<T> *temp=Head;
    Head=temp->next;
    delete(temp);
    
    Count--;
    cout<<"Removed element is:"<<no<<endl;
   
  
}


template<class T>
void Queue<T>::Display()
{
    cout<<"Elements from Queue are \n";
    struct node<T> *temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


template<class T>
int Queue<T>::CountNode()
{
    return Count;
}



int main()
{ 
    Queue <int>obj1;

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