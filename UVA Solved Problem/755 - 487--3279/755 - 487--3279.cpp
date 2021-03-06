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
#define MAX 100005
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

map<char,char>m;
map<string,int>freq;

void MAP(){
    m['A']=m['B']=m['C']='2';
    m['D']=m['E']=m['F']='3';
    m['G']=m['H']=m['I']='4';
    m['J']=m['K']=m['L']='5';
    m['M']=m['N']=m['O']='6';
    m['P']=m['R']=m['S']='7';
    m['T']=m['U']=m['V']='8';
    m['W']=m['X']=m['Y']='9';
}

string DEC(string s){
    string x="";
    for(int i=0,k=0;s[i]!='\0';i++){
        if( isdigit(s[i]) ) x+=s[i],k++;
        else if( isupper(s[i]) ) x+=m[s[i]],k++;
        if(k==3) x+='-',k=4;
    }
    return x;
}

bool com(string a,string b){
    return a.compare(b) < 0;
}

int main(){

    filein;

    MAP();
    int t,T=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        set<string>numbers;
        set<string>::iterator it;
        REP(i,n){
            string num;
            cin>>num;
            num=DEC(num);
            freq[num]++;
            numbers.insert(num);
        }
        vector<string>ans;
        for(it=numbers.begin(); it!=numbers.end(); it++){
            string num=*it;
            if(freq[num]>1) ans.pb(num);
        }
        sort( all(ans) , com );
        if(T) nl;
        if(ans.sz==0)
            puts("No duplicates.");
        else
            REP(i,ans.sz)
                printf("%s %d\n",ans[i].c_str(),freq[ans[i]]);
        T=1;
        freq.cl;
    }
    return 0;
}
