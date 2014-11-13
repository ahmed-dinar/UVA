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

int main()
{
    int n;
    double d,v,u;
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%lf %lf %lf",&d,&v,&u);
        if(v==0 || u==0 || u<=v){
            printf("Case %d: can't determine\n",i);
        }
        else{
            printf("Case %d: %.3lf\n",i,(d/sqrt((u*u)-(v*v)))-(d/u));
        }
    }
    return 0;
}
