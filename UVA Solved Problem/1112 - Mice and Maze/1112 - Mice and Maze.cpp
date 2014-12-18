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
#define MAX 105
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct edge
{
    int v,w;
    edge(int v,int w){ this->v=v; this->w=w; }
};

struct node
{
    int u,w;
    node(int u,int w){ this->u=u; this->w=w; }
    bool operator<( const node& temp ) const { return w>temp.w; }
};

vector<edge>g[MAX];
int d[MAX];

int Dijkstra(int n,int src,int des){
    FOR(i,1,n) d[i]=inf;
    priority_queue<node>q;
    q.push( node(src,0) );
    d[src]=0;
    while(!q.empty()){
        int u=q.top().u;
        q.pop();
        REP(i,g[u].size()){
            int v=g[u][i].v;
            int w=g[u][i].w;
            if( d[v]>d[u]+w ){
                d[v] = d[u]+w;
                q.push( node(v,d[v]) );
            }
        }
    }
    return d[des];
}

int main()
{
    filein;
   // fileout;

    int t;
    sc(t);
    while(t--){
        int n,ex,time,m;
        scanf("%d %d %d",&n,&ex,&time);
        sc(m);
        while(m--){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            g[u].pb( edge(v,w) );
        }
        int mice=0;
        FOR(i,1,n){
            int r = Dijkstra(n,i,ex);
            if(r<=time) ++mice;
        }
        printf("%d\n",mice);
        if(t) puts("");
        FOR(i,1,n) g[i].clear();
    }
    return 0;
}

