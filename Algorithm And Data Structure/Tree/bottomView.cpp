{
// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>
using namespace std;
// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};
// Method that prints the bottom view.
void bottomView(Node *root);
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
     scanf("%d
",&n);
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
     bottomView(root);
     cout << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */
// Method that prints the bottom view.
void fillMap(Node *root,int d,int l , map<int,pair<int,int>> &m)
{
    if(root == NULL)
    return;
    if(m.count(d) == 1)
    {
        m[d] = make_pair(root->data,l);
    }
    else if(m[d].second <= l)
    {   
        m[d] = make_pair(root->data,l);
    }
    fillMap(root->left,d-1,l+1,m);
    fillMap(root->right,d+1,l+1,m);
    
}
void bottomView(Node *root)
{
   if(root == NULL)
   return;
   map<int,pair<int,int>> m;
   
   fillMap(root,0,0,m);
   
   for(auto i = m.begin(); i != m.end(); i++)
   {
       cout<< i->second.first<<" ";
   }
}
