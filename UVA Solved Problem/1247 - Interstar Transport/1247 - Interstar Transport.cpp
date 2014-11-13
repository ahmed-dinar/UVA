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


int g[110][110];
int next[110][110];
map<char,int>id;
map<int,char>r;

void floyd_warshall(int n){
    for(int k=1;k<=n; k++)
        for(int i=1;i<=n; i++)
            for(int j=1;j<=n; j++)
                if( g[i][j]>(g[i][k]+g[k][j]) )
                    g[i][j]=(g[i][k]+g[k][j]),next[i][j]=next[i][k];

}

void Set(int n){
    for(int i=1;i<=n; i++)
        for(int j=1;j<=n; j++)
            g[i][j]=inf,next[i][j]=j;
}

int main()
{
    //filein;

    int n,m,query;
    while( scanf("%d %d",&n,&m) == 2 ){
        int index=1;
        Set(n);
        for(int i=1;i<=m;i++){
            int w;
            char U,V;
            sc("\n");
            scanf("%c %c %d",&U,&V,&w);
            if(id[U]==0) id[U]=index++;
            if(id[V]==0) id[V]=index++;
            g[id[U]][id[V]] = w;
            g[id[V]][id[U]] = w;
            r[id[U]]=U;
            r[id[V]]=V;
        }
        floyd_warshall(n);
        sc(query);
        while(query--){
            char u,v;
            sc("\n");
            scanf("%c %c",&u,&v);
            int p = id[u];
            int q=id[v];
            printf("%c",u);
            while( p!=q ){
                p = next[p][q];
                printf(" %c",r[p]);
            }
            nl;
        }
    }
    return 0;
}

