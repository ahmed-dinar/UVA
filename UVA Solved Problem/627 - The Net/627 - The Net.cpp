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
#define MAX 305
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
int vis[MAX];
int par[MAX];

void bfs(int u){
    queue<int>q;
    q.push(u);
    vis[u]=0;
    while(!q.em){
        int u=q.front(); q.pop();
        REP(i,g[u].sz){
            int v=g[u][i];
            if( vis[v]>vis[u]+1 ){
                vis[v]=vis[u]+1;
                par[v]=u;
                q.push(v);
            }
        }
    }
}

void printpath(int u,int v){
    if(u==v){
        printf("%d",v);
        return;
    }
    printpath(par[u],v);
    printf(" %d",u);
}

int main(){

    //filein;

    int n,T=0;
    string s;
    while( scanf("%d\n",&n) == 1 ){
        REP(i,n){
            getline(cin,s);
            for(int i=0,v=0,u;  ;i++){
                if(s[i]=='-'){
                    u=v;
                    v=0;
                }
                else if( s[i]=='\0' ){
                    g[u].pb(v);
                    v=0;
                    break;
                }
                else if( s[i]==',' ){
                    g[u].pb(v);
                    v=0;
                }
                else if( isdigit(s[i]) )
                    v=v*10+(s[i]-'0');
            }
        }
        int m;
        scanf("%d",&m);
        puts("-----");
        while(m--){
            int u,v;
            scanf("%d %d",&u,&v);
            REP(i,MAX) vis[i]=oo;
            bfs(u);
            if(vis[v]==oo)
                puts("connection impossible");
            else{
                printpath(v,u);
                nl;
            }
        }
        FOR(i,1,n) g[i].cl;
    }
    return 0;
}
