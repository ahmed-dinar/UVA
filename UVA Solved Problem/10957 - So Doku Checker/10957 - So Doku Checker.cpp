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

int n[10][10];
int N,Count;

int illegal_line(int x,int y,int v){
   for(int i=1; i<=N*N; i++)
        if(n[x][i] == v && (i!=y))
            return 0;

   for(int i=1; i<=N*N; i++)
        if(n[i][y] == v && (i!=x))
            return 0;

   return 1;
}

int illegal_box(int x,int y,int v){
    int tmx=x,tmy=y;
    x=(x-1)/N;
    y=(y-1)/N;
    x=(x*N)+1;
    y=(y*N)+1;
    for(int i=x; i<x+N; i++)
        for(int j=y; j<y+N; j++)
            if(n[i][j]==v && (i!=tmx && j!=tmy) )
                return 0;

    return 1;
}

int line(int x,int y,int v){
   for(int i=1; i<=N*N; i++)
        if(n[x][i] == v)
            return 0;

   for(int i=1; i<=N*N; i++)
        if(n[i][y] == v)
            return 0;

   return 1;
}

int box(int x,int y,int v)
{
    x=(x-1)/N;
    y=(y-1)/N;
    x=(x*N)+1;
    y=(y*N)+1;
    for(int i=x; i<x+N; i++)
        for(int j=y; j<y+N; j++)
            if(n[i][j]==v){
                return 0;


    return 1;
}


void solve_soduko(int r,int c){
    if(r>N*N){
        Count++;
    }
    else{
        if(n[r][c] !=0 ){
            if(c<N*N)
                solve_soduko(r,c+1);
            else
                solve_soduko(r+1,1);
        }
        else{
            for(int k=1; k<=9; k++){

                if(line(r,c,k)==1 && box(r,c,k)==1){
                    n[r][c]=k;
                    solve_soduko(r,c);
                }
                if(Count>1)
                    break;
            }
            n[r][c]=0;
        }
    }
}

int check_illegal()
{
    for(int i=1; i<=N*N; i++)
        for(int j=1; j<=N*N; j++)
            if(n[i][j]!=0)
                if( illegal_line(i,j,n[i][j]) ==0 || illegal_box(i,j,n[i][j]) == 0)
                    return 0;


    return 1;
}

int main()
{
   int ca=0;
   N=3;
   while( scanf("%d",&n[1][1]) == 1)
   {
        for(int j=2; j<=N*N; j++)
                scanf("%d",&n[1][j]);

        for(int i=2; i<=N*N; i++)
            for(int j=1; j<=N*N; j++)
                scanf("%d",&n[i][j]);

        Count=0;
        if( check_illegal() == 0)
            printf("Case %d: Illegal.\n",++ca);
        else{
            solve_soduko(1,1);
            if(Count==1)
                printf("Case %d: Unique.\n",++ca);
            else if(Count>1)
                printf("Case %d: Ambiguous.\n",++ca);
            else if(Count==0)
                printf("Case %d: Impossible.\n",++ca);
        }
    }
    return 0;
}
