#include <iostream>
#include<bits/stdc++.h>


using namespace std;
int fibonacci(int n)
{
    if(n == 1 || n == 2)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        cout<<fibonacci(n);
        cout<<endl;
    }
    return 0;
}
