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
#define ss second
#define fi first

#define sc(n) scanf("%d",&n)
#define nl puts("")

#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define For(i,k,n) for(int i=k;i<n; i++)

#define EPS 1e-9
#define pi acos(-1.0)
#define MAX 105
#define oo 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<i64> vcll;
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct result
{
    int contestant,solved_problems,penalty;
    result(int contestant,int solved_problems,int penalty) : contestant(contestant),solved_problems(solved_problems),penalty(penalty) {}
    bool operator<( const result& p ) const {
        if( solved_problems == p.solved_problems ){
            if( penalty==p.penalty ){
                return contestant > p.contestant;
            }
            else{
                return penalty > p.penalty;
            }
        }
        else{
            return solved_problems < p.solved_problems;
        }
    }
};

int penalty[MAX];
int timess[MAX][15];
int solved[MAX][15];
int solved_problems[MAX];

int main()
{
    //filein;
    //fileout;

    string s;
    int t,contestant,problem ,time,T=0;
    char verdict[3];
    scanf("%d\n",&t);
    while( t-- ){
        set<int>participate;
        priority_queue<result>q;
        REP(i,MAX) penalty[i]=0,solved_problems[i]=0;
        memset(solved,0,sizeof(solved));
        memset(timess,0,sizeof(solved));
        while( getline(cin,s) ){
            if( s.compare("") == 0 ) break;
            sscanf(s.c_str(),"%d %d %d %s",&contestant ,&problem ,&time,verdict);
            participate.insert(contestant);
            if( !solved[contestant][problem] && verdict[0]=='C' ){
                solved[contestant][problem]=1;
                solved_problems[contestant]++;
                penalty[contestant]+=time+timess[contestant][problem];
            }
            else if( !solved[contestant][problem] &&  verdict[0]=='I' ){
                timess[contestant][problem]+=20;
            }
        }
        for(set<int>::iterator it=participate.begin(); it!=participate.end(); ++it){
            int p=*it;
            q.push( result(p,solved_problems[p],penalty[p]) );
        }
        if(T) nl;
        while(!q.empty()){
            result qq=q.top(); q.pop();
            printf("%d %d %d\n",qq.contestant,qq.solved_problems,qq.penalty);
        }
        T=1;
    }
    return 0;
}
