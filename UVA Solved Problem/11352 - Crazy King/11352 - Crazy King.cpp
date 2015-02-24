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
#define MAX 105
#define oo 200000000
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

int dx[]={-2,-2,+2,+2,+1,-1,+1,-1};
int dy[]={+1,-1,+1,-1,-2,-2,+2,+2};

int kx[]={+0,+0,-1,+1,+1,+1,-1,-1};
int ky[]={+1,-1,+0,+0,-1,+1,+1,-1};

int r,c,moves[MAX][MAX];
char chess[MAX][MAX];

bool valid(int rr,int cc){
    return (rr>=0 && rr<r && cc>=0 && cc<c);
}

void bfs(int rr,int cc){
    queue<int>qx,qy;
    qx.push(rr);
    qy.push(cc);
    moves[rr][cc]=0;
    while(!qx.em){
        int px=qx.front(); qx.pop();
        int py=qy.front(); qy.pop();
        REP(i,8){
            int nx=px+kx[i];
            int ny=py+ky[i];
            if( valid(nx,ny) && chess[nx][ny]!='Z' && moves[nx][ny]>moves[px][py]+1 ){
                moves[nx][ny]=moves[px][py]+1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

void Block(int px,int py){
    REP(i,8){
        int nx=px+dx[i];
        int ny=py+dy[i];
        if( valid(nx,ny) && chess[nx][ny]!='B' ) chess[nx][ny]='Z';
    }
}

int main(){

    //filein;

    int t,T=0;
    sc(t);
    while(t--){
        scd(r,c);
        vcp knights;
        pri A,B;
        REP(i,r){
            REP(j,c){
                cin>>chess[i][j];
                if(chess[i][j]=='Z') knights.pb({i,j});
                else if(chess[i][j]=='A') A={i,j};
                else if(chess[i][j]=='B') B={i,j};
                moves[i][j]=oo;
            }
        }
        REP(i,knights.sz) Block(knights[i].fi,knights[i].ss);
        bfs(A.fi,A.ss);
        (moves[B.fi][B.ss]==oo) ? puts("King Peter, you can't go now!") : printf("Minimal possible length of a trip is %d\n",moves[B.fi][B.ss]);
    }
    return 0;
}
