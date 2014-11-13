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


int bol[1000001]={0};
int indx[1000001]={0};
int prime[78499];

void sieve(){
    int sq=sqrt(1000001),k=1;
    bol[0]=1;
    bol[1]=1;
    for(int i=3; i<=sq; i+=2)
        if(bol[i]==0)
            for(int j=i*i; j<=1000001; j+= 2*i)
                bol[j]=1;

    prime[0]=2;
    for(int i=4,j=3; i<=1000001; i+=2,j+=2){
        if(bol[j]==0)
            prime[k++]=j;
        bol[i]=1;
    }
    k=1;
    for(int i=0; i<=1000001; i++){
        if(bol[i]==0){
            indx[i]=k;
            i++;
            while(bol[i]==1){
                indx[i]=k;
                i++;
            }
            i--;
            k++;
        }
    }
}

int main()
{
    sieve();
    int a,b,t;
    sc(t);
    while(t--){
        scd(a,b);
        if( (indx[b]-indx[a-1]) < 2 ){
            printf("No jumping champion\n");
            continue;
        }
        int k=indx[b];
        int f=prime[indx[a-1]],no=0,mx=0,ans;
        int dis[200]={0};
        for(int i=indx[a-1]+1; i<k; i++){
            int s = prime[i];
            int ds=s-f;
            dis[ds]++;
            if(dis[ds]>mx){
                mx = dis[ds];
                ans = ds;
                no=0;
            }
            else if(dis[ds]==mx)
                no=1;

            f=s;
        }
        if(no == 1)
            printf("No jumping champion\n");
        else
            printf("The jumping champion is %d\n",ans);
    }
    return 0;
}
