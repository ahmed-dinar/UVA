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

#define eps 0.0000000001
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
#define MAX 1000001
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

vector<int>prime;
int res[MAX];

void sieve(){
    int bol[1011]={0};
    for(int i = 3; i*i <= 1011; i+=2 )
        if( bol[i] == 0)
            for(int j = i*i; j <= 1011; j += 2*i )
                bol[j] = 1;

    prime.pb(2);
    for(int i = 3; i <= 1011; i+=2 )
        if( bol[i] == 0)
            prime.pb(i);
}

int primeFactorize(int n ){
    int co=0;
    for(int i = 0; (prime[i]*prime[i]) <=n; i++ ){
        if( n % prime[i] == 0 ){
            while( n % prime[i] == 0 ){
                n /= prime[i];
                co++;
            }
        }
    }
    if(n > 1) ++co;
    return co;
}

void pregen(){
    res[0]=0;
    for(int i=1; i<MAX; i++)
        res[i] = res[i-1]+primeFactorize(i);
}

int main(){
    filein;
    fileout;
    sieve();
    pregen();
    int n;
    while( sc(n) != EOF ){
        printf("%d == %3d\n",n,res[n]);
    }
    return 0;
}
