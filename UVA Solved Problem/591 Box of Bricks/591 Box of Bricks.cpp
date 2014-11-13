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
#include<unistd.h>

using namespace std;

#define ll long long

int h[55];

int mx_mn(int l,int *x,int *y)
{
    int mx=h[0],mn=h[0];
    *x=0;*y=0;
    for(int i=1; i<l; i++)
    {
        if(h[i]>mx){
            mx=h[i];
            *x=i;
        }
        if(h[i]<mn){
            mn=h[i];
            *y=i;
        }
    }
    if(mx != mn)
        return 0;
    return 1;
}

int main()
{
    int n,ca=0;
    while(scanf("%d",&n)==1 && n){
        int step=0,u,v;
        for(int i=0; i<n; i++){
            scanf("%d",&h[i]);
        }
        while(mx_mn(n,&u,&v) == 0)
        {
            h[u]--;
            h[v]++;
            step++;
        }
        printf("Set #%d\n",++ca);
        printf("The minimum number of moves is %d.\n\n",step);
    }
    return 0;
}



