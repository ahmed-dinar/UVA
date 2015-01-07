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
#define MAX 30
#define inf 2000000000
#define MOD 1000000007

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct node
{
    char u;
    int w;
    node(char u,int w) : u(u),w(w) {}
    bool operator<( const node& p ) const { return w > p.w; }
};

map<char,vector<char> >g;
map<char,char >par;
map<char,int>d;

void Dj(char src,char des){
    priority_queue<node>q;
    for(char i='A'; i<='Z';i++) d[i]=inf;
    d[src]=0;
    q.push( node(src,0) );
    while(!q.empty()){
        char u = q.top().u; q.pop();
        REP(i,g[u].sz){
            char v=g[u][i];
            if( d[v]>d[u]+1 ){
                par[v] = u;
                d[v]=d[u]+1;
                q.push( node(v,d[v]) );
            }
        }
    }
}

void printPath(char u,char v){
    if(u==v){
        printf("%c",u);
        return;
    }
    printPath(par[u],v);
    printf("%c",u);
}

int main()
{
    filein;

    int t;
    sc(t);
    while( t-- ){
        int n,m;
        scanf("%d %d",&n,&m);
        while(n--){
            string u,v;
            cin >> u >> v;
            g[u[0]].pb(v[0]);
            g[v[0]].pb(u[0]);
        }
        while(m--){
            string u,v;
            cin >> u >> v;
            Dj(u[0],v[0]);
            printPath(v[0],u[0]);
            nl;
        }
        if(t) nl;
        for(char i='A'; i<='Z';i++) g[i].clear();
    }
    return 0;
}

