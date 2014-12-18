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
#define MAX 3005
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

i64 x[MAX];

int main()
{
  //  filein;
   // fileout;

    i64 n;
    while( scanf("%lld",&n) == 1 ){
        scanf("%lld",&x[0]);
        map<i64,int>is;
        int jolly = 1;
        fr(i,1,n){
            i64 a;
            scanf("%lld",&x[i]);
            i64 df = abs(x[i-1]-x[i]);
            is[df]=1;
        }
        for(i64 i=1;i<n;i++){
            if(!is[i]){
                jolly=0;
                break;
            }
        }
        if(jolly)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
