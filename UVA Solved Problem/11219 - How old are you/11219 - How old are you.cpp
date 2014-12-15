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
#define ss second
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
#define MAX 200005
#define inf 2000000000

template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

int d1,d2,m1,m2,yr1,yr2;

void read(){
    char date1[12],date2[12];
    scanf("%s",date1);
    scanf("%s",date2);
    yr1=0;yr2=0;d1=0;d2=0;m1=0;m2=0;
    int i=0;
    while(date1[i]!='/') d1 = d1*10+(date1[i++]-'0');
    ++i;
    while(date1[i]!='/') m1 = m1*10+(date1[i++]-'0');
    ++i;
    while(date1[i]!='\0') yr1 = yr1*10+(date1[i++]-'0');
    i=0;
    while(date2[i]!='/') d2 = d2*10+(date2[i++]-'0');
    ++i;
    while(date2[i]!='/') m2 = m2*10+(date2[i++]-'0');
    ++i;
    while(date2[i]!='\0') yr2 = yr2*10+(date2[i++]-'0');
}

int Invalid(){
    if(yr1<yr2)
        return 1;
    else if( yr1==yr2 ){
        if(m1<m2)
            return 1;
        else if(m1==m2 && d1<d2)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int calculate(){
    int age = yr1-yr2;
    if( m2>m1 || ( m2==m1 && d2>d1 ) ) --age;
    return age;
}

int main()
{
    filein;
    //fileout;

    int t,T=0;
    sc(t);
    while( t-- ){
        read();
        //cout << d1 << "  " << m1 <<  " " << yr1 << endl;
        //cout << d2 << "  " << m2 <<  " " << yr2 << endl;
        printf("Case #%d: ",++T);
        if( Invalid() )
            printf("Invalid birth date\n");
        else{
            int age = calculate();
            (age>130) ? printf("Check birth date\n") : printf("%d\n",age);
        }
    }
    return 0;
}

