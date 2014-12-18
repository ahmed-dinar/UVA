#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
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
#define ss second
#define fi first
#define i64 long long
#define nl printf("\n")
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 10
#define inf 2000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int m[MAX][MAX];
int x[] = {2,2,-2,-2,1,-1,1,-1};
int y[] = {1,-1,1,-1,2,2,-2,-2};

bool valid_move(int r,int c){
    return ( (r>0&&r<=8) && (c>0&&c<=8) );
}

void init(){
    FOR(i,1,8)
        FOR(j,1,8)
            m[i][j]=inf;
}

int bfs(int sr,int sc,int r2,int c2){
    init();
    queue<pr>q;
    q.push( mp(sr,sc) );
    m[sr][sc]=0;
    while(!q.empty()){
        pr p = q.front(); q.pop();
        REP(i,8){
            int r=p.fi+x[i];
            int c=p.ss+y[i];
            if( valid_move(r,c) && m[p.fi][p.ss]+1<m[r][c] ){
                m[r][c] = m[p.fi][p.ss]+1;
                q.push( mp(r,c) );
            }
        }
    }
    return m[r2][c2];
}

int main()
{
    //filein;

    char R[4],C[4];
    while( scanf("%s %s",R,C) == 2 ){
        printf("To get from %s to %s takes %d knight moves.\n",R,C,bfs(R[1]-'0',R[0]-'a'+1,C[1]-'0',C[0]-'a'+1));
    }
    return 0;
}

