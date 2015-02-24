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
#define csh(x) printf("Case #%d: ",x)
#define csn(x) printf("Case %d:\n",x)
#define loc(p) puts(p)

#define nFind(v,n) find(all(v),n)==v.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define all(x) x.begin(),x.end()
#define toDigit(x) (x-'0')
#define MS(x,v) memset(&x,v,sizeof(x))
#define CL(x) memset(&x,0,sizeof(x))
#define mp make_pair
#define pb push_back
#define sz size()
#define cl clear()
#define pp pop()
#define em empty()
#define ss second
#define fi first

#define sc1(n) scanf("%d",&n)
#define sc2(n,m) scanf("%d %d",&n,&m)
#define sc3(n,m,v) scanf("%d %d %d",&n,&m,&v)
#define vanish scanf("\n")
#define nl puts("")

#define Iterate(s) for(typeof(s.begin()) it = s.begin(); it != s.end (); it++)
#define FOR(i,k,n) for(__typeof(n) i = (k); i <= (n); ++i)
#define For(i,k,n) for(__typeof(n) i = (k); i < (n); ++i)
#define ROF(i,n) for(__typeof(n) i = n; i >= 0; i--)
#define REP(i,n) for(__typeof(n) i = 0; i < (n); ++i)

#define check(n,pos) (bool)(n & (1<<(pos)))

#define EPS 1e-7
#define PI acos(-1.0)
#define MAX 105
#define oo 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef unsigned long long ui64;
typedef pair<int,int> pri;
typedef pair<i64,i64> pri64;
typedef vector<int> vci;
typedef vector<string> vcs;
typedef vector<i64> vci64;
typedef vector<pri> vcp;
typedef set<int> IS;
typedef set<string> SS;
typedef queue<int> IQ;
typedef queue<pri> PQ;

int on(int N,int pos){ int m=(N | (1<<pos)); return m; }
int off(int N,int pos){ int m=(N & ~(1<<pos)); return m; }
template<class T>string toString(T n){ stringstream ss; string num; ss<<n; ss>>num; return num; }
template<class T>bool iseq(T a,T b){return abs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p){ if(p==0) return 1; if(p&1) return n*Pow(n,p-1);  else return sq(Pow(n,p/2));}
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T bMod(T A,T P,T M){ if(P==0) return (T)1; if(!(P&1)){T temp=bMod(A,P/2); return ((temp%M)*(temp%M))%M; } return ((A%M)*(bMod(A,P-1)%M))%M; }
template<class T>T InMod(T A,T M){return bMod(A,M-2,M);}
template<class T>T todeg(T x) { return (180.0*x)/((T)PI);}
template<class T>T torad(T x) { return (x*(T)PI)/(180.0);}
template<class T>T _distance(T x1,T y1,T x2, T y2){return sqrt(sq(x1-x2)+sq(y1-y2));}

vci g[MAX];
int Back[MAX],Dis[MAX],vis[MAX],AP[MAX],d,critical_places,child;

void ArticulationPoint(int u){
    vis[u]=1;
    Dis[u]=Back[u]=++d;
    REP(i,g[u].sz){
        int v=g[u][i];
        if(!vis[v]){
            ArticulationPoint(v);
            Back[u]=min(Back[u],Back[v]);
            if(u==1){
                child++;
                if(child>1 && !AP[u]) critical_places++,AP[u]=1;
            }
            else if( Back[v]>=Dis[u] && !AP[u] ){
                critical_places++;
                AP[u]=1;
            }
        }
        else
            Back[u]=min(Back[u],Dis[v]);
    }
}

void RESET(int n){
    FOR(i,1,n) vis[i]=0,Back[i]=0,Dis[i]=0,AP[i]=0;
    d=0;
    child=0;
    critical_places=0;
}

int main(){

 //   filein;
   // fileout;

    int n;
    while( sc1(n)==1 && n ){
        vanish;
        string s;
        while(getline(cin,s)){
            if(s[0]=='0') break;
            else if(s=="") continue;
            int u=0,v=0;
            REP(i,s.sz){
                if(s[i]==' ' && v!=0){
                    if(u==0) u=v;
                    else g[u].pb(v),g[v].pb(u);
                    v=0;
                }
                else if( isdigit(s[i]) ) v=v*10+(s[i]-'0');
            }
            if(v!=0) g[u].pb(v),g[v].pb(u);
        }
        RESET(n);
        ArticulationPoint(1);
        printf("%d\n",critical_places);
        FOR(i,1,n) g[i].cl;
    }
    return 0;
}
