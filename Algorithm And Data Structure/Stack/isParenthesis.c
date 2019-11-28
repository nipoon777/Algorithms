{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       if(ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
}
/*This is a function problem.You only need to complete the function given below*/
// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    stack<char> s;
    char ch;
    
    for(int i = 0 ; i < x.length(); i++)
    {
        if((x[i] == '[') || (x[i] == '{') || (x[i] == '('))
        {
            s.push(x[i]);
            continue;
        }
        if(s.empty())
        return false;
        
        switch(x[i])
        {
            case ')':
            ch = s.top();
            s.pop();
            if(ch == '{'|| ch == '[')
            return false;
            break;
            
            case '}':
            ch = s.top();
            s.pop();
            if(ch == '('|| ch == '[')
            return false;
            break;
            
            case ']':
            ch = s.top();
            s.pop();
            if(ch == '{'|| ch == '(')
            return false;
            break;
            
        }
        
    }
    
    return (s.empty());
}
