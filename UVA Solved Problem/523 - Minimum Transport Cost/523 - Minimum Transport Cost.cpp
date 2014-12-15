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
#define MAX 10005
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
    bool operator<( const node& p) const { return p.w < w; }
};

vector<edge>g[MAX];
map<int,int>tax;
map<int,int>path;
map<int,int>d;

void dijsktra(int n,int src,int des){
    FOR(i,1,n) d[i]=inf;
    priority_queue<node>q;
    q.push( node(src,0) );
    d[src]=0;
    while(!q.empty()){
        int u = q.top().u;
        q.pop();
        int sz=g[u].size();
        REP(i,sz){
            int v = g[u][i].v;
            int w = g[u][i].w;
            if( v==des && d[v] > d[u]+w  ){
                path[v]= u;
                d[v] = d[u]+w;
                q.push( node(v,d[v]) );
            }
            else if( v!=des && d[v] > d[u]+w+tax[v]  ){
                path[v]= u;
                d[v] = d[u]+w+tax[v];
                q.push( node(v,d[v]) );
            }
        }
    }
}

int main()
{
    filein;
   // fileout;

    int t;
    scanf("%d\n",&t);
    while(t--){
        string s;
        getline(cin,s);
        istringstream ss(s);
        string num;
        int n=0,u,v;
        while( getline(ss,num,' ') ){
            ++n;
            int N = atoi(num.c_str());
            if(N!=-1 && n!=1) g[1].pb( edge(n,N) );
        }
        FOR(i,2,n){
            FOR(j,1,n){
                sc(u);
                if(u!=-1 && i!=j ) g[i].pb( edge(j,u) );
            }
        }
        FOR(i,1,n) sc(tax[i]);
        scanf("\n");
        int blank=0;
        while( getline(cin,s) ){
            if(s.compare("")==0) break;
            istringstream ss(s);
            getline(ss,num,' ');
            u = atoi(num.c_str());
            getline(ss,num,' ');
            v = atoi(num.c_str());
            dijsktra(n,u,v);
            if(blank) nl;
            printf("From %d to %d :\n",u,v);
            printf("Path: ");
            vector<int>route;
            int k=v;
            route.pb(k);
            while(k!=u){
                k = path[k];
                route.pb(k);
            }
            for(int x=route.size()-1;x>=0;x--){
                printf("%d",route[x]);
                if(x>0) printf("-->");
            }
            nl;
            printf("Total cost : %d\n",d[v]);
            blank=1;
        }
        if(t) nl;
        FOR(i,1,n) g[i].clear();
    }
    return 0;
}

