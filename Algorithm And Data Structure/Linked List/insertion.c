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
    temp->next = head;
    return temp;
}

Node *insertEnd(Node *head, int key)
{
    if(head == NULL)
    return  new Node(key);
    
    Node *curr = head;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = new Node(key);
    return head;
}
void printList(Node *head)
{
    Node *curr = head;
    
    while(curr != NULL)
    {
        cout<<curr->key<<" ";
        curr= curr->next;
    }
}

int main() {
	Node *head = NULL;
	head = insertNode(head,7);
	head = insertNode(head,18);
	head = insertNode(head,27);
	head = insertNode(head,99);

	head = insertEnd(head, 7);
	head = insertEnd(head,18);
	head = insertEnd(head,27);
	head = insertEnd(head,99);
	printList(head);
	return 0;
}