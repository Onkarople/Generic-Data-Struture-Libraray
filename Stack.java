import java.lang.*;
import java.util.*;

class node {
    public int data;
    public node next;
}

class Stackk {

    public node Head;
    public int Count;

    public Stackk() {
        Head = null;
        Count = 0;
    }

    public void Push(int no) {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if (Head == null) {
            Head = newn;
        } else {
            newn.next = Head;
            Head = newn;
        }

        Count++;
    }

    public void Display() {
        node temp = Head;
        System.out.print("Elements from Stack are:");
        while (temp != null) {
            System.out.print("|" + temp.data + "|->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public int CountNode() {
        return Count;
    }

    public void Pop() {
        if (Head == null) {
            return;
        }

        else {
            node temp = Head;
            int no = temp.data;
            Head = temp.next;
            temp = null;
            System.out.println("Removed element are" + no);

        }
        Count--;
    }

}

class Stack {
    public static void main(String args[]) {

        Stackk obj1 = new Stackk();

        obj1.Push(11);
        obj1.Push(21);
        obj1.Push(51);
        obj1.Push(101);

        obj1.Display();

        System.out.println("Count of elements are " + obj1.CountNode());

        obj1.Pop();
        obj1.Pop();

        obj1.Display();

        System.out.println("Count of elements are " + obj1.CountNode());

        obj1.Push(111);
        obj1.Display();

        obj1.Pop();
        obj1.Display();
    }
}