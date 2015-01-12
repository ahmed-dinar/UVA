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
#define MAX 110
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

int maze[MAX][MAX],r,c;
i64 vis[MAX][MAX];

int invalid(int rr,int cc){
    return( rr>r || cc>c || maze[rr][cc] );
}

i64 paths(int e,int f){

    if( invalid(e,f) ) return 0;

    if( e==r && f==c ) return 1;

    if( vis[e][f]!=-1 ) return vis[e][f];

    return vis[e][f]=paths(e+1,f)+paths(e,f+1);
}

int main(){


    int n;
    while( scanf("%d %d",&r,&c) == 2 ){
        if(r+c==0) break;
        FOR(i,0,r)
            FOR(j,0,c)
                maze[i][j]=0,vis[i][j]=-1;

        scanf("%d",&n);
        while(n--){
            int p,q;
            scanf("%d %d",&p,&q);
            maze[p][q]=1;
        }
        i64 k=paths(0,0);
        if( k==0 )
            puts("There is no path.");
        else if(k==1)
            puts("There is one path from Little Red Riding Hood's house to her grandmother's house.");
        else
            printf("There are %lld paths from Little Red Riding Hood's house to her grandmother's house.\n",k);
    }
    return 0;
}
