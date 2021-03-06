#include<bits/stdc++.h>

using namespace std;

#define pf(x) printf("%d",x)
#define pfd(x,y) printf("%d %d",x,y)
#define pfl(x) printf("%ld",x)
#define nl printf("\n")
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scll(n) scanf("%lld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define sct(n,m,w) scanf("%d %d %d",&n,&m,&w)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define FOR(i,n) for(int i=0;i<n; i++)
#define inf 100000000
#define MAX 100005

bool isUpper(char ch){ if( ch>='A' && ch<='Z' ) return true; return false; }
bool isLower(char ch){ if( ch>='a' && ch<='z') return true; return false;}
bool isLetter(char ch){ if( ch>='A' && ch<='Z' || ch>='a' && ch<='z') return true; return false; }
bool isDigit(char ch){ if( ch>='0' && ch<='9') return true; return false; }
char toLower(char ch){ if (isUpper(ch)) return (ch+32); return ch; }
char toUpper(char ch){ if (isLower(ch)) return (ch-32); return ch; }

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return a*a; }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { if(n>=p) return n; return p; }


vector<i64>sums;

i64 bin_search(int num,int n){
    int low=0,high=n-1,mid;
    i64 mdif=-1,res=0;
    while(low<=high){
        mid = (low+high)/2;
        i64 dif = abs(num-sums[low]);
        if(mdif==-1){
            mdif = dif;
            res = sums[low];
        }

        dif = abs(num-sums[low]);
        if(mdif==dif){
            res = min(res,sums[low]);
        }
        else if(dif<mdif){
            mdif = dif;
            res = sums[low];
        }
        dif = abs(num-sums[mid]);
        if(mdif==dif){
            res = min(res,sums[mid]);
        }
        else if(dif<mdif){
            mdif = dif;
            res = sums[mid];
        }
        dif = abs(num-sums[high]);
        if(mdif==dif){
            res = min(res,sums[high]);
        }
        else if(dif<mdif){
            mdif = dif;
            res = sums[high];
        }

        if( sums[mid] == num )
            return num;
        else if( sums[mid]>num )
            high = mid-1;
        else
            low = mid+1;
    }
    return res;
}

int main()
{
    //filein;
    //fileout;

    int n,T=0;
    while(sc(n) && n){
        i64 ar[n+1];
        for(int i=0;i<n;i++) scll(ar[i]);

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                sums.pb(ar[i]+ar[j]);

        sort( all(sums) );
        int sz=sums.size();
        int query;
        sc(query);
        csn(++T);
        while(query--){
            i64 m;
            scll(m);
            printf("Closest sum to %lld is %lld.\n",m,bin_search(m,sz) );
        }
        sums.clear();
    }
    return 0;
}
