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
#define MAX 30
#define oo 200000000
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

struct cyclist
{
    int r,c,color,dir,w;
    cyclist(int r,int c,int color,int dir,int w) : r(r),c(c),color(color),dir(dir),w(w) {}
};

        //N  E   S  W
int dx[]={-1,+0,+1,+0};
int dy[]={+0,-1,+0,+1};
int r,c,ti,tj,vis[MAX][MAX][4][5];
char grids[MAX][MAX];

bool valid(int rr,int cc){
    return (rr>=0 && rr<r && cc>=0 && cc<c);
}

int turn(int curd,char turd){
    if(turd=='L'){
        if(curd==0) return 3;
        if(curd==1) return 0;
        if(curd==2) return 1;
        if(curd==3) return 2;
    }
    if(turd=='R'){
        if(curd==0) return 1;
        if(curd==1) return 2;
        if(curd==2) return 3;
        if(curd==3) return 0;
    }
}

int bfs(int rr,int cc){
    queue<cyclist>q;
    q.push( cyclist(rr,cc,0,0,0) );
    vis[rr][cc][0][0]=1;
    while(!q.em){

        cyclist cy=q.front();
        q.pop();

        int px=cy.r;
        int py=cy.c;
        int color=cy.color;
        int dir=cy.dir;
        int w=cy.w;

        if( px==ti && py==tj && color==0 ) return w;

        int nx=px+dx[dir];
        int ny=py+dy[dir];
        int ncolor=(color+1)%5;
        if( valid(nx,ny) && grids[nx][ny]!='#'  ){
            if( !vis[nx][ny][dir][ncolor] ){
                vis[nx][ny][dir][ncolor]=1;
                q.push( cyclist(nx,ny,ncolor,dir,w+1) );
            }
        }

        int ndir=turn(dir,'L');
        nx=px;
        ny=py;
        ncolor=color;
        if( !vis[nx][ny][ndir][ncolor] ){
            vis[nx][ny][ndir][ncolor]=1;
            q.push( cyclist(nx,ny,ncolor,ndir,w+1) );
        }
        ndir=turn(dir,'R');
        if( !vis[nx][ny][ndir][ncolor] ){
            vis[nx][ny][ndir][ncolor]=1;
            q.push( cyclist(nx,ny,ncolor,ndir,w+1) );
        }

    }
    return -1;
}

int main(){

   // filein;

    int T=0,si,sj;
    while( scanf("%d %d",&r,&c)==2 ){
        if(r+c==0) break;
        REP(i,r){
            REP(j,c){
                cin>>grids[i][j];
                if(grids[i][j]=='S')
                    si=i,sj=j;
                else if(grids[i][j]=='T')
                    ti=i,tj=j;
            }
        }
        memset(&vis,0,sizeof(vis));
        int res=bfs(si,sj);

        if(T) nl;
        printf("Case #%d\n",++T);
        if(res==-1)
            puts("destination not reachable");
        else
            printf("minimum time = %d sec\n",res);
    }
    return 0;
}
