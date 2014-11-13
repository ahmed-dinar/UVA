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


struct res
{
    int u;
    string name;
    res( int U,string N ) { u=U; name=N; }
    bool operator < ( const res& p ) const {
        if( u == p.u )
            return name >  p.name ;
        else
            return u > p.u;
    }
};

int g[23][23];
map<int,string>id;

void floyd_warshall(int n){
    for(int k=1;k<=n; k++)
        for(int i=1;i<=n; i++)
            for(int j=1;j<=n; j++)
                if( g[i][j]>(g[i][k]+g[k][j]) )
                    g[i][j]=g[i][k]+g[k][j];

}

void Set(int n){
    for(int i=1;i<=n; i++)
        for(int j=1;j<=n; j++)
            g[i][j]=inf;
}

int main()
{


    int T=0,t;
    int n,m;
    while( scd(n,m) == 2 ){
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++) cin >> id[i];
        Set(n);
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            g[u][v]=w;
            g[v][u]=w;
        }
        floyd_warshall(n);
        priority_queue<res>q;
        for(int i=1;i<=n;i++){
            int tot=0;
            for(int j=1;j<=n;j++){
                if( g[i][j] == inf || i==j ) continue;
                tot += g[i][j];
            }
            q.push( res( tot,id[i] ) );
        }
        printf("Case #%d : %s\n",++T,q.top().name.c_str());
    }
    return 0;
}
