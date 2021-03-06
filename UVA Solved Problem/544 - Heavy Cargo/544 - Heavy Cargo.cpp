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


string destination;

struct node
{
    string u,v;
    int w;
    node(string u1,string v1,int w1) { u=u1; v=v1; w=w1; }
    bool operator < ( const node& x) const {
        return w < x.w;
    }
};

priority_queue<node>q;
map<string,string>p;

string parent(string x){
    return (p[x].compare(x) == 0) ? x : parent(p[x]);
}

int mst(string src,string des){
    int res=inf;
    while(1){
        node n=q.top();
        q.pop();
        string u=parent(n.u);
        string v=parent(n.v);
        if(u.compare(v)!=0){
            if(res>n.w) res=n.w;
            p[v]=u;
        }
        u=parent(src);
        v=parent(des);
        if(u.compare(v)==0){
            break;
        }
    }
    return res;
}

int main(){


    int n,r,T=0;
    while( scd(n,r) == 2){
        if(n==0 && r==0) break;
        string u,v;
        int w;
        for(int i=0;i<r;i++){
            cin >> u >> v >> w;
            q.push(node(u,v,w));
            p[u]=u;
            p[v]=v;
        }
        cin >> u >> v ;
        cout << "Scenario #" << ++T << endl;
        if( (p[u].compare("")==0 || p[v].compare("")==0) || r==0 ){
            cout << "0 tons" << endl << endl;
        }
        else{
            cout <<  mst(u,v) << " tons" << endl << endl;
        }
        while(!q.empty()) q.pop();
        p.clear();
    }
    return 0;
}
