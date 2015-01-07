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

#define EPS 1e-9
#define pr pair<int,int>
#define mp make_pair
#define sz size()
#define ss second
#define fi first
#define i64 long long
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
#define nl puts("")
#define pb push_back
#define all(x) x.begin(),x.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define nFind(v,n) find(all(v),n)==v.end()
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)
#define pi acos(-1.0)
#define MAX 15
#define inf 2000000000.0
#define MOD 1000000007

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int x[]={0,1,0,-1};
int y[]={1,0,-1,0};
int r,c;
char m[MAX][MAX];
int maze[MAX][MAX];

int direction(char dir){
    if(dir=='N') return 3;
    if(dir=='S') return 1;
    if(dir=='E') return 0;
    if(dir=='W') return 2;
}

bool notExit(int rr,int cc){
    return ( rr>=0 && rr<r && cc>=0 && cc<c );
}

void bfs(int s){
    queue<pr>q;
    q.push( mp(0,s) );
    maze[0][s]=1;
    while(!q.empty()){
        pr p=q.front(); q.pop();
        int curx=p.fi,cury=p.ss;
        int i=direction(m[curx][cury]);
        int rr=curx+x[i],cc=cury+y[i];
        if( notExit(rr,cc) ){
            if(maze[rr][cc]){
                printf("%d step(s) before a loop of %d step(s)\n",maze[rr][cc]-1,maze[curx][cury]-maze[rr][cc]+1);
                break;
            }
            else{
                maze[rr][cc] = maze[curx][cury]+1;
                q.push( mp(rr,cc) );
            }
        }
        else{
            printf("%d step(s) to exit\n",maze[curx][cury]);
            break;
        }
    }
}

int main()
{
    filein;

    int s;
    while( scanf("%d %d %d\n",&r,&c,&s) == 3 ){
        if(r+c+s==0) break;
        REP(i,r)
            gets(m[i]);
        REP(i,r)
            REP(j,c)
                maze[i][j]=0;
        bfs(--s);
    }
    return 0;
}

