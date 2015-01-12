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
#define MAX 110
#define oo 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<string> vcs;
typedef vector<int> vci;
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }


map<char,vector<char> >g;
map<char,char >vis;
int tot;

void dfs(char u){
    tot++;
    vis[u]=1;
    REP(i,g[u].sz){
        char v=g[u][i];
        if(!vis[v])
            dfs(v);
    }
}

int main(){

    //filein;

    int t,T=0;
    scanf("%d\n",&t);
    string mx,s;
    while( t-- ){
        getline(cin,mx);
        set<char>nod;
        set<char>::iterator it;
        for(char i='A'; i<=mx[0]; i++) nod.insert(i);
        while( getline(cin,s)  ){
            if(s=="") break;
            g[s[0]].pb(s[1]);
            g[s[1]].pb(s[0]);
        }
        int graph=0;
        tot=0;
        for(it=nod.begin(); it!=nod.end(); it++){
            char u=*it;
            if(!vis[u]){
                dfs(u);
                graph++;
            }
        }
        printf("%d\n",graph);
        for(it=nod.begin(); it!=nod.end(); it++){
            char u=*it;
            g[u].cl;
        }
        vis.cl;
        if(t) nl;
    }
    return 0;
}
