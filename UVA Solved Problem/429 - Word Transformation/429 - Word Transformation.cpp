#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

using namespace std;

#define filein freopen("in.txt","r",stdin)
#define fileout freopen("out.txt","w",stdout)

#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)

#define nFind(v,n) find(all(v),n)==v.end()
#define Find(v,n) find(all(v),n)!=v.end()
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define sz size()
#define cl clear()
#define em empty()
#define ss second
#define fi first

#define sc(n) scanf("%d",&n)
#define nl puts("")

#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 15
#define oo 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<string> vcs;
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

map<string,vcs >g;

void bfs(string src,string des){
    map<string,int>d;
    queue<string>q;
    q.push(src);
    d[src]=1;
    while(!q.em){
        string u=q.front(); q.pop();
        REP(i,g[u].sz){
            string v=g[u][i];
            if(!d[v]){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    printf("%s %s %d\n",src.c_str(),des.c_str(),d[des]-1);
}

int main(){

    //filein;

    int t;
    scanf("%d\n",&t);
    while(t--){
        string s,u,v;
        set<string> w;
        set<string>::iterator it;
        while(getline(cin,s)){
            if(s[0]=='*') break;
            for(it=w.begin(); it!=w.end(); it++){
                string k=*it;
                int sza=k.sz;
                int szb=s.sz;
                if(sza==szb){
                    int dif_char=0;
                    for(int i=0; i<sza; i++){
                        if( s[i]!=k[i] ) dif_char++;
                        if(dif_char>1) break;
                    }
                    if(dif_char==1){
                        g[s].pb(k);
                        g[k].pb(s);
                    }
                }
            }
            w.insert(s);
        }
        while(getline(cin,u)){
            if(u.compare("")==0) break;
            s="";
            for(int i=0;u[i]!='\0';i++){
                if(u[i]==' '){
                    v=s;
                    s="";
                }
                else
                    s+=u[i];
            }
            bfs(v,s);
        }
        if(t) nl;
        for(it=w.begin(); it!=w.end(); it++){
            u=*it;
            g[u].cl;
        }
    }
    return 0;
}
