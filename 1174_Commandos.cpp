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
#define        _00_         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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
int n,r;
vector<int>G[500];
int dist1[500],dist2[500],vis[500];
void bfs(int src)
{
    queue<int>q;
    q.push(src);
    dist1[src]=0;
    vis[src]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto nbr:G[u])
        {
            if(vis[nbr]==0)
            {
                vis[nbr]=1;
                dist1[nbr]=dist1[u]+1;
                q.push(nbr);
            }
        }
    }

}
void bfs1(int dst)
{
    queue<int>q;
    q.push(dst);
    dist2[dst]=0;
    vis[dst]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto nbr:G[u])
        {
            if(vis[nbr]==0)
            {
                vis[nbr]=1;
                dist2[nbr]=dist2[u]+1;
                q.push(nbr);
            }
        }
    }

}
int main()
{
	  _00_
	  inout();
    test
    {
        for(int i=0;i<500;i++)
        {
            G[i].clear();
            dist1[i]=0;
            dist2[i]=0;
            vis[i]=0;
        }
        cin>>n>>r;
        for(int i=0;i<r;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int src,dist;
        cin>>src>>dist;
        bfs(src);
        //for(int i=0;i<n;i++)
        //cout<<dist1[i]<<sp;
        memset(vis,0,sizeof vis);
        bfs1(dist);
        //for(int i=0;i<n;i++)
        //cout<<dist2[i]<<sp;
        int mx=0;
        for(int i=0;i<n;i++)
            mx=max(dist1[i]+dist2[i],mx);
        //deb(mx);  
        printf("Case %d: %d\n",tc,mx);  
    }
	return 0;
}