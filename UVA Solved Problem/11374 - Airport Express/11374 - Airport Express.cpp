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
#define MAX 505
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct edge
{
    int v,w;
    edge(int v,int w) { this->v=v; this->w=w; }
};

struct node
{
    int u,w;
    node(int u,int w) { this->u=u; this->w=w; }
    bool operator<( const node& p) const { return w > p.w; }
};

vector<edge>g[MAX];
int path[MAX];
int nu,nv,nw,Commercial;

int Dijkstra(int n,int src,int des){
    int d[n+1];
    FOR(i,1,n) d[i]=inf;
    priority_queue<node>q;
    q.push( node(src,0) );
    d[src]=0;
    while(!q.empty()){
        int u = q.top().u; q.pop();
        int sz=g[u].size();
        REP(i,sz){
            int v = g[u][i].v;
            int w = g[u][i].w;
            if( d[v]>d[u]+w ){
                d[v] = d[u]+w;
                path[v] = u;
                q.push( node(v,d[v]) );
            }
        }
        if(nu==u && d[nv]>d[nu]+nw){
            d[nv] = d[nu]+nw;
            path[nv] = nu;
            Commercial = nu;
            q.push( node(nv,d[nv]) );
        }
        else if(nv==u && d[nu]>d[nv]+nw){
            d[nu] = d[nv]+nw;
            path[nu] = nv;
            Commercial = nv;
            q.push( node(nu,d[nu]) );
        }
    }
    return d[des];
}

int main()
{
    filein;
    //fileout;

    int n,src,des,blank=0;
    while( scanf("%d %d %d",&n,&src,&des) == 3 ){
        int m;
        sc(m);
        while(m--){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            g[u].pb( edge(v,w) );
            g[v].pb( edge(u,w) );
        }
        nu=-1;nv=-1;nw=-1;
        Commercial=-1;
        int com=Commercial;
        int res = Dijkstra(n,src,des);
        vector<int>route;
        int k = des;
        if(res!=inf){
            route.pb(k);
            while( k!=src ){
                k = path[k];
                route.pb(k);
            }
        }
        sc(m);
        while(m--){
            scanf("%d %d %d",&nu,&nv,&nw);
            int r = Dijkstra(n,src,des);
            if( r<res ){
                if(r!=inf){
                    route.clear();
                    k = des;
                    route.pb(k);
                    while( k!=src ){
                        k = path[k];
                        route.pb(k);
                    }
                }
                res = r;
                com = Commercial;
            }
        }
        if(blank) nl;
        m = route.size()-1;
        for(int i=m;i>=0; i--){
            printf("%d",route[i]);
            if(i>0) printf(" ");
        }
        nl;
        (com == -1 ) ? printf("Ticket Not Used\n") : printf("%d\n",com);
        printf("%d\n",res);
        FOR(i,1,n) g[i].clear();
        blank=1;
    }
    return 0;
}

