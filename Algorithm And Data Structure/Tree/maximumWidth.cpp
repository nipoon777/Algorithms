{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << getMaxWidth(root) << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*  Structure of a Binary Tree 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
/* Function to get the maximum width of a binary tree*/
int getMaxWidth(Node* root)
{
  queue<Node*> q;
  
  q.push(root);
  int res = 0;
  while(!q.empty())
  {
      
      int count = q.size();
      
      
      for(int i = 0 ; i < count; i++)
      {
          Node *curr = q.front();
          q.pop();
          if(curr->left != NULL)
          q.push(curr->left);
          if(curr ->right != NULL)
          q.push(curr->right);
      }
      res = max(res,count);
  }
  return res;
}
