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
#define ss second
#define fi first

#define sc(n) scanf("%d",&n)
#define nl puts("")

#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 800
#define inf 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<int> vci;
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
    double w;
    node( int u,int v,double w) : u(u),v(v),w(w) {}
    bool operator < ( const node& p) const { return w < p.w; }
};

vector<node>g;
int par[MAX];
map<int,pri> id;
map<int,map<int,int> >connected;

int parent(int x){
    return (par[x]==x) ? x : par[x]=parent(par[x]);
}

double mst(int n,int nd){
    sort(all(g));
    int szz=(int)g.sz;
    int nodes=nd;
    double res=0.00;
    REP(i,szz){
        int u=parent(g[i].u);
        int v=parent(g[i].v);
        if(!connected[g[i].u][g[i].v] && u!=v){
            par[u]=v;
            res += g[i].w;
            nodes++;
        }
        if(nodes == n) return res;
    }
    return res;
}

double distance_(int a,int b){
    double x = (id[a].fi-id[b].fi);
    double y = (id[a].ss-id[b].ss);
    return (double)sqrt( (x*x)+(y*y) );
}

int main()
{
    //filein;
    //fileout;

    int n,m;
    while( scanf("%d",&n) == 1 ){
        FOR(i,1,n){
            int x,y;
            scanf("%d %d",&x,&y);
            id[i] = make_pair(x,y);
        }
        scanf("%d",&m);
        int exists=0;
        FOR(i,1,n)
            par[i]=i;
        REP(i,m){
            int u,v;
            scanf("%d %d",&u,&v);
            double dis = distance_(u,v);
            int pu=parent(u);
            int pv=parent(v);
            if(pu!=pv){
                par[pu]=pv;
                exists++;
            }
            connected[u][v]=1;
            connected[v][u]=1;
            g.pb( node(u,v,dis) );
        }
        if(exists>=n){
            printf("0.00\n");
        }
        else{
            FOR(i,1,n){
                FOR(j,i+1,n){
                    if(!connected[i][j]){
                        double dis = distance_(i,j);
                        g.pb( node(i,j,dis) );
                    }
                }
            }
            printf("%.2lf\n",mst(n,exists));
        }
        g.clear();
        id.clear();
        connected.clear();
    }
    return 0;
}
