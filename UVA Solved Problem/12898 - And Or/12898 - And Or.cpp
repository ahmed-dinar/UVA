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
#define MAX 1000000000000000000
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int main()
{
    int t,T=0;
    i64 a,b;
    sc(t);
    while(t--){
        scanf("%lld %lld",&a,&b);
        if(a==b){
            printf("Case %d: %lld %lld\n",++T,a,b);
        }
        else{
            i64 k=a;
            i64 i=a|(a+1);
            i64 n=a&(a+1);
            int res1=0,res2=0;
            while(1){

                if(res1 && res2) break;

                if(!res1){
                    if( n==0 )
                        res1 = 1;
                    else if( !( n & (n-1) ) ){
                        if(b>=(n<<1)) n=0;
                        res1  = 1;
                    }
                    else if( i>=b ){
                        res1 = 1;;
                    }
                    else{
                        n = n&(i+1);
                        i = i|(i+1);
                    }
                }
                if(!res2){
                    if(k>=b)
                        res2=1;
                    else
                        k=k|(k+1);
                }
            }
            printf("Case %d: %lld %lld\n",++T,k,n);
        }
    }
    return 0;
}

