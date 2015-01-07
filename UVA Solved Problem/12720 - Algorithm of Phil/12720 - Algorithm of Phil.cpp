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
#define fileout freopen("my.txt","w",stdout)

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
#define MAX 100005
#define inf 2000000000.0
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

char a[MAX];
int s[MAX];

i64 toDecimal(int ln){
    i64 p=1,dc=0;
    for(int i=ln-1;i>=0;i--){
        dc = (dc%MOD + (p*s[i])%MOD)%MOD;
        p = (p%MOD * 2%MOD)%MOD;
    }
    return dc;
}

int main()
{
    //filein;

    int t,T=0;
    sc(t);
    while( t-- ){
        scanf("%s",a);
        int ln=strlen(a);
        int leftBit,rightBit;

        if( (ln&1) ){
            leftBit = ln>>1;
            rightBit=leftBit+1;
        }
        else{
            rightBit = ln>>1;
            leftBit=rightBit-1;
        }

        int k=0,pre=leftBit;
        while(ln){
            if(ln==1){
                s[k]=(a[leftBit]-'0');
            }
            else if( (ln&1) ){
                s[k]=(a[leftBit]-'0');
                int tmp=leftBit;
                leftBit=pre-1;
                pre=leftBit;
            }
            else{
                if( a[leftBit]<=a[rightBit] ){
                    s[k]=(a[rightBit]-'0');
                    ++rightBit;
                }
                else{
                    s[k]=(a[leftBit]-'0');
                    leftBit=rightBit;
                    ++rightBit;
                }
            }
            --ln;
            ++k;
        }
        printf("Case #%d: %lld\n",++T,toDecimal(k));
    }
    return 0;
}

