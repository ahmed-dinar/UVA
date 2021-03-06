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
#include<ctime>

using namespace std;

#define filein freopen("in.txt","r",stdin)
#define fileout freopen("out.txt","w",stdout)

#define cs(x) printf("Case %d: ",++x)
#define csh(x) printf("Case #%d: ",++x)
#define csn(x) printf("Case %d:\n",++x)
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
#define MAX 10005
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
template<class T>inline void IO(T &x){ char c=getchar(); T sgn=1; while(c<'0'|| c>'9'){ if(c=='-') sgn=-1; c=getchar();} x=0;while(c>='0'&&c<='9'){x=(T)(x<<1)+(x<<3)+c-'0';c=getchar();}x*=sgn;}
template<class T>T InMod(T A,T M){return bMod(A,M-2,M);}
template<class T>T todeg(T x) { return (180.0*x)/((T)PI);}
template<class T>T torad(T x) { return (x*(T)PI)/(180.0);}
template<class T>T _distance(T x1,T y1,T x2, T y2){return sqrt(sq(x1-x2)+sq(y1-y2));}

int T[MAX];
i64 dep[MAX];
int L[MAX];
int P[MAX][20];
vcp g[MAX];

void dfs(int u,int p,i64 depth,int D){
    T[u]=p;
    dep[u]=depth;
    L[u]=D;
    REP(i,g[u].sz){
        int v=g[u][i].fi;
        int w=g[u][i].ss;
        if(v!=p)
            dfs(v,u,depth+w,D+1);
    }
}

void lca_init(int n){

    REP(i,n)
        for(int j=0; (1<<j)<n; j++)
            P[i][j]=-1;

    REP(i,n)
        P[i][0]=T[i];

    for(int j=1; (1<<j)<n; j++)
        REP(i,n)
            if(P[i][j-1]!=-1)
                P[i][j]=P[P[i][j-1]][j-1];
}


int LCA(int p,int q){
    int x;
    if(L[p]<L[q]) swap(p,q);

    for(x=1; (1<<x)<=L[p]; x++);
    --x;

    for(int i=x; i>=0; i--)
        if(L[p]-(1<<i)>=L[q])
            p=P[p][i];

    if(p==q) return p;

    for(int i=x; i>=0; i--)
        if(P[p][i]!=-1 && P[p][i]!=P[q][i])
            p=P[p][i],q=P[q][i];

    return T[p];
}

int meet(int p,int k){
    int x;

    for(x=1; (1<<x)<=dep[p]; x++);
    --x;

    for(int i=x; i>=0; i--)
        if((1<<i)<=k)
            p=P[p][i],k-=(1<<i);

    return p;
}


int main(){

    filein;

    int n,u,v,t;
    i64 w;
    IO(t);
    while(t--){
        IO(n);
        REP(i,n-1){
            IO(u); IO(v); IO(w);
            --u; --v;
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
        }

        dfs(0,0,0,0);
        lca_init(n);

        while(1){

            string s;
            cin>>s;

            if(s[1]=='O') break;

            IO(u); IO(v);
            --u; --v;

            int lca=LCA(u,v);
            i64 dis=dep[u]+dep[v]-2*dep[lca];

            if(s[0]=='D')
                printf("%lld\n",dis);
            else if(s[0]=='K'){
                int x;
                IO(x);

                int z=L[u]+L[v]-2*L[lca];

                if(lca==u){
                    --x;
                    x=z-x;
                    printf("%d\n",meet(v,x)+1);
                }
                else if(lca==v){
                    int o=meet(u,x-1)+1;
                    printf("%d\n",o);
                }
                else{

                    int fa=L[u]-L[lca]+1;
                    int fb=L[v]-L[lca]+1;

                    if(fa>=x){
                        cout << meet(u,x-1)+1 << endl;
                    }
                    else{
                        int tm=x-fa;
                        x=fb-tm;
                        cout <<  meet(v,x-1)+1 << endl;
                    }

                }

            }
        }
        REP(i,n) g[i].cl;
        nl;
    }
    return 0;
}
