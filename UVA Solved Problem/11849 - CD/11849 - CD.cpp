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

long n[1000005],m[1000005];

int main()
{
    long N,M,co;
    while(scanf("%ld %ld",&N,&M)==2)
    {
        if(N==0&&M==0)
            break;

        for(int i=0; i<N; i++)
            scanf("%ld",&n[i]);

        for(int i=0; i<M; i++)
            scanf("%ld",&m[i]);

        co=0;
        long k=0;
        for(int i=0; i<N; i++){
            for(int j=k; j<M; j++){
                if(n[i]<m[j])
                    break;
                if(n[i]==m[j]){
                    k=j+1;
                    co++;
                    break;
                }
            }
        }
        printf("%ld\n",co);
    }
	return 0;
}
