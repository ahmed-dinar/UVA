#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
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

#define filein freopen("in.txt","r",stdin)
#define fileout freopen("out.txt","w",stdout)

#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)

#define nFind(v,n) find(all(v),n)==v.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define sz size()
#define cl clear()
#define ss second
#define fi first

#define sc(n) scanf("%d",&n)
#define nl puts("")

#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 1005
#define oo 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<i64> vcll;
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct node
{
    int u,v;
    i64 w;
    node( int u,int v,i64 w) : u(u),v(v),w(w) {}
    bool operator < ( const node& p) const { return w < p.w; }
};

vector<node>g;
int par[MAX];
int incycle[MAX];
vcll cycles;

int parent(int x){
    return (par[x]==x) ? x : par[x]=parent(par[x]);
}

void mst(int n,int m){
    REP(i,m)
        incycle[i]=1;
    FOR(i,1,n)
        par[i]=i;
    sort(all(g));
    int szz=(int)g.sz;
    int nodes=0;
    REP(i,szz){
        int u=parent(g[i].u);
        int v=parent(g[i].v);
        if(u!=v){
            par[u]=v;
            incycle[i]=0;
            nodes++;
        }
        if(nodes == n-1) return;
    }
}

void checkCycle(int n,int m){
    REP(i,m)
        if(incycle[i])
            cycles.pb(g[i].w);
}

int main()
{
    //filein;
    //fileout;

    int n,m;
    while( scanf("%d %d",&n,&m) == 2 ){
        if(n+m==0) break;
        REP(i,m){
            int u,v;
            i64 w;
            scanf("%d %d %lld",&u,&v,&w);
            g.pb( node(++u,++v,w) );
        }
        mst(n,m);
        checkCycle(n,m);
        int k=cycles.sz;
        if(k == 0)
            printf("forest\n");
        else{
            sort(all(cycles));
            REP(i,k){
                printf("%lld",cycles[i]);
                if(i<k-1) printf(" ");
            }
            nl;
        }
        cycles.cl;
        g.cl;
    }
    return 0;
}
