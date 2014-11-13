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


struct g
{
    char c;
    int h,space;
    g(char x,int y,int z){c=x; h=y; space=z;}
    bool operator<(const g&p)const
    {
        if(h==p.h)
            return space > p.space;
        else
            return h<p.h;
    }
};


int main()
{
    int t,ca=0;
    string ch;
    scanf("%d",&t);
    while(t--){
        priority_queue<g>q;
        int w=1;
        char sm;
        cin >> ch;
        int sz=ch.size();
        for(int i=0; i<sz; i++)
        {
            if(ch[i]=='R')
            {
                sm='/';
                q.push( g(sm,w,i+1) );
                w++;
            }
            else if(ch[i]=='F'){
                sm=92;
                w--;
                q.push( g(sm,w,i+1) );
            }
            else{
                sm='_';
                q.push( g(sm,w,i+1) );
            }
        }
        printf("Case #%d:\n",++ca);
        w=-1;
        int k=q.top().h,flag=1;
        printf("|");
        while(!q.empty())
        {
            char symbol=q.top().c;
            int sp=q.top().space;
            int nl=q.top().h;
            q.pop();


            if(k!=nl){
                printf("\n|");
                w=-1;
            }
            w=sp-w;
            for(int i=1; i<w; i++)
                printf(" ");

            printf("%c",symbol);
            k=nl;
            w=sp;
        }
        printf("\n+");
        for(int i=0; i<sz+2; i++)
            printf("-");
        printf("\n");
        printf("\n");
    }
	return 0;
}
