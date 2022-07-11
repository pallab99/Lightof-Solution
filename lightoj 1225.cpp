#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int ks=0;
    for(int i=1;i<=t;i++)
    {
        string s;
    cin>>s;
    string a=s;
    reverse(s.begin(),s.end());
    if(s==a)
        cout<<"Case"<<" "<<i<<":"<<" "<<"Yes"<<endl;
        else
            cout<<"Case"<<" "<<i<<":"<<" "<<"No"<<endl;
    }

}
