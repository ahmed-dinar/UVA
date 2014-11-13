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
    int t,l,w,h,ca=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&l,&w,&h);
        if(l>20||w>20||h>20)
            printf("Case %d: bad\n",++ca);
        else
            printf("Case %d: good\n",++ca);
    }
    return 0;
}


