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

vector<i64>e;
vector<char>p;

void maximal(int sz)
{
    i64 ad=0,fl=0,mul=1;
    int i;
    for(i=0; i<sz-1 ; i++)
    {
        if( p[i] == '+' && fl==0){
            fl=1;
        }

        if( p[i] =='+' && fl==1){
            if(ad==0)
                ad=e[i];

            ad=ad+e[i+1];
        }

        if(p[i]=='*'){

            if(mul==1 && ad ==0)
                mul=e[i];
            else if(mul==1 && ad !=0)
                mul=ad;
            else if(mul!=1 && ad !=0)
                mul *= ad;

            if(p[i+1] != '+')
                mul *= e[i+1];

            fl=0;
            ad=0;
        }
    }
    if( p[i-1] =='+')
        mul *= ad;

    printf("%lld",mul);
}

void minimum(int sz)
{
    i64 ad=0,fl=0,mul=0;
    int i;
    for(i=0; i<sz-1 ; i++)
    {
        if(p[i]=='*' && fl==0){
            fl=1;
        }

        if(p[i]=='*' && fl==1){
            if(mul==0)
                mul=e[i];

           mul *= e[i+1];
        }

        if(p[i]=='+'){

            if(mul==0&&ad==0)
                ad=e[i];
            else if(mul!=0&&ad==0)
                ad=mul;
            else if(mul!=0&&ad!=0)
                ad += mul;


            if(p[i+1] != '*')
                ad += e[i+1];

            fl=0;
            mul=0;
        }
    }

    if(p[i-1]=='*')
        ad += mul;

    printf("%lld",ad);
}


int main()
{
    i64 t;
    char equ[100];
    scanf("%lld\n",&t);
    for(i64 T=0; T<t; T++)
    {
        cin.getline(equ,99);
        int sz=strlen(equ);
        i64 num=0;
        for(int i=0; i<sz; i++){
            if(equ[i]>=48 && equ[i]<=57){
                num = num*10 + (equ[i]-'0');
            }
            else{
                if(num != 0)
                    e.push_back(num);

                if(equ[i] == '+' || equ[i]=='*')
                    p.push_back(equ[i]);

                num = 0;
            }
        }
        if(num != 0 )
            e.push_back(num);


        int lm=e.size();
        printf("The maximum and minimum are ");
        maximal(lm);
        printf(" and ");
        minimum(lm);
        printf(".\n");
        e.clear();
        p.clear();
    }
	return 0;
}
