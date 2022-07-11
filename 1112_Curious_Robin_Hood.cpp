///Have faith in god.
#include<bits/stdc++.h>
using namespace std;
using ll= long long;
using ull= unsigned long long;
using pll= pair<ll,ll>;
using pii= pair<int,int>;
//=============Typedefines=============//
#define        nn           "\n"
#define        sp           " "
#define        F            first
#define        S            second
#define        pi           acos(-1.0)
#define        inf          1<<30 //2^30
#define        no           cout<<"NO"<<endl;
#define        yes          cout<<"YES"<<endl;
#define        all(x)       (x).begin(),(x).end()
#define        deb(a)       cout<<" # "<<#a<<" -> "<<a<<endl;
#define        test         int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define        _00_         ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
//=============Functions===============//
ll To_int(string str){stringstream ss(str); ll x = 0; ss >> x ; return x ;}
string To_string(ll x){stringstream ss; ss << x; string str = ss.str(); return str;}
template<typename T>T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b < 0)return gcd(a,-b);return (b == 0)?a:gcd(b,a%b);}
template<typename T>T lcm(T a,T b){if(a<0)return lcm(-a,b);if(b < 0)return lcm(a,-b);return a*(b/gcd(a,b));}
void inout()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
      //freopen("output.txt","w",stdout);
    #endif
}
int arr[100005],tree[100005];
int n;
	void update(int ind,int val)
{
    for(int i=ind;i<=n;i+=(i&-i))
        tree[i]+=val;
}

int query(int ind)
{
    int ret=0;
    for(int i=ind;i>0;i-=(i&-i))
        ret+=tree[i];
    return ret;
}
int main()
{
	  //_00_
	  //inout();
    test
    {
        int q;
       scanf("%d%d",&n,&q);
       for(int i=1;i<=n;i++)
         scanf("%d",&arr[i]);
          printf("Case %d:\n",tc);
        for(int i=1;i<=n;i++)
         update(i,arr[i]);
       while(q--)
       {
           int x;
           scanf("%d",&x);
           if(x==1)
           {
               int y;
               scanf("%d",&y);
               y++;
               int ans=query(y)-query(y-1);
              printf("%d\n",ans);
               update(y,-ans);
           }
           else if(x==2)
           {
               int y,z;
               scanf("%d%d",&y,&z);
               //y++;
               update(y+1,z);
           }
           else 
           {
               int y,z;
               scanf("%d%d",&y,&z);
               y++,z++;
              printf("%d\n",query(z)-query(y-1));
           }
       }
       memset(tree,0,sizeof tree);
    }
	return 0;
}