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
#define MAX 15
#define oo 2000000000.0
#define MOD 1000000007

typedef long long i64;
typedef pair<int,int> pri;
typedef vector<int> vci;
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

map<string,int>freq;
vector<string>dictionary;

bool com(string x,string y){
    return x<y;
}

int main(){

    //filein;

    string s,pre="";
    int bc=0;
    while( getline(cin,s) ){
        string cur="";
        for(int i=0,k=0; ; i++){
            if( s[i]=='\0' ){
                if(s[i-1]!='-'){
                    pre.append(cur);
                    if( pre!="" && !freq[pre]){
                        freq[pre]=1;
                        dictionary.pb(pre);
                    }
                    bc=0;
                    pre="";
                }
                else{
                    pre.append(cur);
                    bc=1;
                }
                break;
            }
            else if( s[i]=='-' && s[i+1]!='\0' ){
                cur+=s[i];
            }
            else if( isupper(s[i]) || islower(s[i]) )
                cur+=tolower(s[i]);
            else if(s[i]!='-'){
                if(k==0 && bc ){
                    pre.append(cur);
                    if(pre!="" && !freq[pre]){
                        freq[pre]=1;
                        dictionary.pb(pre);
                    }
                }
                else if( cur!="" && !freq[cur]){
                    freq[cur]=1;
                    dictionary.pb(cur);
                }
                cur="";
                pre="";
                k=1;
                bc=0;
            }
        }
    }
    sort(all(dictionary), com);
    REP(i,dictionary.sz)
        printf("%s\n",dictionary[i].c_str());
    return 0;
}
