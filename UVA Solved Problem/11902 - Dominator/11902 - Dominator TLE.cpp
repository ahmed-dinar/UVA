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

#define mp make_pair
#define fr first
#define ss second
#define pf printf
#define pi acos(-1.0)
#define i64 long long
#define nl printf("\n")
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("uv.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 102
#define inf 20000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

vector<vector<int> >alp[MAX];
vector<int>g[MAX];
int vis[MAX];
int par[MAX];
int res[MAX][MAX];

void dfs(int u){
    vis[u]=1;
    int p=u;
    vector<int>path;
    path.pb(p);
    while(p!=0){
        path.pb(par[p]);
        p = par[p];
    }
    reverse(all(path));
    alp[u].pb(path);
    REP(i,g[u].size()){
        int v = g[u][i];
        if(vis[v]) continue;
        par[v]=u;
        dfs(v);
    }
    if(u!=0) vis[u]=0;
}

int main()
{
    filein;
    fileout;

    int t,T=0;
    sc(t);
    while(t--){
        int n;
        sc(n);
        REP(i,n){
            vis[i]=0;
            REP(j,n){
                int u;
                sc(u);
                if(u==1) g[i].pb(j);
                res[i][j]=0;
            }
        }
        dfs(0);
        REP(i,n){
            int sz=alp[i].size();
            REP(j,sz){
                vector<int>v = alp[i][j];
                REP(x,v.size()){
                    res[v[x]][i]++;
                }
            }
            REP(j,n){
                if( res[j][i]==sz ) res[j][i]=1;
                else res[j][i]=0;
            }
        }
        int ii=0;
        printf("Case %d:\n",++T);
        FOR(i,0,n*2){
            if(i%2 == 0){
                FOR(j,0,n*2){
                    if(j==0 || j==n*2) printf("+");
                    else printf("-");
                }
            }
            else{
                int jj=0;
                FOR(j,0,n*2){
                    if(j%2==0) printf("|");
                    else (res[ii][jj++]) ? printf("Y") : printf("N");;
                }
                g[ii].clear(),alp[ii].clear();
                ++ii;
            }
            nl;
        }
    }
    return 0;
}

