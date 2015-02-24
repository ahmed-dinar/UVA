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
#define MAX 110
#define oo 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<string> vcs;
typedef vector<int> vci;
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int dx[]={+0,+0,-1,+1};
int dy[]={+1,-1,+0,+0};
int r,c;
map<int,map<int,char> >grids;
map<int,map<int,int> >vis;
map<char,int >counted;
map<char,int>states;
vector<char>let;

bool valid(int rr,int cc){
    return (rr>=0 && rr<r && cc>=0 && cc<c);
}

void bfs(int rr,int cc,char ch){
    queue<int>qx,qy;
    qx.push(rr);
    qy.push(cc);
    vis[rr][cc]=1;
    while(!qx.em){
        int px=qx.front(); qx.pop();
        int py=qy.front(); qy.pop();
        REP(i,4){
            int nx=px+dx[i];
            int ny=py+dy[i];
            if( valid(nx,ny) && grids[nx][ny]==ch && !vis[nx][ny] ){
                vis[nx][ny]=1;
                qx.push(nx);
                qy.push(ny);
            }
        }
    }
}

bool com(char ch1,char ch2){
    if(states[ch1]==states[ch2])
        return ch1<ch2;
    else
        return states[ch1]>states[ch2];
}

int main(){

   // filein;

    int t,T=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        REP(i,r)
            REP(j,c)
                cin>>grids[i][j];


        REP(i,r){
            REP(j,c){
                char ch=grids[i][j];
                if(!counted[ch])
                    let.pb(ch),counted[ch]=1;

                if( !vis[i][j] ){
                    states[ch]++;
                    bfs(i,j,ch);
                }
            }
        }
        sort(all(let),com);
        printf("World #%d\n",++T);
        REP(i,let.sz){
            printf("%c: %d\n",let[i],states[let[i]]);
        }
        states.cl;
        vis.cl;
        let.cl;
        counted.cl;
    }
    return 0;
}
