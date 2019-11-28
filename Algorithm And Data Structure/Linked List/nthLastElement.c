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

void printNth(Node *head , int n)
{
    if(head == NULL)
    return;
    
    Node *ref_ptr = head;
    Node *main_ptr = head;
    
    for(int i = 0 ; i < n ; i++)
    {   
        if(ref_ptr == NULL)
        return;
        ref_ptr = ref_ptr->next;
    }
    while(ref_ptr != NULL)
    {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    
    cout<<(main_ptr->key)<< " ";
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
	//printMiddle(head);
	
	
	printNth(head,4);
	
	return 0;
}