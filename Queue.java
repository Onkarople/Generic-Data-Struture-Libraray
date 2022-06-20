import java.lang.*;
import java.util.*;

class node {
    public int data;
    public node next;
}

class Queuee {

    public node Head;
    public int Count;

    public Queuee() {
        Head = null;
        Count = 0;
    }

    public void Display() {
        node temp = Head;
        System.out.print("Elements from queue are:");
        while (temp != null) {
            System.out.print("|" + temp.data + "|->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public int CountNode() {
        return Count;
    }

    public void Enqueue(int no) {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if (Head == null) {
            Head = newn;
        } else {
            node temp = Head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newn;
        }

        Count++;
    }

    public void Dequeue() {
        if (Head == null) {
            System.out.println("Queue is empty");
            return;
        }

        else {

            node temp = Head;
            int no = temp.data;
            Head = temp.next;
            temp = null;
            System.out.println("removed data is " + no);

        }
        Count--;
    }

}

class Queue {
    public static void main(String args[]) {
        Queuee obj1 = new Queuee();

        obj1.Enqueue(11);
        obj1.Enqueue(21);
        obj1.Enqueue(51);
        obj1.Enqueue(101);

        obj1.Display();

        System.out.println("Count of elements are :" + obj1.CountNode());

        obj1.Dequeue();
        obj1.Dequeue();
        obj1.Dequeue();

        obj1.Display();

        System.out.println("Count of elements are :" + obj1.CountNode());

        obj1.Dequeue();
        obj1.Dequeue();

    }
}