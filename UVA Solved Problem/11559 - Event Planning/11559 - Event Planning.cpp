#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

using namespace std;

#define ll long long

struct cost
{
    ll c;
    cost(ll nn) {c=nn;}
    bool operator<(const cost&e)const { return e.c < c;}
};

int main()
{
    ll N,B,H,W,flag,p;
    while( scanf("%lld %lld %lld %lld",&N,&B,&H,&W) == 4)
    {
        vector<ll>ho[100];
        vector<ll>price;
        priority_queue<cost>ans;
        for(int j=0; j<H; j++)
        {
            scanf("%lld",&p);
            price.push_back(p);
            for(int i=0; i<W; i++)
            {
                scanf("%lld",&p);
                ho[j].push_back(p);
            }
        }

        flag=0;
        for(int j=0; j<H; j++)
        {
            for(int i=0; i<W; i++)
            {
                if(ho[j][i]>=N)
                {
                    int sp=N*price[j];
                    if(sp<=B){
                        ans.push(cost(sp));
                        flag=1;
                    }
                }
            }
        }
        if(flag==1)
            printf("%lld\n",ans.top().c);
        else
            printf("stay home\n");
    }
    return 0;
}
