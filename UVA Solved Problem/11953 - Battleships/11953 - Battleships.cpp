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
#define ss second
#define fi first

#define sc(n) scanf("%d",&n)
#define nl puts("")

#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 105
#define oo 2000000000
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

int x[]={1,0,-1,0};
int y[]={0,1,0,-1};
char grid[MAX][MAX];
int n;

bool invalid(int rr,int cc){
    return (rr<0 || rr>=n || cc<0 || cc>=n);
}

void bfs(int rr,int cc){
    queue<pri>q;
    q.push(mp(rr,cc));
    grid[rr][cc]='.';
    while(!q.empty()){
        int rx=q.front().fi;
        int cy=q.front().ss;
        q.pop();
        REP(i,4){
            int xx=rx+x[i];
            int yy=cy+y[i];
            if( !invalid(xx,yy) && grid[xx][yy]!='.' ){
                grid[xx][yy]='.';
                q.push( mp(xx,yy) );
            }
        }
    }
}

int main(){

    //filein;

    int t,T=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n);
        REP(i,n)
           gets(grid[i]);

        int ships=0;
        REP(i,n){
            REP(j,n){
                if(grid[i][j]=='x'){
                    ++ships;
                    bfs(i,j);
                }
            }
        }
        printf("Case %d: %d\n",++T,ships);
    }
    return 0;
}
