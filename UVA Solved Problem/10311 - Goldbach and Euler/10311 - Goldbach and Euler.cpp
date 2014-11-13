#include<bits/stdc++.h>

using namespace std;

#define pf(x) printf("%d",x)
#define pfd(x,y) printf("%d %d",x,y)
#define pfl(x) printf("%ld",x)
#define pfll(x) printf("%lld",x)
#define pfllu(x)
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
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define MOD 4294967296

bool isUpper(char ch){ return ( ch>='A' && ch<='Z' ) ?  true :  false; }
bool isLower(char ch){ return ( ch>='a' && ch<='z')  ?  true :  false; }
bool isLetter(char ch){ return ( ch>='A' && ch<='Z' || ch>='a' && ch<='z') ?  true :  false; }
bool isDigit(char ch){ return ( ch>='0' && ch<='9') ?  true :  false; }
char toLower(char ch){ return (isUpper(ch)) ? (ch+32) : ch; }
char toUpper(char ch){ return (isLower(ch)) ? (ch-32) : ch; }

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { return (n>=p) ? n : p; }
template<class T>T ABS(T n) { return (n<0) ?  (-n) :  n; }

#define MAX 100000000
#define lim 3125002

int flag[lim]={0};
vector<int>primes;

void sieve(){
    flag[0/32] = flag[0/32] | 1 << 0%32;
    flag[1/32] = flag[1/32] | 1 << 1%32;
    for(int i=3;i*i<=MAX; i += 2){
        if(  (flag[i/32] & 1<<i) ==0 ){
            primes.pb(i);
            for(int j=i*i; j<=MAX; j += 2*i){
                flag[j/32] = flag[j/32] | 1 << j%32 ;
            }
        }
    }
    primes.pb(2);
    for(int i=4,j=3;i<=MAX;i+=2,j+=2){
        flag[i/32] = flag[i/32] | 1 << i%32;
        if(  (flag[j/32] & 1<<j) == 0 )  primes.pb(j);
    }
}

int main()
{
	//filein;

    sieve();

    int n;
    while(sc(n)!=EOF){

        if(n<=4)
            printf("%d is not the sum of two primes!\n",n);
        else if( !isEven(n) ){
            int x=n-2;
            if( (flag[x/32] & 1<<x) == 0 )
                printf("%d is the sum of %d and %d.\n",n,2,x);
            else
                printf("%d is not the sum of two primes!\n",n);
        }
        else{
            int is=false;
            int index = (int) ( lower_bound(primes.begin(),primes.end(),n/2) - primes.begin() );
            if(primes[index]==n/2) index++;

            while( primes[index]<n ){
                int x = primes[index];
                int y = n-x;
                if( (flag[y/32] & 1<<y) == 0   ){
                    is = true;
                    printf("%d is the sum of %d and %d.\n",n,y,x);
                    break;
                }
                index++;
            }
            if(!is) printf("%d is not the sum of two primes!\n",n);
        }
    }
    return 0;
}
