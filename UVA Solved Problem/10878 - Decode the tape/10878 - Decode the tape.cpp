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

#define EPS 0.0000000001
#define pr pair<int,int>
#define mp make_pair
#define ss second
#define fi first
#define i64 long long
#define nl printf("\n")
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 100005
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int decimal(string x){
    int p=0,dc,ln=x.size();
    dc = ((x[ln-1]-48)*1);
    for(int j=(ln-2); j>=0; j--)
    {
        dc = dc + ((x[j]-48)*(2<<p));
        p++;
    }
    return dc;
}

int main()
{
    //filein;
   // fileout;

    char a[100];
    while( gets(a) ){
        if( a[0] == '|' ){
            string n="";
            for(int i=0; a[i]!='\0'; i++){
                if( a[i]== ' ' )
                    n += '0';
                else if(a[i]=='o')
                    n += '1';
            }
            int num = decimal(n);
            printf("%c",(char)num);
        }
    }
    return 0;
}
