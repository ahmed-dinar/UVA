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
string one;
int n;
i64 sz;

int multiple()
{
    i64 s=0;
    for(int i=0; i<sz; i++){
        s = s*10+(one[i]-'0');
        s=s%n;
    }
    if(s==0)
        return 1;

    return 0;
}


int main()
{
    int ans[]={0,1,0,3,0,0,0,6,0,9,0,4};

    while(scanf("%d",&n)==1){
        if(n<=11){
            printf("%d\n",ans[n]);
            continue;
        }
        if(n%2==0){
            printf("0\n");
            continue;
        }
        one="11";
        sz=2;
        while(multiple()==0){
            one += "1";
            sz++;
        }
        printf("%lld\n",sz);
    }
    return 0;
}



