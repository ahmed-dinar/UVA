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
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 1000
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct cell
{
    int v,r,c;
    cell(int v,int r,int c) { this->v=v; this->r=r; this->c=c; }
    bool operator<( const cell& p ) const { return v > p.v; }
};

int r,c;
int x[]={-1,0,1,0};
int y[]={0,-1,0,1};
int m[MAX][MAX];
int d[MAX][MAX];

bool valid_move(int R,int C){
    return ((R>=0&&R<r) && (C>=0&&C<c));
}

int maze(){
    priority_queue<cell>q;
    q.push( cell(m[0][0],0,0) );
    d[0][0] = m[0][0];
    while(!q.empty()){
        cell b = q.top(); q.pop();
        int v=b.v;
        REP(i,4){
            int mr = b.r+x[i];
            int mc = b.c+y[i];
            if( valid_move(mr,mc) && d[mr][mc] > v+m[mr][mc]  ){
                d[mr][mc] = v+m[mr][mc];
                q.push( cell(d[mr][mc],mr,mc) );
            }
        }
    }
    return d[r-1][c-1];
}

int main()
{
    //filein;

    int t;
    sc(t);
    while(t--){
        sc(r);
        sc(c);
        REP(i,r){
            REP(j,c){
                sc(m[i][j]);
                d[i][j]=inf;
            }
        }
        printf("%d\n",maze());
    }
    return 0;
}

