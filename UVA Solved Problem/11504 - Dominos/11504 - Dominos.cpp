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
#define fileout freopen("my.txt","w",stdout)

#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)

#define nFind(v,n) find(all(v),n)==v.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define all(x) x.begin(),x.end()
#define clr(x) memset(&x,0,sizeof(x))
#define mp make_pair
#define pb push_back
#define sz size()
#define cl clear()
#define em empty()
#define ss second
#define fi first

#define sc(n) scanf("%d",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define sct(n,m,v) scanf("%d %d %d",&n,&m,&v)
#define nl puts("")

#define REP(i,n) for(__typeof(n) i = 0; i < (n); ++i)
#define FOR(i,k,n) for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n) for(__typeof(n) i = (k); i < (n); ++i)
#define rREP(i,b) for (__typeof(b) i = (b); i >= 0; --i)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 100005
#define oo 2000000000
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

vci g[MAX];
vci topo;
int vis[MAX];

void topoDfs(int u){
    vis[u]=1;
    REP(i,g[u].sz)
        if(!vis[g[u][i]])
            topoDfs(g[u][i]);
    topo.pb(u);
}

void dfs(int u){
    vis[u]=1;
    REP(i,g[u].sz)
        if(!vis[g[u][i]])
            dfs(g[u][i]);
}

int main(){

    //filein;
   // fileout;

    int t,T=0,n,m,u,v;
    scanf("%d",&t);
    while(t--){
        scd(n,m);
        while(m--){
            scd(u,v);
            g[u].pb(v);
        }
        FOR(i,1,n) vis[i]=0;

        FOR(i,1,n)
            if(!vis[i])
                topoDfs(i);

        /* rREP(i,(int)topo.sz-1) cout << topo[i] << " ";
        nl;*/

        FOR(i,1,n) vis[i]=0;

        int knocked=0;
        rREP(i,(int)topo.sz-1){
            u=topo[i];
            if(!vis[u])
                ++knocked,dfs(u);
        }
        printf("%d\n",knocked);
        FOR(i,1,n) g[i].cl;
        topo.cl;
    }
    return 0;
}
