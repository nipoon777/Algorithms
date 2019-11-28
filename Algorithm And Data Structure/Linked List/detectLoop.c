{
// C program to detect loop in a linked list
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
void push(struct Node **head_ref, int new_data) {
    struct Node *new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}
int detectloop(struct Node *list);
/* Driver program to test above function*/
int main() {
    int t, n, c, x, i;
    cin >> t;
    while (t--) {
        /* Start with the empty list */
        cin >> n;
        struct Node *head = NULL;
        struct Node *temp;
        struct Node *s;
        cin >> x;
        push(&head, x);
        s = head;
        for (i = 1; i < n; i++) {
            cin >> x;
            push(&head, x);
        }
        /* Create a loop for testing */
        cin >> c;
        if (c > 0) {
            c = c - 1;
            temp = head;
            while (c--) temp = temp->next;
            s->next = temp;
        }
        int g = detectloop(head);
        if (g)
            cout << "True
";
        else
            cout << "False
";
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/

/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
*/
int detectloop(Node *head) {
    
    
    Node *slow_ptr = head;
    Node *fast_ptr = head;
    
    while(fast_ptr != NULL && fast_ptr ->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        
        if(slow_ptr == fast_ptr)
        return 1;
    }
   
   return 0;
    
}