///Have faith in god.
#include<bits/stdc++.h>
using namespace std;
#define     pi         acos(-1.0)

int main()
{
   //freopen("input.txt","r",stdin);
    
    int t,tc=1;
    cin>>t;
    while(t--)
    {
        double r,x,y,area1,area2;
        cin>>r;
        x=r*2;
        //deb(x);
        area1=x*x;
        //deb(area1);
        area2=pi*r*r;
        ///deb(area2);
        y=abs(area1-area2);
        //deb(y);
        printf("Case %d: %.2lf\n",tc++,y);
    }
	return 0;
}

