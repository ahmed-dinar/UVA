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

ll gcd(ll x,ll y)
{
    if(y==0) return x;

    return gcd(y,x%y);
}

int main()
{
    char test[4];
    char numbers[1000000];
    ll n[110],i;
    gets(test);
    int t = atoi(test);
    while(t--)
    {
        gets(numbers);
        char *ch;
        ch = strtok(numbers," ");
        i=0;
        while(ch != NULL)
        {
            n[i]=atoi(ch);
            i++;
            ch = strtok(NULL," ");
        }
        ll ln=i,k;
        ll mx=0;
        for(i=0; i<ln-1; i++)
            for(ll j=i+1; j<ln; j++){
                k=gcd( max(n[i],n[j]), min(n[i],n[j]) );
                if(k>mx)
                    mx=k;
            }
        cout << mx << endl;
    }
    return 0;
}









