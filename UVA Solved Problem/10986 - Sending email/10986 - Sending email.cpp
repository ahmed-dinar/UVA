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

struct node
{
    int v;
    i64 w;
    node(int V,i64 W) { v=V; w=W; }
    bool operator < ( const node& p) const { return w > p.w; }
};

vector<vector<int> >g(20000);
vector<vector<i64> >cost(20000);
i64 dis[20000];

i64 djastra(int n,int src,int des){
    for(int i=0;i<n;i++) dis[i]=inf;
    priority_queue<node>q;
    q.push(node(src,0));
    dis[src]=0;
    while(!q.empty()){
        node no=q.top();
        q.pop();
        int u=no.v;
        if(u==des) return dis[des];
        int sz=g[u].size();
        for(int i=0;i<sz;i++){
            int v=g[u][i];
            if(dis[v]>dis[u]+cost[u][i]){
                dis[v]=dis[u]+cost[u][i];
                q.push(node(v,dis[v]));
            }
        }
    }
    return -1;
}

int main()
{

    //filein;

    int t;
    sc(t);
    for(int T=1;T<=t;T++){
        int n,m,src,des;
        scd(n,m);
        scd(src,des);
        for(int i=0;i<m;i++){
            int u,v;
            i64 w;
            scanf("%d %d %lld",&u,&v,&w);
            g[u].pb(v);
            g[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        i64 res = djastra(n,src,des);
        if(res == -1)
            printf("Case #%d: unreachable\n",T);
        else
            printf("Case #%d: %lld\n",T,res);

        for(int i=0;i<n;i++){
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

