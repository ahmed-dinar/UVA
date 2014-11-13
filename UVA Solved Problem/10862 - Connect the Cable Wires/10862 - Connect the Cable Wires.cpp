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


char fib[5002][1050];

void fibonacci()
{
    int lf,ls,i,fm,carry;
    char temp[1050];
    string s("0"),f("1");
    for(int x=0; x<=5000; x++){
        strcpy(fib[x],f.c_str());
        lf=f.size()-1;
        ls=s.size()-1;
        string sum;
        for(i=max(lf,ls),carry=0; i>=0; i--,ls--,lf--)
        {
            if(i==0)
            {
                if(ls<0){
                    fm=(f[lf]-48)+carry;
                }
                else if(lf<0){
                    fm=(s[ls]-48)+carry;
                }
                else{
                    fm=(s[ls]-48)+(f[lf]-48)+carry;
                }
                if(fm>=10){
                    sum.push_back(fm%10+48);
                    sum.push_back(fm/10+48);
                }
                else{
                    sum.push_back(fm+48);
                }
                break;
            }
            else if(lf<0)
            {
                fm=(s[ls]-48)+carry;
                sum.push_back(fm%10+48);
            }
            else if(ls<0)
            {
                fm=(f[lf]-48)+carry;
                sum.push_back(fm%10+48);
            }
            else
            {
                fm=(s[ls]-48)+(f[lf]-48)+carry;
                if(fm>=10)
                    sum.push_back(fm%10+48);
                else
                    sum.push_back(fm+48);
            }
            carry=fm/10;
        }
        s.clear();
        s=f;
        f.clear();
        for(int i=sum.size()-1; i>=0; i--){
            f.push_back(sum[i]);
        }
    }
}

int main(){
    fibonacci();
    int n;
    while(scanf("%d",&n) && n){
        printf("%s\n",fib[n*2 - 1]);
    }
    return 0;
}
