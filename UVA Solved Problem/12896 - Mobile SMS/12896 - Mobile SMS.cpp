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
#define MAX 6005
#define inf 2000000

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }

char ch[105][105];

void mobile(){
    ch[1][1] = '.';
    ch[1][2] = ',';
    ch[1][3] = '?';
    ch[1][4] = '"';

    ch[2][1] = 'a';
    ch[2][2] = 'b';
    ch[2][3] = 'c';
    ch[2][4] = '2';

    ch[3][1] = 'd';
    ch[3][2] = 'e';
    ch[3][3] = 'f';
    ch[3][4] = '3';

    ch[4][1] = 'g';
    ch[4][2] = 'h';
    ch[4][3] = 'i';
    ch[4][4] = '4';

    ch[5][1] = 'j';
    ch[5][2] = 'k';
    ch[5][3] = 'l';
    ch[5][4] = '5';

    ch[6][1] = 'm';
    ch[6][2] = 'n';
    ch[6][3] = 'o';
    ch[6][4] = '6';

    ch[7][1] = 'p';
    ch[7][2] = 'q';
    ch[7][3] = 'r';
    ch[7][4] = 's';

    ch[8][1] = 't';
    ch[8][2] = 'u';
    ch[8][3] = 'v';
    ch[8][4] = '8';

    ch[9][1] = 'w';
    ch[9][2] = 'x';
    ch[9][3] = 'y';
    ch[9][4] = 'z';

    ch[0][1] = ' ';
    ch[0][2] = '0';
    ch[0][3] = ' ';
    ch[0][4] = '0';
}

int main(){

    filein;

    mobile();
    int t,T=0;
    sc(t);
    while(t--){
        int n,p;
        sc(n);
        int key[n+1],time[n+1];
        REP(i,n) sc(key[i]);
        REP(i,n){
            sc(p);
            printf("%c",ch[key[i]][p]);
        }
        nl;
    }
    return 0;
}





