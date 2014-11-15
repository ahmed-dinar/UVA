#include<bits/stdc++.h>

using namespace std;

#define pr pair<int,int>
#define mp make_pair
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
#define FOR(i,j,n) for(int i=j;i<=n; i++)
#define REP(i,n) for(int i=0;i<n; i++)
#define inf 2000000
#define MAX 5005

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


map<string,vector<string> >g;
map<string,string>par;

int bfs(string src,string des){
    queue<string>q;
    map<string,int>visited;
    q.push(src);
    visited[src]=1;
    while( !q.empty() ){
        string u=q.front();
        q.pop();
        int sz=g[u].size();
        REP(i,sz){
            string v=g[u][i];
            if( !visited[v] ){
                visited[v]=1;
                par[v] = u;
                q.push(v);
            }
        }
        if(visited[des]) return 1;
    }
    return 0;
}

int main()
{
    //filein;

    int n,nwl=0;
    string u,v;
    while(sc(n)==1){
        REP(i,n){
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        cin >> u >> v;
        if(nwl) nl;
        if(u.compare(v)==0){
            cout << u << " " << v << endl;
        }
        else if( bfs(u,v) ){
            vector<pair<string,string> >path;
            while(u.compare(v)!=0){
                path.pb(make_pair(par[v],v));
                v = par[v];
            }
            reverse(all(path));
            REP(i,path.size()){
                cout << path[i].first << " " << path[i].second << endl;
            }
        }
        else
            printf("No route\n");
        g.clear();
        par.clear();
        nwl = 1;
    }
    return 0;
}
