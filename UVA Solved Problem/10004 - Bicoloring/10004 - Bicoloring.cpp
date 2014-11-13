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

void biocolour(vector<int>x[250]){
    queue<int>Q;
    int colored[250]={0};
    int flag=1;
    Q.push(0);
    colored[0]=1;
    while(!Q.empty()){
        int u=Q.front();
        int sz=x[u].size();
        for(int j=0; j<sz; j++){
            int v=x[u][j];
            if(colored[v] != 0 && colored[u]==colored[v]){
                flag=0;
                break;
            }
            if(colored[v]==0){
                if(colored[u]==1)
                    colored[v]=2;
                else
                    colored[v]=1;
                Q.push(v);
            }
        }
        if(flag==0)
            break;
        Q.pop();
    }
    if(flag==0)
        printf("NOT BICOLORABLE.\n");
    else
        printf("BICOLORABLE.\n");
}


int main()
{
    int n,l,a,b;
    while( sc(n) == 1){
        if(n==0) break;

        sc(l);
        vector<int>v[250];
        for(int i=0; i<l; i++){
            scd(a,b);
            v[a].pb(b);
            v[b].pb(a);
        }
        biocolour(v);
    }
    return 0;
}



