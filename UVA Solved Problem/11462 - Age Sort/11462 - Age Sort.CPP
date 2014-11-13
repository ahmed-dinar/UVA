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

struct age
{
    int a;
    age(int x){a=x;}
    bool operator < (const age&p)const{return p.a < a;}
};

int main()
{
    priority_queue<age>AGE;
    int t,n;
    while(scanf("%d",&t)==1){
        if(t==0) break;

        for(int i=0; i<t; i++){
            scanf("%d",&n);
            AGE.push(n);
        }
        while(!AGE.empty()){
            printf("%d",AGE.top().a);
            AGE.pop();
            if(!AGE.empty())
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}



