/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class Node
{
    int key;
    Node next;
    
    Node(int x)
    {
        key = x;
    }
    
};

class LList{
    Node head;
    
    void insertNode(int x)
    {
    Node temp = new Node(x);
    temp.next = head;
    head = temp;
    }
    void insertEnd(int x)
    {
        Node temp = new Node(x);
        if(head == null)
        {
            head = temp;
            return;
        }
        Node curr = head;
        while(curr.next != null)
        {
            curr = curr.next;
        }
        curr.next = temp;
        
    }
    void printNode()
    {
        Node curr = head;
        
        while(curr != null)
        {
            System.out.print(curr.key+ " ");
            curr = curr.next;
        }
    }
    
}

class GFG {
	public static void main (String[] args) {
	    
	    LList l = new LList();
	    l.insertNode(7);
	    l.insertNode(77);
	    l.insertNode(99);
	    l.insertEnd(7);
	    l.insertEnd(77);
	    l.insertEnd(99);
	    
		l.printNode();
	}
}