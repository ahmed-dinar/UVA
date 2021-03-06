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


void one(char x,int lm)
{
    if(x=='1'){
        printf(" ");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf(" ");
    }
    else if(x=='2' || x=='3' || x=='5' || x=='6' || x=='7' || x=='8' || x=='9' || x=='0'){
        printf(" ");
        for(int i=0; i<lm; i++)
        {
            printf("-");
        }
        printf(" ");
    }
    else if(x=='4'){
        printf(" ");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf(" ");
    }
    return;
}

void zero(char x,int lm)
{
    printf(" ");
    for(int i=0; i<lm; i++)
    {
        printf(" ");
    }
    printf(" ");
}

void two(char x,int lm)
{
    if(x=='1'){
        printf(" ");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if(x=='2' || x=='3' || x=='7'){
        printf(" ");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if(x=='4' || x=='8' || x=='9' ||x=='0'){
        printf("|");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if(x=='5' || x=='6' ){
        printf("|");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf(" ");
    }
    return;
}

void three(char x,int lm)
{
    if(x=='1'){
        printf(" ");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if(x=='3' || x=='4' || x=='5' || x=='9' || x=='7'){
        printf(" ");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if(x=='2'){
        printf("|");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf(" ");
    }
    else if(x=='6' || x=='8' || x=='0'){
        printf("|");
        for(int i=0; i<lm; i++)
        {
            printf(" ");
        }
        printf("|");
    }
    return;
}

void pfo(char x,int lm)
{
        printf(" ");
        for(int i=0; i<lm; i++)
        {
            printf("-");
        }
        printf(" ");
}


int main()
{
    char n[11];
    int s;
    while( scanf("%d %s",&s,n)==2 ){
        if(s==0 && n[0]=='0') break;

        int sz=strlen(n);
        for(int j=1; j<=5; j++){

            if(j==1 || j==5){
                for(int i=0; i<sz; i++){
                        if(j==5 && n[i]=='7')
                            zero(n[i],s);
                        else
                            one(n[i],s);

                        if(i!=sz-1)
                            printf(" ");
                }
                printf("\n");
            }
            else if(j==3 ){
                    for(int i=0; i<sz; i++){
                        if(n[i]=='0' || n[i]=='7')
                            zero(n[i],s);
                        else if(n[i]=='4')
                            pfo(n[i],s);
                        else
                            one(n[i],s);

                        if(i!=sz-1)
                            printf(" ");
                    }
                    printf("\n");
            }
            else if(j==2){
                for(int m=0; m<s; m++){
                    for(int i=0; i<sz; i++){
                            two(n[i],s);

                        if(i!=sz-1)
                            printf(" ");
                    }
                    printf("\n");
                }
            }
            else if(j==4){
                for(int m=0; m<s; m++){
                    for(int i=0; i<sz; i++){
                                three(n[i],s);
                        if(i!=sz-1)
                            printf(" ");
                    }
                    printf("\n");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
