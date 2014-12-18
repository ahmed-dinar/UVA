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

int x[] = {1,0,-1,0};
int y[] = {0,1,0,-1,};

int maze[MAX][MAX];
int node[MAX][MAX];
int par[100];
map<int,char>path;
vector<pr> wall[4];

bool iswall(int r,int c,int p,int q,int i){
    int a=0,b=0;
    REP(j,wall[i].size()){
        if( wall[i][j].fi == r && wall[i][j].ss==c )
            a=1;
        else if( wall[i][j].fi == p && wall[i][j].ss==q )
            b=1;
    }
    return (a && b);
}

char direction(int xx,int yy){
    if( xx==0 && yy==-1 )
        return 'N';
    else if( xx==0 && yy==1 )
        return 'S';
    else if( xx==1 && yy==0 )
        return 'E';
    else if( xx==-1 && yy==0 )
        return 'W';
}

bool invalid_move(int r,int c){
    return ( r<=0 || r>6 || c<=0 || c>6 );
}

bool nowall(int r,int c,char d){
    int e,f,g,h;
    if( d == 'N' ) e=r-1,f=c-1,g=r,h=c-1;
    else if( d == 'S' ) e=r-1,f=c,g=r,h=c;
    else if( d == 'E' ) e=r,f=c,g=r,h=c-1;
    else if( d == 'W' ) e=r-1,f=c,g=r-1,h=c-1;

    REP(i,3){
        if( iswall(e,f,g,h,i) ) return false;
    }
    return true;
}

void bfs(int sr,int sc){
    queue<pr>q;
    q.push( mp(sr,sc) );
    maze[sr][sc] = 0;
    while(!q.empty()){
        pr p = q.front(); q.pop();
        REP(i,4){
            char d = direction(x[i],y[i]);
            int r = p.fi+x[i];
            int c = p.ss+y[i];
            if( !invalid_move(r,c) && nowall(p.fi,p.ss,d) && maze[r][c] > maze[p.fi][p.ss]+1 ){
                par[node[r][c]] = node[p.fi][p.ss];
                path[node[r][c]] = d;
                maze[r][c] = maze[p.fi][p.ss]+1;
                q.push( mp(r,c) );
            }
        }
    }
}

void init(){
    int n=0;
    FOR(i,0,6)
        FOR(j,0,6)
            maze[i][j]=inf,node[i][j]=n++;

}

void read_wall(){
    int wer,wec,r,c;
    REP(i,3){
        scanf("%d %d %d %d",&r,&c,&wer,&wec);
        while(1){
            wall[i].pb( mp(r,c) );

            if(r==wer && c==wec) break;

            if(r<wer) ++r;
            else if(r>wer) --r;

            if(c<wec) ++c;
            else if(c>wec) --c;
        }
    }
}

void printpath(int v,int u){
    if(v==u){
        return ;
    }
    else{
        printpath(par[v],u);
        printf("%c",path[v]);
    }
}

int main()
{
    //filein;
    //fileout;

    int sr,sc,er,ec;
    while( scanf("%d %d",&sr,&sc) == 2 ){
        if(sr==0 &&sc==0) break;
        scanf("%d %d",&er,&ec);
        read_wall();
        init();
        bfs(sr,sc);
        printpath(node[er][ec],node[sr][sc]);
        nl;
        REP(i,3) wall[i].clear();
     }
     return 0;
}

