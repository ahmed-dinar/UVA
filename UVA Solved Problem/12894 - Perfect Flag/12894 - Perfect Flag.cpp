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

#define mp make_pair
#define fr first
#define ss second
#define pf printf
#define pi acos(-1.0)
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
#define MAX 6005
#define inf 2000000.0

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int main()
{
    //filein;

    float rat = (10.0/6.0);
    int t;
    sc(t);
    while(t--){
        int x0,y0,x1,y1,cx,cy,r,x2,y2,x3,y3;
        scanf("%d %d %d %d %d %d %d",&x0,&y0,&x1,&y1,&cx,&cy,&r);
        x2 = x1;
        y2 = y0;
        float len = (float)sqrt(sq(x2-x0)+sq(y2-y0));
        float wid = (float)sqrt(sq(x1-x2)+sq(y1-y2));
        if( fabs( (len/wid) - rat) < 0.00001 ){
            if( fabs( (len/(float)r) - 5.0) < 0.00001 ){
                float ntenth = (9.0*len)/20.0;
                float nln = (float)sqrt(sq(cx-x0));
                if( fabs( nln - ntenth) < 0.00001 ){
                    float mdl = (float)sqrt(sq(cy-y0));
                    if( fabs( mdl - (wid/2.0) ) < 0.00001  ){
                        pf("YES\n");
                    }
                    else{
                        pf("NO\n");
                    }
                }
                else{
                    pf("NO\n");
                }
            }
            else{
                pf("NO\n");
            }
        }
        else{
            pf("NO\n");
        }
    }
    return 0;
}
