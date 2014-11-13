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

int main(void)
{
    long t,a,b,c,d;
    scanf("%ld",&t);
    while( t-- )
    {
        scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
        if(a==b && b==c && c==d && d==a)
            printf("square\n");
        else if( (a==b && c==d) || (a==c && b==d) || (a==d && b==c))
            printf("rectangle\n");
        else if( (a+b+c)>d && (a+b+d) > c && (a+c+d) > b && (b+c+d)>a )
             printf("quadrangle\n");
        else
             printf("banana\n");
    }
    return 0;
}

