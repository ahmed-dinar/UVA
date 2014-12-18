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

#define eps 0.0000000001
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
#define fileout freopen("out.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 35
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct cell
{
    int v,level,r,c;
    cell(int v,int level,int r,int c) { this->v=v; this->level=level; this->r=r; this->c=c; }
    bool operator<( const cell& p ) const { return v > p.v; }
};

int r,c,lv;
int x[]={0,0,-1,0,1,0};
int y[]={0,0,0,-1,0,1};
int z[]={1,-1,0,0,0,0};
char m[MAX][MAX][MAX];
int d[MAX][MAX][MAX];

bool valid_move(int L,int R,int C){
    if( R<0 || R>=r  || C<0 || C>=c || L<0 || L>=lv )
        return false;
    else if( m[L][R][C] == '#' )
        return false;
    else
        return true;
}

int dungeon(int sl,int sr,int sc,int el,int er,int ec){
    priority_queue<cell>q;
    q.push( cell(0,sl,sr,sc) );
    d[sl][sr][sc]=0;
    while(!q.empty()){
        cell ce = q.top(); q.pop();
        int v = ce.v;
        int ll = ce.level;
        int rr = ce.r;
        int cc = ce.c;
        REP(i,6){
            int Ll = ll+z[i];
            int Rr = rr+x[i];
            int Cc = cc+y[i];
            if( valid_move(Ll,Rr,Cc) ){
                if( d[Ll][Rr][Cc] > v+1 ){
                    d[Ll][Rr][Cc] = v+1;
                    q.push( cell(d[Ll][Rr][Cc],Ll,Rr,Cc) );
                }
            }
        }
    }
    return d[el][er][ec];
}

int main()
{
    //filein;
    //fileout;

    while( scanf("%d %d %d\n",&lv,&r,&c) == 3 ){
        if(lv==0 && r==0 && c==0) break;
        int sl,sr,sc,el,er,ec;
        REP(l,lv){
            REP(i,r){
                gets(m[l][i]);
                REP(j,c){
                    if(m[l][i][j]=='S'){
                        sl=l;sr=i;sc=j;
                    }
                    else if(m[l][i][j]=='E'){
                        el=l;er=i;ec=j;
                    }
                    d[l][i][j]=inf;
                }
            }
            scanf("\n");
        }
        int res = dungeon(sl,sr,sc,el,er,ec);
        (res==inf) ? printf("Trapped!\n") : printf("Escaped in %d minute(s).\n",res);
    }
    return 0;
}

