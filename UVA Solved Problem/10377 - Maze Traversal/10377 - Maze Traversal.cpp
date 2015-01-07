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
#define MAX 65
#define inf 2000000000
#define MOD 100000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

char maze[MAX][MAX];

int main()
{
    //filein;
    //fileout;

    int t;
    sc(t);
    while(t--){
        int r,c,x,y,quit=0;
        char facing='N';
        string command;
        scanf("%d %d\n",&r,&c);
        REP(i,r){
            gets(maze[i]);
        }
        scanf("%d %d\n",&x,&y);
        x=x-1; y=y-1;
        while(getline(cin,command)){
            for(int i=0; command[i]!='\0' ;i++){
                if(command[i]=='Q'){
                    quit=1;
                    break;
                }
                else if(command[i]=='R'){
                    if(facing=='N') facing='E';
                    else if(facing=='E') facing='S';
                    else if(facing=='S') facing='W';
                    else if(facing=='W') facing='N';
                }
                else if(command[i]=='L'){
                    if(facing=='N') facing='W';
                    else if(facing=='W') facing='S';
                    else if(facing=='S') facing='E';
                    else if(facing=='E') facing='N';
                }
                else if(command[i]=='F'){
                    int rr,cc;
                    if(facing=='N'){
                         rr=x-1;
                         cc=y;
                    }
                    else if(facing=='E'){
                         rr=x;
                         cc=y+1;
                    }
                    else if(facing=='S'){
                         rr=x+1;
                         cc=y;
                    }
                    else if(facing=='W'){
                         rr=x;
                         cc=y-1;
                    }
                    if(rr>=0&&rr<r&&cc>=0&&cc<c){
                        if(maze[rr][cc]!='*'){
                            x=rr;
                            y=cc;
                        }
                    }
                }
            }
            if(quit) break;
        }
        printf("%d %d %c\n",x+1,y+1,facing);
        if(t) puts("");
    }
    return 0;
}
