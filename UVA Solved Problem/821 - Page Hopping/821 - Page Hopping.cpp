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
#define MAX 50001
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


float g[102][102];

void floyd_warshall(int n){
    for(int k=1;k<=n; k++)
        for(int i=1;i<=n; i++)
            for(int j=1;j<=n; j++)
                if(g[i][j]>(g[i][k]+g[k][j]))
                    g[i][j]=(g[i][k]+g[k][j]);
}

void Set(){
    for(int i=1;i<=100; i++)
        for(int j=1;j<=100; j++)
            g[i][j]=inf;
}

int main()
{
    filein;

    int a,b,n,T=0;
    while( scd(a,b) == 2 ){
        if(a==0&&b==0) break;
        Set();
        g[a][b]=1;
        n = a;
        n = Max(n,b);
        while( scd(a,b) == 2 ){
            if(a==0&&b==0) break;
            g[a][b]=1;
            n = Max(n,a);
            n = Max(n,b);
        }
        floyd_warshall(n);
        float res=0,pairs=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)continue;
                if(g[i][j]!=inf){
                    res += g[i][j];
                    pairs++;
                }
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",++T,(res/pairs));
    }
    return 0;
}

