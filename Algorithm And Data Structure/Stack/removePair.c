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
        
        string ans = removePair (s);
        
        if(ans=="")
            cout<<"Empty String"<<endl;
        else
            cout<<ans<<endl;
    }
    
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
// Function to return string after removing consecutive duplicates
// Function to remove pair of characters
string removePair(string str){
    string res;
    int j = 0 ;
    res = str[0];
    int n = str.length();
    
    for(int i = 1 ; i < n ; i++)
    {
        if(j < 0)
        {
            res.push_back(str[i]);
            j++;
        }
        else if(str[i] == res[j])
        {
            res.pop_back();
            j--;
        }
        else 
        {
            res.push_back(str[i]);
            j++;
        }
        
    }
    return res;
}