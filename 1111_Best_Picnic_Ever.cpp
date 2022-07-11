#include <bits/stdc++.h>
using namespace std;
vector<int>vec[1010];
int ar[1010];
int vis[1010];
int flag[1010];

void dfs(int u)
{
    int i,v,sz;
    vis[u]=1;
    flag[u]++;
    sz = vec[u].size();
    for(i=0;i<sz;i++)
    {
        v = vec[u][i];
        if(vis[v]==0)
            dfs(v);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int tks,ks=1,k,cnt,n,m,u,v,i;
    scanf("%d",&tks);
    while(tks--)
    {
        scanf("%d%d%d",&k,&n,&m);
        for(i=1;i<=n;i++)
        {
            vec[i].clear();
            flag[i]=0;
        }
        for(i=0;i<k;i++)
            scanf("%d",&ar[i]);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            vec[u].push_back(v);
        }
        for(i=0;i<n;i++)
        {
            memset(vis,0,sizeof vis);
            dfs(ar[i]);
        }
        cnt = 0;
        for(i=1;i<=n;i++)
            if(flag[i]==k)
                cnt++;
        printf("Case %d: %d\n",ks++,cnt);
    }
    return 0;
}