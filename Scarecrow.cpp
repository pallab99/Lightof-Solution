#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("input.txt","r",stdin);
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;)
        {
            if(s[i]=='.')
            {
               cnt++;
               i+=3;
            }
            else
            i++;
        }
        printf("Case %d: %d\n",tc++,cnt);
    }
}