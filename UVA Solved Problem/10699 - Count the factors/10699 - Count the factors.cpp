#include<bits/stdc++.h>

using namespace std;

#define pf(x) printf("%d",x)
#define pfd(x,y) printf("%d %d",x,y)
#define pfl(x) printf("%ld",x)
#define pfll(x) printf("%lld",x)
#define pfllu(x)
#define nl printf("\n")
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scll(n) scanf("%lld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define inf 100000
#define MAX 1000005
#define MOD 4294967296

bool isUpper(char ch){ return ( ch>='A' && ch<='Z' ) ?  true :  false; }
bool isLower(char ch){ return ( ch>='a' && ch<='z')  ?  true :  false; }
bool isLetter(char ch){ return ( ch>='A' && ch<='Z' || ch>='a' && ch<='z') ?  true :  false; }
bool isDigit(char ch){ return ( ch>='0' && ch<='9') ?  true :  false; }
char toLower(char ch){ return (isUpper(ch)) ? (ch+32) : ch; }
char toUpper(char ch){ return (isLower(ch)) ? (ch-32) : ch; }

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { return (n>=p) ? n : p; }
template<class T>T ABS(T n) { return (n<0) ?  (-n) :  n; }

long prime[200];
long dp[MAX];

void sieve(){
    long bol[1011]={0};
    long ik,jk;
    prime[0] = 2;
    for( ik = 3; ik <= sqrt(1011); ik+=2 )
        if( bol[ik] == 0)
            for( jk = ik*ik; jk <= 1011; jk += 2*ik )
                 bol[jk] = 1;

    for( ik = 3,jk=1; ik <= 1011; ik+=2 )
        if( bol[ik] == 0)
            prime[jk++] = ik;
}

long primeFactorize(long pn ){
    long i=0,sqrtPn,tmp,co=0;
    sqrtPn =(int)(sqrt(pn));
    for( i = 0; prime[i] <= sqrtPn; i++ ){
        if( pn % prime[i] == 0 ){
            co++;
            while( pn % prime[i] == 0 ){
                pn /= prime[i];
            }
        }
    }
    if(pn > 1) co++;

    return co;
}

void pregen(){
    for(long k=1; k<=1000000; k++)
        dp[k]=primeFactorize(k);
}

int main()
{
    sieve();
    pregen();
    long num;
    while( scanf("%ld",&num) && num != 0 ){
        printf("%ld : %ld\n",num,dp[num]);
    }
    return 0;
}
