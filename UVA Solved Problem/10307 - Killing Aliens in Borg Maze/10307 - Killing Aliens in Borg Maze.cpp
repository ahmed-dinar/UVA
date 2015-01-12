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

int dx[]={+0,+0,-1,+1};
int dy[]={+1,-1,+0,+0};

struct G
{
    int u,v,uv;
    G(int u,int v,int uv) : u(u),v(v),uv(uv) {}
    bool operator<(const G& e) const { return uv < e.uv; }
};

pri p;
map<pri,int>node;
vcp ver;
vector<G>g;
int n,r,c,d[55][55],par[MAX];
char maze[55][55];

bool valid(int i,int j){
    return (i>=0 && i<r && j>=0 && j<c);
}

void bfs(int si,int sj){
    REP(i,r)
        REP(j,c)
            d[i][j]=oo;
    queue<int>qx,qy;
    qx.push(si);
    qy.push(sj);
    d[si][sj]=0;
    while(!qx.em){
        int px=qx.front(); qx.pop();
        int py=qy.front(); qy.pop();
        REP(i,4){
            int nx=px+dx[i];
            int ny=py+dy[i];
            if( valid(nx,ny) && maze[nx][ny]!='#' && d[nx][ny]>d[px][py]+1 ){
                d[nx][ny]=d[px][py]+1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void buildEdge(){
    REP(i,n){
        p=ver[i];
        int u=node[p];
        bfs(p.fi,p.ss);
        REP(j,n){
            p=ver[j];
            if(i!=j && d[p.fi][p.ss]!=oo){
                g.pb( G(u,node[p],d[p.fi][p.ss]) );
            }
        }
    }
}

int parent(int u){
    return (par[u]==u) ? u : par[u]=parent(par[u]);
}

int killAliens(){
    sort(all(g));
    int res=0;
    REP(i,g.sz){
        int u=parent(g[i].u);
        int v=parent(g[i].v);
        if(u!=v){
            par[u]=v;
            res+=g[i].uv;
        }
    }
    return res;
}

int main(){

    //filein;

    int t,T=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d\n",&c,&r);
        n=0;
        REP(i,r){
            gets(maze[i]);
            REP(j,c){
                if(isupper(maze[i][j])){
                    p={i,j};
                    par[n]=n;
                    node[p]=n++;
                    ver.pb(mp(i,j));
                }
            }
        }
        buildEdge();
        printf("%d\n",killAliens());
        g.cl;
        ver.cl;
    }
    return 0;
}
