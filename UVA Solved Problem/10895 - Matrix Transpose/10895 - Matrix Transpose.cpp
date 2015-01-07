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
#define MAX 1005
#define inf 2000000000.0
#define MOD 1000000007

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int indx[MAX];
vector<int>in[MAX];
vector<int>m[MAX];

int main()
{
    filein;

    int r,c,n,v;
    while( scanf("%d %d",&r,&c) == 2 ){
        REP(i,r){
            scanf("%d",&n);
            REP(j,n)
                scanf("%d",&indx[j]);

            REP(j,n){
                scanf("%d",&v);
                m[indx[j]-1].pb(v);
                in[indx[j]-1].pb(i+1);
            }
        }
        printf("%d %d\n",c,r);
        REP(i,c){
            int ln=m[i].sz;
            if(ln==0)
                printf("0\n");
            else{
                printf("%d",ln);
                REP(j,ln)
                    printf(" %d",in[i][j]);
                nl;
                printf("%d",m[i][0]);
                For(j,1,ln)
                    printf(" %d",m[i][j]);
            }
            nl;
        }
        REP(i,c) in[i].clear(),m[i].clear();
    }
    return 0;
}

