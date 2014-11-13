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


void first(char x)
{
    if(x == '0')
        printf("%c / ",92);
    if(x =='1' || x =='9')
        printf(" o  ");
    if(x =='2' || x =='3' || x =='8')
        printf("    ");
    if(x=='4')
        printf("_o_ ");
    if(x=='5' || x=='7')
        printf("%co/ ",92);
    if(x == '6')
        printf("%co_ ",92);
}

void second(char x)
{
    if(x== '0' || x=='4' || x=='5')
        printf(" |  ");
    if(x=='1')
        printf("/|%c ",92);
    if(x=='2' || x=='3')
        printf("    ");
    if(x=='6')
        printf("%c|  ",92);
    if(x=='7')
        printf("%c|/ ",92);
    if(x=='8')
        printf(" __o");
    if(x=='9')
        printf("( ) ");
}

void third(char x)
{
    if(x=='0')
        printf("/o%c ",92);
    if(x=='1' || x=='4' || x=='5' || x=='9')
        printf("/ %c ",92);
    if(x=='2')
        printf("__%co",92);
    if(x=='3')
        printf("%c_%co",92,92);
    if(x=='6')
        printf(" |  ");
    if(x=='7')
        printf("    ");
    if(x=='8')
        printf("/  |");
}


int main()
{
    char test[5];
    char s[74];
    scanf("%s",test);
    int t= atoi(test);
    while(t--)
    {
        scanf("%s",s);
        int ln=strlen(s);
        for(int j=1; j<=3; j++)
        {
            for(int i=0; i<strlen(s); i++)
            {
                if(j==1)
                    first(s[i]);
                else if(j==2)
                    second(s[i]);
                else
                    third(s[i]);

                if(i<strlen(s)-1)
                    cout << " ";
            }
            cout << "\n";
        }
            cout << "\n";
    }
    return 0;
}
