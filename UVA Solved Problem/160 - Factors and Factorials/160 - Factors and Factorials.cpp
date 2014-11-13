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
#define inf 100000
#define MAX 50001
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


int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<int>prime_fact[100];
int prime_fact_count[100][100]={0};

void pre(){
    for(int i=2; i<=100; i++){
        int n=i;
        int sq=sqrt(i);
        for(int j=0; prime[j]<=sq; j++){
            if(n%prime[j] == 0){
                int u=prime[j];
                prime_fact[i].pb(u);
                while(n%u==0)
                {
                    n=n/u;
                    prime_fact_count[i][u]++;
                }
                if(n<=0)
                    break;
            }
        }
        if(n>1){
            prime_fact[i].pb(n);
            prime_fact_count[i][n]++;
        }
    }
}

void print(int K){
    vector<int>v;
    int fll[100]={0};
    for(int N=2; N<=K; N++){
        int sz=prime_fact[N].size();
        for(int p=0; p<sz; p++){
            if(find( all(v) ,prime_fact[N][p]) == v.end())
                    v.pb(prime_fact[N][p]);

            fll[prime_fact[N][p]] += prime_fact_count[N][prime_fact[N][p]];
        }
    }
    for(int i=0; i<v.size(); i++){
        if(i==15)
            printf("\n      ");
        printf("%3d",fll[v[i]]);
    }
    printf("\n");
}

int main(){
    pre();
    int num;
    while( scanf("%d",&num) == 1 && num){
        printf("%3d! =",num);
        print(num);
    }
    return 0;
}

