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


int dp[30][70];

int ispalindrome(int x,int y){

    if(x<10&&y<10){
        if(x==y) return 1;
        else
            return 0;
    }
    else if(x<10&&y>=10){
        if(x==0){
            if(y/10 == y%10)
                return 1;
            else
                return 0;
        }
        else{
            if(x==y%10)
                return 1;
            else
                return 0;
        }
    }
    else if(x>=10&&y<10){
        if(x/10==y){
            if(x%10==0)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else if(x>=10&&y>=10){
        if(x/10!=y%10)
            return 0;
        if(x%10!=y/10)
            return 0;

            return 1;
    }
}

void pre(){
    int P=0,Q=10;
    dp[0][0]=1;
    dp[0][1]=1;
    dp[0][2]=1;
    dp[0][3]=1;
    dp[0][4]=1;
    dp[0][5]=1;
    dp[0][6]=1;
    dp[0][7]=1;
    dp[0][8]=1;
    dp[0][9]=1;
    dp[0][10]=0;
    while(1){
        if(P==0&&Q==0){
            break;
        }
        Q++;
        if(Q>=60){
            P++;
            Q=0;
        }
        if(P>=24){
            Q=0;
            P=0;
        }
        dp[P][Q]=ispalindrome(P,Q);
    }
}

int main()
{
    pre();
    int t,h,m;
    char ch;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%c%d",&h,&ch,&m);
        m++;
        if(m>=60){
            h++;
            m=0;
        }
        if(h>=24){
            h=0;
            m=0;
        }
        if(dp[h][m]!=1){
            while(dp[h][m]!=1){
                m++;
                if(m>=60){
                    h++;
                    m=0;
                }
                if(h>=24){
                    h=0;
                    m=0;
                }
            }
        }

        if(h<10)
            printf("0%d",h);
        else
            printf("%d",h);
        printf(":");
        if(m<10)
            printf("0%d\n",m);
        else
            printf("%d\n",m);
    }
    return 0;
}


