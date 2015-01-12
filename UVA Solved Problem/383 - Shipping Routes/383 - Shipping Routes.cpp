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
#define em empty()
#define ss second
#define fi first

#define sc(n) scanf("%d",&n)
#define nl puts("")

#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 40
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

map<string,int>id;
int d[MAX];
vci g[MAX];

void bfs(int n,int src,int des,int p){
    FOR(i,1,n) d[i]=oo;
    queue<int>q;
    q.push(src);
    d[src]=0;
    while(!q.em){
        int u=q.front(); q.pop();
        REP(i,g[u].sz){
            int v=g[u][i];
            if(d[v]>d[u]+1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    if(d[des]==oo)
        printf("NO SHIPMENT POSSIBLE\n");
    else
        printf("$%d\n",p*d[des]*100);
}

int main(){

    //filein;

    int t,T=0;
    string u,v;
    scanf("%d",&t);
    puts("SHIPPING ROUTES OUTPUT\n");
    while(t--){
        int n,m,p;
        scanf("%d %d %d",&n,&m,&p);
        REP(i,n){
            cin>>u;
            id[u]=i+1;
        }
        while(m--){
            cin>>u>>v;
            g[id[u]].pb(id[v]);
            g[id[v]].pb(id[u]);
        }
        printf("DATA SET  %d\n\n",++T);
        while(p--){
            cin>>m>>u>>v;
            bfs(n,id[u],id[v],m);
        }
        nl;
        FOR(i,1,n) g[i].cl;
        id.cl;
    }
    puts("END OF OUTPUT");
    return 0;
}
