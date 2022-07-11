#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<pii>v(1001);
bool Compare(pii aa,pii bb)
{
  if(aa.second==bb.second)
  return aa.first>bb.first;
  return aa.second<bb.second;
}
void Precompute()
{
     for(int i=1;i<=1000;i++)
     {
       v[i].first=i;
       for(int j=i;j<=1000;j+=i)
         v[j].second+=1;
     }
    sort(v.begin(),v.end(),Compare);
}
int main()
{
    Precompute();
     int t;
     scanf("%d",&t);
     int tc=1;
     while(t--)
     {
       int n;
       scanf("%d",&n);
      printf("Case %d: %d\n",tc++,v[n].first);
     }
}