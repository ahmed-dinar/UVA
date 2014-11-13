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
#define MAX 105
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


struct node
{
    int u,v;
    float w;
    node( int U,int V,float W ){ u=U; v=V; w=W; }
    bool operator < ( const node& p) const { return w < p.w; }
};

vector<node>g;
int par[MAX];
map<int,pair<float,float> >id;

int parent(int x){
    return (par[x]==x) ? x : par[x]=parent(par[x]);
}

float mst(int n){
    sort(all(g));
    int sz=(int)g.size();
    int nodes=0;
    float res=0.0;
    for(int i=0;i<sz;i++){
        int u=parent(g[i].u);
        int v=parent(g[i].v);
        if(u!=v){
            par[u]=v;
            res += g[i].w;
            nodes++;
            if(nodes == n) return res;
        }
    }
    return res;
}

float distance_(int a,int b){
    float x = (id[a].first-id[b].first)*(id[a].first-id[b].first);
    float y = (id[a].second-id[b].second)*(id[a].second-id[b].second);
    return (float)sqrt(x+y);
}

int main()
{
    //filein;
    //fileout;

    int t,nwline=false;
    sc(t);
    while( t-- ){
        int n;
        sc(n);
        for(int i=1;i<=n;i++){
            float x,y;
            scanf("%f %f",&x,&y);
            par[i]=i;
            id[i] = make_pair(x,y);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                float dis = distance_(i,j);
                g.pb( node(i,j,dis) );
            }
        }
        if(nwline) printf("\n");
        printf("%.2f\n",mst(n));
        g.clear();
        id.clear();
        nwline = true;
    }
    return 0;
}

