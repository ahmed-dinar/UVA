#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    long N,M,co,v;
    while(scanf("%ld %ld",&N,&M)==2){
        if(N==0&&M==0)
            break;
        vector<long>n;
        vector<long>m;
        for(int i=0; i<N; i++){
            scanf("%ld",&v);
            n.push_back(v);
        }
        for(int i=0; i<N; i++){
            scanf("%ld",&v);
            m.push_back(v);
        }
        co=0;
        for(int i=0; i<N; i++)
           if (binary_search (m.begin(), m.end(), n[i]))
                co++;
        printf("%ld\n",co);
    }
	return 0;
}
