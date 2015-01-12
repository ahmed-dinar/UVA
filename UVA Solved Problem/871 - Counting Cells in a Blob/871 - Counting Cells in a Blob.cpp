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
#define MAX 30
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

int x[]={+0,+0,+1,-1,-1,-1,+1,+1};
int y[]={+1,-1,+0,+0,-1,+1,-1,+1};
char grid[MAX][MAX];
int r,c;
int vis[MAX][MAX];

int valid(int rr,int cc){
    return (rr>=0 && rr<r && cc>=0 && cc<c);
}

int bfs(int rr,int cc){
    memset(vis,0,sizeof(vis));
    queue<pri>q;
    q.push( mp(rr,cc) );
    int res=1;
    vis[rr][cc]=1;
    grid[rr][cc]='0';
    while(!q.em){
        int rx=q.front().fi;
        int cx=q.front().ss; q.pop();
        REP(i,8){
            int xx=rx+x[i];
            int yy=cx+y[i];
            if( valid(xx,yy) && grid[xx][yy]=='1' && !vis[xx][yy] ){
                ++res;
                vis[xx][yy]=1;
                grid[xx][yy]='0';
                q.push( mp(xx,yy) );
            }
        }
    }
    return res;
}


int main(){

    //filein;

    int t;
    scanf("%d\n",&t);
    while(t--){
        r=0;
        while(gets(grid[r])){
            if( strcmp(grid[r],"")==0 ) break;
            ++r;
        }
        c = strlen(grid[0]);
        int ans=0;
        REP(i,r)
            REP(j,c)
                if(grid[i][j]=='1')
                    ans = max(ans,bfs(i,j));

        printf("%d\n",ans);
        if(t) nl;
    }
    return 0;
}
