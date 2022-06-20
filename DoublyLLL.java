import java.lang.*;
import java.util.*;

class node {
    public int data;
    public node next;
    public node prev;
}

class DoublyLL {

    public node Head;
    public int Count;

    public DoublyLL() {
        Head = null;
        Count = 0;
    }

    public void InsertFirst(int no) {
        node newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if (Head == null) {
            Head = newn;
        } else {
            newn.next = Head;
            Head.prev = newn;
            Head = newn;
        }

        Count++;
    }

    public void Display() {
        node temp = Head;
        System.out.print("Elements are:");
        while (temp != null) {
            System.out.print("|" + temp.data + "|->");
            temp = temp.next;
        }
        System.out.println("NULL");
    }

    public int CountNode() {
        return Count;
    }

    public void InsertLast(int no) {
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
            newn.prev = temp;
        }

        Count++;
    }

    public void DeleteFirst() {
        if (Head == null) {
            return;
        }

        else {
            Head = Head.next;
            Head.prev = null;

        }
        Count--;
    }

    public void DeleteLast() {
        if (Head == null) {
            return;
        }

        else {
            node temp = Head;

            while (temp.next.next != null) {
                temp = temp.next;
            }

            temp.next = null;
            Count--;

        }
    }

    public void InsertAtPos(int no, int pos) {
        if (pos < 1 || pos > Count + 1) {
            return;
        }

        if (pos == 1) {
            InsertFirst(no);
        } else if (pos == Count + 1) {
            InsertLast(no);
        } else {
            node newn = new node();

            newn.data = no;
            newn.next = null;
            newn.prev = null;

            node temp = Head;
            for (int iCnt = 1; iCnt < pos - 1; iCnt++) {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next.prev = newn;
            temp.next = newn;
            newn.prev = temp;
            Count++;
        }

    }

    public void DeleteAtPos(int pos) {
        if (pos < 1 || pos > Count) {
            return;
        }

        if (pos == 1) {
            DeleteFirst();

        } else if (pos == Count) {
            DeleteLast();

        } else {

            node temp = Head;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++) {
                temp = temp.next;
            }
            temp.next = temp.next.next;
            temp.next.prev = temp;
        }
    }

}

class DoublyLLL {
    public static void main(String args[]) {
        DoublyLL obj = new DoublyLL();
        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.InsertLast(101);
        obj.InsertLast(111);

        obj.InsertAtPos(55, 4);

        obj.Display();

        obj.DeleteAtPos(4);
        obj.Display();

        System.out.println("elements are:" + obj.CountNode());

        obj.DeleteFirst();
        obj.DeleteLast();
        obj.Display();

    }
}