{
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        nextLargerElement(arr, n);
        
        cout<<endl;
    }
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
// Function to store Next larger elements
void nextLargerElement(long long arr[], int n){
    vector<long long> res;
    stack<long long> s;
    
    s.push(arr[n-1]);
    
    for(int i = n-1 ; i >=0 ; i--)
    {
        while(s.empty() == false && s.top()<= arr[i])
        s.pop();
        long long span = (s.empty()== true)?(-1):s.top();
        
        res.push_back(span);
        s.push(arr[i]);
    }
    reverse(res.begin(),res.end());
    for(int i = 0 ; i < res.size(); i++)
    cout<< res[i]<<" ";
}