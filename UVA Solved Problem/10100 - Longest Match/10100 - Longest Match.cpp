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

char x[1010][25],y[1010][25];
int p,q;
int dp[1010][1010];

int match(int i,int j)
{
    if(i>=p || j>=q) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int c=0;
    if( strcmp(x[i],y[j]) == 0 ){
        c = 1+match(i+1,j+1);
    }
    else{
        int e=match(i+1,j);
        int f=match(i,j+1);
        c=max(e,f);
    }
    return dp[i][j]=c;
}

int main()
{
    char a[1010],b[1010];
    int ca=0;
    while( cin.getline(a,1010) ){
        cin.getline(b,1010);
        printf("%2d. ",++ca);
        if( strlen(a)==0 || strlen(b) == 0){
            printf("Blank!\n");
            continue;
        }
        char *cut;
        cut = strtok(a," ,.';:!/?`~#*-+.'|=_&^%$@");
        p=0;
        while(cut != NULL){
            strcpy(x[p],cut);
            p++;
            cut = strtok(NULL," ,.';:!/?`~#*-+.'|=_&^%$@");
        }
        cut = strtok(b," ,.';:!/?`~#*-+.'|=_&^%$@");
        q=0;
        while(cut != NULL){
            strcpy(y[q],cut);
            q++;
            cut = strtok(NULL," ,.';:!/?`~#*-+.'|=_&^%$@");
        }
        mset(dp,-1);
        printf("Length of longest match: %d\n",match(0,0));
    }
    return 0;
}
