///Have faith in god.
#include<bits/stdc++.h>
using namespace std;
#define     Fin        freopen("input.txt","r",stdin)
#define     FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
///-------------------functions----------------------///
int arr[200];
int Find(int n)
{
   vector<pair<int,int>> vec(n); 
    for(int i=0;i<n;i++) 
    { 
        vec[i].first=arr[i]; 
        vec[i].second=i; 
    } 
    sort(vec.begin(),vec.end()); 
    int ans=0,c=0,j; 
    for(int i=0;i<n;i++) 
    {    
        if(vec[i].second==i)  
            continue; 
        else
        { 
            swap(vec[i].first,vec[vec[i].second].first); 
            swap(vec[i].second,vec[vec[i].second].second);  
        }  
        if(i!=vec[i].second) 
            --i; 
        ans++; 
    }
    return ans; 
}
int main()
{
	FasterIO
    //Fin;
    int tc=1;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        cin>>arr[i];
        printf("Case %d: %d\n",tc++,Find(n));
    }
	return 0;
}

