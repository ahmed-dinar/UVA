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

#define EPS 0.0000000001
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
#define MAX 20
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

void print(string s){
    for(int i=0,n=0; s[i]!='\0'; i++){
        if( s[i]>=48 && s[i]<=57 )
            n += (s[i]-'0');
        else if(s[i]=='!')
                puts("");
        else{
            REP(j,n){
                if(s[i]=='b')
                    printf(" ");
                else
                    printf("%c",s[i]);
            }
            n=0;
        }
    }
    puts("");
}

int main()
{
    filein;
    //fileout;

    string s;
    while(getline(cin,s)){
        if(s.compare("")!=0)
            print(s);
        else
            puts("");
        while(getline(cin,s)){
            if(s.compare("")==0){
                puts("");
                break;
            }
            else print(s);
        }
     }
    return 0;
}
