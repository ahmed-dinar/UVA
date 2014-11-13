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

int n1,n2;
int dp[105][105];
int x[105],y[105];

int tower(int i,int j)
{
    if(i>=n1 || j>=n2) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int tile=0;
    if(x[i]==y[j])
        tile=1+tower(i+1,j+1);
    else{
        int t1=tower(i+1,j);
        int t2=tower(i,j+1);
        tile=max(t1,t2);
    }
    return dp[i][j]=tile;
}

int main()
{
    int ca=0;
    while( scanf("%d %d",&n1,&n2) == 2 )
    {
        if(n1==0 && n2==0) break;

        for(int i=0; i<n1; i++)
            scanf("%d",&x[i]);
        for(int i=0; i<n2; i++)
            scanf("%d",&y[i]);
        memset(dp,-1,sizeof(dp));
        printf("Twin Towers #%d\n",++ca);
        printf("Number of Tiles : %d\n\n",tower(0,0));
    }
    return 0;
}
