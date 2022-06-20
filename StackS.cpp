#include<iostream>

using namespace std;


struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;



class Stack
{
   public:
      PNODE Head;
      int Count;


      Stack();
      void Push(int);    //InsertFirst
      void  Pop();      //deletefirst
      void Display();
      int CountNode();

};


Stack::Stack()
{
    Head=NULL;
    Count=0;
}

void Stack::Push(int No)
{
   PNODE newn=NULL;

   newn= new NODE;

   newn->data=No;
   newn->next=NULL;
  
   newn->next=Head;
   Head=newn;
   
   Count++;
}


void Stack::Pop()
{
    int no;      //int no
   if(Count==0)
   {
      cout<<"stack is Empty";
      return;
    
   }
   
   
    no=Head->data;
    PNODE temp=Head;
    Head=temp->next;
    delete(temp);
    
    Count--;
    cout<<"Removed element is:"<<no<<endl;
   
  
}


void Stack::Display()
{
    cout<<"Elements from Stack are \n";
    PNODE temp=Head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int Stack::CountNode()
{
    return Count;
}



int main()
{ 
    Stack obj1;

    obj1.Push(11);
    obj1.Push(21);
    obj1.Push(51);
    obj1.Push(101);

    

    obj1.Display();

    cout<<"Count of elements are :"<<obj1.CountNode()<<endl;


    obj1.Pop();
    obj1.Pop();

    obj1.Display();

    cout<<"Count of elements are :"<<obj1.CountNode()<<endl;

    obj1.Push(111);
    obj1.Display();

    obj1.Pop();
    obj1.Display();


    return 0;
}