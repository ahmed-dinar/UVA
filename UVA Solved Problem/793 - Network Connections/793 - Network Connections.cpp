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

map<int,int>par;

int rep(int x){
    return (par[x] == x) ? x : par[x]=rep(par[x]);
}

int main()
{
    int t;
    sc(t);
    while(t--){
        int computers,a,b,correct=0,wrong=0;
        string ch;
        char q;
        scanf("%d\n",&computers);
        while( getline(cin,ch) ){
            if(ch =="") break;

            stringstream st;
            st << ch;
            st >> q;
            st >> a;
            st >> b;
            if(q == 'c')
            {
                if(par[a]==0 && par[b]==0){
                    par[b] = a;
                    par[a] = a;
                }
                else if(par[a] != 0 && par[b] == 0){
                    int parent=rep(a);
                    par[b]=parent;
                }
                else if(par[a] == 0 && par[b] != 0){
                    int parent=rep(b);
                    par[a]=parent;
                }
                else if(par[a] != 0 && par[b] != 0){
                    int pa=rep(a);
                    int pb=rep(b);
                    if(pa!=pb){
                        par[pb]=pa;
                        par[b]=pa;
                    }
                }
            }
            else
            {
                if(a==b)
                    correct++;
                else if(par[a]==0 && par[b]==0)
                    wrong++;
                else if(par[a]==0 && par[b] != 0){
                    int pb=rep(b);
                    if(a == pb)
                        correct++;
                    else
                        wrong++;
                }
                else if(par[a] !=0 && par[b] == 0){
                    int pa=rep(a);
                    if(pa == b)
                        correct++;
                    else
                        wrong++;
                }
                else{
                    int pa=rep(a);
                    int pb=rep(b);
                    if(pa == pb)
                        correct++;
                    else
                        wrong++;
                }
            }
        }
        printf("%d,%d\n",correct,wrong);
        if(t) nl;
        par.clear();
    }
    return 0;
}
