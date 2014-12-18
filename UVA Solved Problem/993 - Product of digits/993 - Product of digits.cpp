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
#define MAX 200005
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

i64 prime[] = { 2, 3, 5, 7 };

i64 product(i64 n){
    if(n<10) return n;

    int c[10]={0};
    for(int i=0;i<4; i++){
        while(n%prime[i]==0){
            n/=prime[i];
            c[prime[i]]++;
        }
    }
    if(n>1)
        return -1;

    vector<int>res;
    while(c[2]>=3){
        res.pb(8);
        c[2] -= 3;
    }
    while(c[3]>=2){
        res.pb(9);
        c[3] -= 2;
    }
    while(c[5]>0){
        --c[5];
        res.pb(5);
    }
    while(c[7]>0){
        --c[7];
        res.pb(7);
    }
    if(c[2]==2&&c[3]==1)
        res.pb(6),res.pb(2);
    else if(c[2]==2&&c[3]==0)
        res.pb(4);
    else if(c[2]==1&&c[3]==1)
        res.pb(6);
    else if(c[2]==1&&c[3]==0)
        res.pb(2);
    else if(c[2]==0&&c[3]==1)
        res.pb(3);

    sort( all(res) );
    i64 N = 0;
    REP(i,res.size())
        N = (i64)N*10+(i64)res[i];
    return N;
}

int main()
{
    filein;
    //fileout;

    int t;
    sc(t);
    while(t--){
        i64 n;
        scanf("%lld",&n);
        printf("%lld\n",product(n));
    }
    return 0;
}

