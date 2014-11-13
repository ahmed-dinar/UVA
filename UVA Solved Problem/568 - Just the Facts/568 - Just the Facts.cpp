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

unsigned ll fac(unsigned ll n){
    unsigned ll x=1;
    for(unsigned ll i=1; i<=n; i++){
        x=((x%10000000000000000)*(i%100000000000000))%100000000000000;
        while(x%10==0){
            x=x/10;
        }
    }
    return (x%10);
}

int main()
{
    unsigned ll a;
    while( scanf("%llu",&a) == 1){
        printf("%5llu -> %llu\n",a,fac(a));
    }
    return 0;
}
