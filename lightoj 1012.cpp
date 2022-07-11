#include<bits/stdc++.h>
using namespace std;
int v,e,cnt=0;
int X[4]= {-1,0,0,1};
int Y[4]= {0,-1,1,0};
char s[25][25];
int vis[25][25];
void dfs(int i,int j)
{
    vis[i][j]=1;

    int vx,vy,k;
    for(k=0; k<4; k++)
    {
        vx=X[k]+i;
        vy=Y[k]+j;
        if(vx>=0 && vx<v && vy>=0 && vy<e)
        {
            if(vis[vx][vy]==0 && s[vx][vy]=='.')
            {
                cnt++;
                dfs(vx,vy);
            }
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    int test,i,j,cas=0;
    scanf("%d",&test);
    while(test--)
    {
        cas++;
        scanf("%d %d",&e,&v);
        for(i=0; i<v; i++)
        {
            for(j=0; j<e; j++)
            {
                scanf(" %c",&s[i][j]);
            }
        }
        memset(vis,0,sizeof(vis));
        cnt=1;
        for(i=0; i<v; i++)
        {
            for(j=0; j<e; j++)
            {
                if(s[i][j]=='@')
                {
                    dfs(i,j);
                }
            }

        }
        printf("Case %d: %d\n",cas,cnt);
    }

}
