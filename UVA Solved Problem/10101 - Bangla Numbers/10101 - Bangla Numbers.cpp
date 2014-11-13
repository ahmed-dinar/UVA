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

void say(int sz,char s[])
{
    int flag=0,fl=0;
    for(int i=0; i<sz; i++){
        if( (sz-i) == 9 && s[i] != '0' ){
            if(flag==1)
                printf(" ");
            printf("%c",s[i]);
            i++;
            printf("%c kuti",s[i]);
            flag=1;
        }
        else if( (sz-i) == 8 && s[i] != '0' ){
            if(flag==1)
                printf(" ");
            printf("%c kuti",s[i]);
            flag = 1;
        }
        else if( (sz-i) == 7 && s[i] != '0' ){
            if(flag==1)
                printf(" ");
            printf("%c",s[i]);
            i++;
            printf("%c lakh",s[i]);
            flag=1;
        }
        else if( (sz-i) == 6 && s[i] != '0' ){
            if(flag==1)
                printf(" ");
            printf("%c lakh",s[i]);
            flag=1;
        }
        else if( (sz-i) == 5 && s[i] != '0' ){
            if(flag==1)
                printf(" ");
            printf("%c",s[i]);
            i++;
            printf("%c hajar",s[i]);
            flag=1;
        }
        else if( (sz-i) == 4 && s[i] != '0' ){
            if(flag==1)
                printf(" ");
            printf("%c hajar",s[i]);
            flag=1;
        }
        else if( (sz-i) == 3 && s[i] != '0' ){
            if(flag==1)
                printf(" ");
            printf("%c shata",s[i]);
            flag=1;
        }
        else if( (sz-i) == 2 && s[i] != '0' ){
                if(flag==1)
                    printf(" ");
                printf("%c",s[i]);
                fl=1;
        }
        else if( (sz-i) == 1 && (s[i] != '0' || (s[i]=='0' && fl==1) ) ){
                if(flag==1 && fl==0)
                    printf(" ");
                printf("%c",s[i]);
        }
    }
}

int main()
{
    char n[17];
    char s[17];
    int ca=0;
    while( gets(n) ){
        int sz=strlen(n),j=0;
        for(int i=0,fl=0; i<sz; i++){
            if( (n[i]=='0' && fl==0) || !isdigit(n[i]) )
                continue;
            s[j]=n[i];
            j++;
            fl=1;
        }
        s[j]='\0';
        printf("%4d. ",++ca);
        if(j==0)
            printf("0");
        else{
            if(j>9){
                int i,k=0,fl=0;
                for(i=j-7; i<j; i++){
                    if(s[i]=='0' && fl==0)
                        continue;
                    n[k]=s[i];
                    k++;
                    fl=1;
                }
                n[k]='\0';
                s[j-7]='\0';
                say(j-7,s);
                printf(" kuti");
                if(k>0){
                    printf(" ");
                    say(k,n);
                }
            }
            else
                say(j,s);
        }
        printf("\n");
    }
    return 0;
}



