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
#define scd(n,m) scanf("%d %d",&n,&m)
#define sct(n,m,v) scanf("%d %d %d",&n,&m,&v)
#define nl puts("")

#define REP(i,n) for(__typeof(n) i = 0; i < (n); ++i)
#define FOR(i,k,n) for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n) for(__typeof(n) i = (k); i < (n); ++i)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 205
#define oo 2000000000.0
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
int gurd[MAX];

int bfs(int src){
    if(g[src].sz==0) return 1;
    queue<int>q;
    q.push(src);
    int a=0,b=1;
    gurd[src]=1;
    while(!q.em){
        int u=q.front(); q.pop();
        REP(i,g[u].sz){
            int v=g[u][i];
            if(!gurd[v]){
                if(gurd[u]==1)
                    gurd[v]=2,a++;
                else
                    gurd[v]=1,b++;
                q.push(v);
            }
            else if(gurd[u]==gurd[v]) return -1;
        }
    }
    return min(a,b);
}

int main(){

   // filein;

    int t,T=0;
    scanf("%d",&t);
    while(t--){
        int n,m,u,v;
        scanf("%d %d",&n,&m);
        while(m--){
            scanf("%d %d",&u,&v);
            g[u].pb(v);
            g[v].pb(u);
        }
        memset(&gurd,0,sizeof(gurd));
        int gurds=0,impossible=0;
        REP(i,n){
            if(!gurd[i]){
                int total=bfs(i);
                if(total==-1){
                    impossible=1;
                    break;
                }
                else
                    gurds+=total;
            }
        }
        printf("%d\n",impossible ? -1 : gurds);
        REP(i,n) g[i].cl;
    }
    return 0;
}
