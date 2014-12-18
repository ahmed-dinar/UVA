#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
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

#define eps 0.0000000001
#define pr pair<int,int>
#define mp make_pair
#define ss second
#define fi first
#define i64 long long
#define nl printf("\n")
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define REP(i,n) for(int i=0;i<n; i++)
#define FOR(i,k,n) for(int i=k;i<=n; i++)
#define fr(i,k,n) for(int i=k;i<n; i++)
#define MAX 2005
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

map<int,map<char,int> >solved;
map<char,pair<int,int> >last_blood;

int main()
{
    filein;

    int n,t,m;
    while( scanf("%d %d %d",&n,&t,&m) == 3 ){
        int time,id;
        char problem[3],verdict[10];
        for(char i='A'; i<='L'; i++) last_blood[i].fi = -1;
        while(m--){
            scanf("%d %d %s %s",&time,&id,problem,verdict);
            if( strcmp(verdict,"Yes") == 0 ){
                if( !solved[id][problem[0]] ){
                    solved[id][problem[0]] = 1;
                    last_blood[problem[0]].fi = time;
                    last_blood[problem[0]].ss = id;
                }
            }
        }
        for(int ch=0; ch<n; ch++){
            char i = (char)ch+'A';
            if( last_blood[i].fi == -1 )
                printf("%c - -\n",i);
            else
                printf("%c %d %d\n",i,last_blood[i].fi,last_blood[i].ss);
        }
        solved.clear();
    }
    return 0;
}

