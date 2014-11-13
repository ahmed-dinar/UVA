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
    long long indx,ca=0;
    while( scanf("%lld",&indx) == 1)
    {
        if(indx == 0) break;

        double u,v,t,s,a;
        if(indx == 1)
        {
            scanf("%lf %lf %lf",&u,&v,&t);
            a = (v-u) / t;
            s = (u*t) + ((a*(t*t))/2);
            printf("Case %lld: %.3lf %.3lf\n",++ca,s,a);
        }
        else if(indx == 2)
        {
            scanf("%lf %lf %lf",&u,&v,&a);
            t = (v-u) / a;
            s = (u*t) + ((a*(t*t))/2);
            printf("Case %lld: %.3lf %.3lf\n",++ca,s,t);
        }
        else if(indx == 3)
        {
            scanf("%lf %lf %lf",&u,&a,&s);
            v = sqrt( (u*u) + (2*a*s) );
            t = (v-u) / a;
            printf("Case %lld: %.3lf %.3lf\n",++ca,v,t);
        }
        else if(indx == 4)
        {
            scanf("%lf %lf %lf",&v,&a,&s);
            u = sqrt( (v*v) - (2*a*s) );
            t = (v-u) / a;
            printf("Case %lld: %.3lf %.3lf\n",++ca,u,t);
        }
    }
    return 0;
}



