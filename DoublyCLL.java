import java.lang.*;
import java.util.*;

class node {
    public int data;
    public node next;
    public node prev;
}

class DoublyCL {

    public node Head;
    public node tail;
    public int Count;

    public DoublyCL() {
        Head = null;
        tail = null;
        Count = 0;
    }

    public void InsertFirst(int no) {
        node newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if (Head == null && tail == null) {
            Head = newn;
            tail = newn;
        } else {
            newn.next = Head;
            Head.prev = newn;
            Head = newn;
        }
        Head.prev = tail;
        tail.next = Head;

        Count++;
    }

    public void Display() {
        node temp = Head;
        System.out.print("Elements are:");
        do {
            System.out.print("|" + temp.data + "|->");
            temp = temp.next;
        } while (temp != tail.next);
        System.out.println("NULL");
    }

    public int CountNode() {
        return Count;
    }

    public void InsertLast(int no) {
        node newn = new node();

        newn.data = no;
        newn.next = null;
        newn.prev = null;

        if (Head == null && tail == null) {
            Head = newn;
            tail = newn;
        } else {
            tail.next = newn;
            newn.prev = tail;
            tail = newn;
        }

        tail.next = Head;
        Head.prev = tail;
        Count++;
    }

    public void DeleteFirst() {
        if (Head == null && tail == null) {
            return;
        }

        else if (Head == tail) {
            Head = null;
            tail = null;
        } else {
            Head = Head.next;
            Head.prev = tail;
            tail.next = Head;

        }
        Count--;
    }

    public void DeleteLast() {
        if (Head == null && tail == null) {
            return;
        }

        else if (Head == tail) {
            Head = null;
            tail = null;
        } else {
            node temp = Head;
            node temp1 = null;

            while (temp.next != tail) {
                temp = temp.next;
            }

            temp1 = temp.next;
            temp1 = null;
            temp.next = Head;
            tail = temp;
        }
        Count--;
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
            newn.next.prev = newn;
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
            Count--;
        }
    }

}

class DoublyCLL {
    public static void main(String args[]) {
        DoublyCL obj = new DoublyCL();
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