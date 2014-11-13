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
#include<time.h>

using namespace std;

map<long,long>par;

long find_pa(long X)
{
    if(par[X] == X)
         return X;
    else
        return par[X]=find_pa(par[X]);
}

int main()
{
    long n,m;
    while( scanf("%ld %ld",&n,&m) == 2 )
    {
        if(n==0 && m==0) break;

        long x,y,ans=1,tm,indx=1;
        string a,b;
        map<long,long>lenth;
        map<string,long>in;

        for(long i=0; i<n; i++)
            cin >> a;

        for(long i=0; i<m; i++)
        {
            cin >> a >> b;
            if(in[a]==0)
            {
                indx++;
                in[a]=indx;
            }

            if(in[b]==0)
            {
                indx++;
                in[b]=indx;
            }
            x=in[a];
            y=in[b];


            if(par[x]==0&&par[y]!=0)
            {
                long u=find_pa(y);
                par[x]=u;
                lenth[u]++;
                tm=lenth[u];
            }
            if(par[y]==0&&par[x]!=0)
            {
                long u=find_pa(x);
                par[y]=u;
                lenth[u]++;
                tm=lenth[u];
            }
            else if(par[x]==0 && par[y]==0)
            {
                par[y]=x;
                par[x]=x;
                lenth[x]=2;
                tm=lenth[x];
            }
            else
            {
                long u=find_pa(x);
                long v=find_pa(y);
                if( u!= v)
                {
                    lenth[u] += lenth[v];
                    lenth[v]=lenth[u];
                    par[v]=u;
                    tm=lenth[u];
                }
                if(lenth[x] != lenth[u])
                    lenth[x]=lenth[u];
                if(lenth[y] != lenth[v])
                    lenth[y]=lenth[v];
            }
            if(tm>ans)
                ans=tm;
        }
        printf("%ld\n",ans);
        par.clear();
    }
    return 0;
}
