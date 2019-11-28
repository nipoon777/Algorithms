#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int key;
    Node *next;
    
    Node(int x)
    {
        key = x;
        next = NULL;
    }
};

Node *insertNode(Node *head, int key)
{
    Node *temp = new Node(key);
    
    temp ->next = head;
    
    return temp;
}

void printList(Node *head)
{
    Node *curr = head;
    
    while(curr != NULL)
    {
    cout<< curr->key << " ";
    curr = curr->next;
    }
}

void printMiddle(Node *head)
{
    if(head == NULL)
        return;
    Node *slow = head;
    Node *fast = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    cout<<slow->key<<" ";
    
}

int main() {
	Node *head = NULL;
	
	head = insertNode(head,7);
	
	head = insertNode(head,9);
	
	head = insertNode(head,18);
	
	head = insertNode(head,17);
	
	head = insertNode(head,28);
	
	printList(head);
	cout<<endl;
	
	//To find the middle of the Linked list 
	printMiddle(head);
	return 0;
}