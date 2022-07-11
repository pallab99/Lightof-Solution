///Have faith in god.
#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    for (int tc = 1; tc <= t; tc++)
void inout()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.tnumt","w",stdout);
#endif
}
int main()
{
    // _00_
   // inout();
    int num;
    test
    {
        printf("Case %d:\n",tc);
        int n, m;
        cin >> n >> m;
        deque<int> dq;
        string op;
        while (m--)
        {
            cin >> op;
            if (op == "pushLeft")
            {
                cin >> num;
                if (dq.size() != n)
                {
                    dq.push_front(num);
                    printf("Pushed in left: %d\n",num);
                }
                else
                    printf("The queue is full\n");
            }
            else if (op == "pushRight")
            {
                cin >> num;
                if (dq.size() != n)
                {
                    dq.push_back(num);
                    printf("Pushed in right: %d\n",num);
                }
                else
                    printf("The queue is full\n");
            }
            else if (op == "popLeft")
            {
                if (dq.empty())
                    printf("The queue is empty\n");
                else
                {
                    printf("Popped from left: %d\n", dq.front());
                    dq.pop_front();
                }
            }
            else if (op == "popRight")
            {
                if (dq.empty())
                    printf("The queue is empty\n");
                else
                {
                    printf("Popped from right: %d\n", dq.back());
                    dq.pop_back();
                }
            }
        }
    }
    return 0;
}