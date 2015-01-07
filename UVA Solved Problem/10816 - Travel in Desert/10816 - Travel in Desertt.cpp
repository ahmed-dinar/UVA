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

#define EPS 0.0000000001
#define pr pair<int,int>
#define mp make_pair
#define sz size()
#define ss second
#define fi first
#define i64 long long
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
#define nl puts("")
#define pb push_back
#define all(x) x.begin(),x.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define nFind(v,n) find(all(v),n)==v.end()
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)
#define pi acos(-1.0)
#define MAX 105
#define inf 2000000000.0
#define MOD 1000000007

template<class T>bool isEqual(T a,T b){ return a<b+EPS; }
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct node
{
    int u;
    float w;
    node(int u,float w) : u(u),w(w) {}
    bool operator<( const node& p ) const {
        return w > p.w;
    }
};

float T[MAX][MAX];
vector<int>g[MAX];
vector<float>cost[MAX],temp[MAX];
float dist[MAX],mxtemp;
int par[MAX];

void Dijkstra(int n,int src){
    priority_queue<node>q;
    q.push( node(src,0.0) );
    dist[src]=0.0;
    while(!q.empty()){
        int u=q.top().u; q.pop();
        REP(i,g[u].sz){
            int v=g[u][i];
            float w=cost[u][i];
            float tem=temp[u][i];
            if( isEqual(tem,mxtemp) && dist[v]>dist[u]+w ){
                par[v]=u;
                dist[v]=dist[u]+w;
                q.push( node(v,dist[v]) );
            }
        }
    }
}

void printPath(int u,int v){
    if(u==v){
        printf("%d",v);
        return;
    }
    printPath(par[u],v);
    printf(" %d",u);
}

int main()
{
    filein;
    fileout;

    int n,m;
    while( scanf("%d %d",&n,&m) == 2 ){
        int src,des;
        scanf("%d %d",&src,&des);
        FOR(i,1,n)
            FOR(j,1,n)
                T[i][j]=inf,dist[i]=inf;;
        while(m--){
            int u,v;
            float w,tem;
            scanf("%d %d %f %f",&u,&v,&tem,&w);
            g[u].pb(v);
            g[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
            temp[u].pb(tem);
            temp[v].pb(tem);
            T[u][v]=min(T[u][v],tem);
            T[v][u]=min(T[v][u],tem);
        }
        FOR(k,1,n)
            FOR(i,1,n)
                FOR(j,1,n)
                    T[i][j]=min(T[i][j],max(T[i][k],T[k][j]));

        mxtemp=T[src][des];
        Dijkstra(n,src);
        printPath(des,src);
        printf("\n%.1f %.1f\n",dist[des],T[src][des]);
        FOR(i,1,n) cost[i].clear(),temp[i].clear(),g[i].clear();
    }
    return 0;
}

