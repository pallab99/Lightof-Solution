#include<bits/stdc++.h>
using namespace std;
const int high=20009;
const int BLACK=1;
const int RED=2;
const int WHITE=0;
vector<int>adj[high];
int ans=0,color[high],vampire=0,lykan=0;

void Clear()
{
    for(int i=0; i<high; i++)
    {
        adj[i].clear();
    }
}

void bfs(int s)
{
    queue<int>q;
    color[s]=BLACK;///consider it as vampire=black
    vampire++;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v=adj[u][i];
            if(color[v]==WHITE)
            {
                q.push(v);
                if(color[u]==BLACK)
                {
                    color[v]=RED;
                    lykan++;
                }
                else
                {
                    color[v]=BLACK;
                    vampire++;
                }

            }
        }
    }
}
int main()
{
    int t,tc=0,u,v,n,i=0;
    cin>>t;
    while(t--)
    {
        Clear();
        memset(color,0,sizeof color);
        vampire=0;
        lykan=0;
        ans=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0; i<high; i++)
        {
            if(!adj[i].empty() && color[i]==WHITE)
            {
                vampire = 0;
                lykan = 0;
                bfs(i);
                ans+=max(vampire,lykan);
            }
        }
        printf("Case %d: %d\n",++tc,ans);
    }
}
