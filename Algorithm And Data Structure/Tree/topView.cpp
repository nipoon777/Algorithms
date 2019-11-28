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
void topView(struct Node *root);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  cin >> t;
  while (t--)
  {
     map<int, Node*> m;
     int n;
     cin >> n;
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
     topView(root);
     cout << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree

void fillMap(Node *root,int d, int l, map<int,pair<int,int>>&mp)
{
    if(root == NULL)
    return; 
    
    if(mp.count(d)== 0)
    {
        mp[d] = make_pair(root->data,l);
    }
    else if(mp[d].second > l)
    {
        mp[d] = make_pair(root->data,l);
    }
    fillMap(root->left,d-1,l+1,mp);
    fillMap(root->right,d+1,l+1,mp);
}
void topView(struct Node *root)
{
    if(root == NULL)
    return;
    
    
    map<int,pair<int,int>>mp;
    
    fillMap(root, 0 , 0 ,mp);
    
    for(auto i = mp.begin(); i != mp.end() ; i++)
    {
        cout<<i->second.first <<" ";
    }
    
}