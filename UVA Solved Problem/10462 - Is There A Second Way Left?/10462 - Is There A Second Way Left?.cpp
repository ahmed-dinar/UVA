#include<bits/stdc++.h>

using namespace std;

#define pf(x) printf("%d",x)
#define pfd(x,y) printf("%d %d",x,y)
#define pfl(x) printf("%ld",x)
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
#define sct(n,m,w) scanf("%d %d %d",&n,&m,&w)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define FOR(i,n) for(int i=0;i<n; i++)
#define inf 100000000
#define MAX 110

bool isUpper(char ch){ if( ch>='A' && ch<='Z' ) return true; return false; }
bool isLower(char ch){ if( ch>='a' && ch<='z') return true; return false;}
bool isLetter(char ch){ if( ch>='A' && ch<='Z' || ch>='a' && ch<='z') return true; return false; }
bool isDigit(char ch){ if( ch>='0' && ch<='9') return true; return false; }
char toLower(char ch){ if (isUpper(ch)) return (ch+32); return ch; }
char toUpper(char ch){ if (isLower(ch)) return (ch-32); return ch; }

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }

struct node
{
    int u,v,w;
    node(int U,int V,int W) { u=U; v=V; w=W; }
    bool operator < ( const node& p) const { return w < p.w; }
};

vector<node>g;
int par[MAX];
vector<int>edges;

int parent(int x){
    return (par[x]==x) ? x : par[x]=parent(par[x]);
}

int mst(int n,int indx){
    for(int i=0;i<=n;i++) par[i]=i;

    int sz=(int)g.size();
    int nodes=0;
    int res=0;
    for(int i=0;i<sz;i++){
        if( i == indx ) continue;
        int u=g[i].u;
        int v=g[i].v;
        if( u==v ) continue;
        int pu=parent(u);
        int pv=parent(v);
        if(pu!=pv){
            if(indx==-1) edges.pb(i);

            par[pu]=pv;
            res += g[i].w;
            nodes++;
            if( nodes == n-1 ) return res;
        }
    }
    return -1;
}

int main()
{
    //filein;

    int t,Tc=0;
    sc(t);
    while(t--){
        int n,m;
        scd(n,m);
        for(int i=0;i<m;i++){
            int u,v,w;
            sc(u),sc(v),sc(w);
            g.pb( node(u,v,w) );
        }
        printf("Case #%d : ",++Tc);
        if( m==0 ){
            if( n == 1 )
                printf("No second way\n");
            else
                printf("No way\n");
            continue;
        }
        else if( n==1 ){
            printf("No second way\n");
        }
        else{
            sort( all(g) );
            int best = mst(n,-1);
            if( best == -1 ){
                printf("No way\n");
            }
            else{
                int sz=edges.size();
                int secondBest = inf;
                int p = -1;
                bool isc=false;
                for(int i=0;i<sz;i++){
                    p = mst(n,edges[i]);
                    if( p != -1 ){
                        isc = true;
                        secondBest = min(secondBest,p);
                    }
                }
                if( !isc )
                    printf("No second way\n");
                else
                    printf("%d\n",secondBest);
            }
        }
        g.clear();
        edges.clear();
    }
    return 0;
}
