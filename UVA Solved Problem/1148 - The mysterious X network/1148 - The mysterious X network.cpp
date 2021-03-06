#include<bits/stdc++.h>

using namespace std;

#define pf(x) printf("%d",x)
#define pfd(x,y) printf("%d %d",x,y)
#define pfl(x) printf("%ld",x)
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
#define sct(n,m,w) scanf("%d %d %d",&n,&m,&w)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define FOR(i,n) for(int i=0;i<n; i++)
#define inf 100000000
#define MAX 100005

bool isUpper(char ch){ if( ch>='A' && ch<='Z' ) return true; return false; }
bool isLower(char ch){ if( ch>='a' && ch<='z') return true; return false;}
bool isLetter(char ch){ if( ch>='A' && ch<='Z' || ch>='a' && ch<='z') return true; return false; }
bool isDigit(char ch){ if( ch>='0' && ch<='9') return true; return false; }
char toLower(char ch){ if (isUpper(ch)) return (ch+32); return ch; }
char toUpper(char ch){ if (isLower(ch)) return (ch-32); return ch; }

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }

vector<int>g[MAX];

int bfs(int src,int des,int n){
    queue<int>q;
    int visited[n+1];
    int far[n+1];
    for(int i=0;i<n;i++) visited[i]=0,far[i]=0;
    q.push(src);
    visited[src]=1;
    while( !q.empty() ){
        int u=q.front();
        q.pop();
        int sz=g[u].size();
        for(int i=0;i<sz;i++){
            int v=g[u][i];
            if( !visited[v] ){
                visited[v]=1;
                far[v] = far[u]+1;
                q.push(v);
            }
        }
        if(far[des]) return (far[des]-1);
    }
}

int main()
{
    //filein;

    int t,T=0;
    sc(t);
    while(t--){
        int n,m,u,v;
        sc(n);
        for(int i=0;i<n;i++){
            scd(u,m);
            while( m-- ){
                sc(v);
                g[u].pb(v);
            }
        }
        scd(u,v);
        if(T) nl;
        printf("%d %d %d\n",u,v,bfs(u,v,n));
        for(int i=0;i<n;i++) g[i].clear();
        T=1;
    }
    return 0;
}
