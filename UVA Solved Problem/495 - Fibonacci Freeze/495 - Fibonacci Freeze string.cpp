#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iterator>
#include<limits.h>

using namespace std;

char fib[5002][1050];

void fibonacci()
{
    int lf,ls,i,fm,carry;
    char temp[1050];
    string s("0"),f("1");
    for(int x=0; x<=5000; x++)
    {
        strcpy(fib[x],f.c_str());
        lf=f.size()-1;
        ls=s.size()-1;
        string sum;
        for(i=max(lf,ls),carry=0; i>=0; i--,ls--,lf--)
        {
            if(i==0)
            {
                if(ls<0){
                    fm=(f[lf]-48)+carry;
                }
                else if(lf<0){
                    fm=(s[ls]-48)+carry;
                }
                else{
                    fm=(s[ls]-48)+(f[lf]-48)+carry;
                }
                if(fm>=10){
                    sum.push_back(fm%10+48);
                    sum.push_back(fm/10+48);
                }
                else{
                    sum.push_back(fm+48);
                }
                break;
            }
            else if(lf<0)
            {
                fm=(s[ls]-48)+carry;
                sum.push_back(fm%10+48);
            }
            else if(ls<0)
            {
                fm=(f[lf]-48)+carry;
                sum.push_back(fm%10+48);
            }
            else
            {
                fm=(s[ls]-48)+(f[lf]-48)+carry;
                if(fm>=10)
                    sum.push_back(fm%10+48);
                else
                    sum.push_back(fm+48);
            }
            carry=fm/10;
        }
        s.clear();
        s=f;
        f.clear();
        for(int i=sum.size()-1; i>=0; i--){
            f.push_back(sum[i]);
        }
    }
}



int main()
{
    fibonacci();
    int lim;
    while(scanf("%d",&lim) == 1)
    {
        if( lim == 0)
            printf("The Fibonacci number for %d is %d\n",lim,lim);
        else
            printf("The Fibonacci number for %d is %s\n",lim,fib[lim-1]);
    }
    return 0;
}

