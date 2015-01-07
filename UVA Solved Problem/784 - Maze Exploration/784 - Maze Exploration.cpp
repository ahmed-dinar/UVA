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

#define EPS 0.0000000001
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
#define MAX 90
#define inf 2000000000.0
#define MOD 1000000007

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int x[]={1,0,-1,0};
int y[]={0,1,0,-1};
char maze[MAX][MAX];

void paint(int rr,int cc){
    queue<pr>q;
    q.push(mp(rr,cc));
    maze[rr][cc]='#';
    while(!q.empty()){
        int r=q.front().fi;
        int c=q.front().ss;
        q.pop();
        REP(i,4){
            int xx=r+x[i];
            int yy=c+y[i];
            if(maze[xx][yy]==' '){
                maze[xx][yy]='#';
                q.push( mp(xx,yy) );
            }
        }
    }
}

int main()
{
    filein;

    int t;
    scanf("%d\n",&t);
    while( t-- ){
        int r=0;
        while(gets(maze[r])){
            if(maze[r][0]=='_') break;
            ++r;
        }
        int sx=-1,sy;
        REP(i,r){
            for(int j=0;maze[i][j]!='\0'; j++){
                if(maze[i][j]=='*'){
                    sx=i;
                    sy=j;
                    break;
                }
            }
            if(sx!=-1) break;
        }
        paint(sx,sy);
        REP(i,r)
            printf("%s\n",maze[i]);
        printf("%s\n",maze[r]);
    }
    return 0;
}

