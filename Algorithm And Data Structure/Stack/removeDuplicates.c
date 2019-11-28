{
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        string s;
        cin>>s;
        cout<<removeConsecutiveDuplicates(s)<<endl;
    }
    
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
// Function to print string after removing consecutive duplicates
string removeConsecutiveDuplicates(string str)
{
    string res ="";
    
    stack<char> s;
    
    s.push(str[0]);
    
    for(int i = 1 ; i < str.length() ; i++)
    {
        
        if(str[i] == s.top())
        continue;
        else
        {
        res += s.top();
        s.pop();
        s.push(str[i]);
        }
    }
    res+=s.top();
    s.pop();
    return res;
}
