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
#define MAX 55
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

struct h
{
    int fills;
    char ch;
    h(int fills,char ch) : fills(fills),ch(ch) {}
    bool operator<( const h& p ) const {
        if(fills==p.fills){
            return ch < p.ch;
        }
        else
            return fills > p.fills;
    }
};

int x[]={1,0,-1,0};
int y[]={0,1,0,-1};
char land[MAX][MAX];
int r,c;
vector<h>hole;

bool invalid(int rr,int cc){
    return (rr<0 || rr>=r || cc<0 || cc>=c);
}

int Fill(int rr,int cc,char ch){
    queue<pri>q;
    q.push(mp(rr,cc));
    land[rr][cc]='.';
    int ans=1;
    while(!q.empty()){
        int rx=q.front().fi;
        int cy=q.front().ss;
        q.pop();
        REP(i,4){
            int xx=rx+x[i];
            int yy=cy+y[i];
            if( !invalid(xx,yy) && land[xx][yy]==ch ){
                ++ans;
                land[xx][yy]='.';
                q.push( mp(xx,yy) );
            }
        }
    }
    return ans;
}

int main(){

    //filein;

    int T=0;
    while( scanf("%d %d\n",&r,&c) == 2 ){
        if(r+c==0) break;
        REP(i,r)
            gets(land[i]);
        REP(i,r){
            REP(j,c){
                if( isupper(land[i][j]) ){
                    char ch=land[i][j];
                    int res = Fill(i,j,ch);
                    hole.pb( h(res,ch) );
                }
            }
        }
        sort(all(hole));
        printf("Problem %d:\n",++T);
        REP(i,hole.sz)
            printf("%c %d\n",hole[i].ch,hole[i].fills);
        hole.cl;
    }
    return 0;
}
