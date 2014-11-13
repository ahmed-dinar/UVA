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

map<string,int>iscandidate;
vector<string>candidates;
map<string,int>vote;
map<string,string>party;

int main()
{
    char cas[10];
    int t,ca=0;
    gets(cas);
    t = atoi(cas);
    for(int T=0; T<t; T++){
        if(T) nl;
        char nline;
        scanf("%c",&nline);
        char N[3];
        gets(N);
        int n = atoi(N);
        for(int i=0; i<n; i++){
            string cname,pname;
            getline(cin,cname);
            getline(cin,pname);
            iscandidate[cname] = 1;
            candidates.push_back(cname);
            party[cname] = pname;
        }
        char M[3];
        gets(M);
        int m = atoi(M),highest=0;
        int result[10005] = {0};
        string winner;
        for(int i=0; i<m; i++){
            string ballot;
            getline(cin,ballot);
            vote[ballot]++;
            if(highest<=vote[ballot]){
                highest = vote[ballot];
                winner = ballot;
                result[highest]++;
            }
        }
        if(result[highest] == 1)
            printf("%s\n",party[winner].c_str());
        else
            printf("tie\n");
        iscandidate.clear();
        candidates.clear();
        vote.clear();
        party.clear();
    }
    return 0;
}
