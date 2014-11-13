#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
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
    int r,c,co;
    while(scanf("%d %d",&r,&c) != EOF){
        co=0;
        if(c>1)
            co=c-1;
        if(r>1)
            co=co*r+(r-1);
        printf("%d\n",co);
    }
    return 0;
}



