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

#define pf printf
#define nl pf("\n")
#define cs(x) pf("Case %d: ",x)
#define csn(x) pf("Case %d:\n",x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 2005
#define inf 200000000
#define M 1000000007

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }

int main(){

    filein;

    int t;
    sc(t);
    int n;
    while(t--){
        string neigbr;
        vector<int>v;
        int p,min_nbr=inf;
        sc(p);
        scanf("\n");
        REP(i,p){
            getline(cin,neigbr);
            int tot=0;
            REP(j,neigbr.size()){
                if( neigbr[j]==' ' ) tot++;
            }
            ++tot;
            min_nbr = min(min_nbr,tot);
            v.pb(tot);
        }
        int sp=0;
        REP(i,p){
            if(v[i]==min_nbr){
                if(sp) pf(" ");
                pf("%d",i+1);
                sp=1;
            }
        }
        nl;
    }
    return 0;
}
