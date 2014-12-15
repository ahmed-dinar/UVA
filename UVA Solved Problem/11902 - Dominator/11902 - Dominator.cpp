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
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 102
#define inf 20000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

vector<int>g[MAX];
int vis[MAX];
int res[MAX][MAX];
int reach[MAX];

void dfs(int u,int des){
    if(des==-1) reach[u]=1;
    if(u==des) return;
    vis[u]=1;
    REP(i,g[u].size()){
        int v = g[u][i];
        if( vis[v] ) continue;
        dfs(v,des);
    }
}

int main()
{
    filein;
    //fileout;

    int t,T=0;
    sc(t);
    while(t--){
        int n;
        sc(n);
        REP(i,n){
            reach[i]=0;
            vis[i]=0;
            REP(j,n){
                int u;
                sc(u);
                if(u) g[i].pb(j);
            }
        }
        dfs(0,-1);
        REP(i,n){
            REP(j,n) vis[j]=0;
            dfs(0,i);
            REP(j,n)
                if(!vis[j] && reach[j])
                    res[i][j]=1;
                else
                    res[i][j]=0;
        }
        printf("Case %d:\n",++T);
        REP(i,n){
            printf("+");
            REP(j,n*2-1)
                printf("-");
            printf("+\n");
            REP(j,n)
                if( res[i][j] )
                    printf("|Y");
                else
                    printf("|N");
            printf("|\n");
            g[i].clear();
        }
        printf("+");
        REP(i,n*2-1) printf("-");
        printf("+\n");
    }
    return 0;
}

