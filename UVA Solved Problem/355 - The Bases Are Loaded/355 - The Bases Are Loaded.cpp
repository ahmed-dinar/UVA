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
typedef vector<pri> vcp;

template<class T>bool iseq(T a,T b){return fabs(a-b)<EPS;}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return (b==0) ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>T Pow(T n,T p) { if(p==0) return 1; T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

char n[1000];
int skip;

void convert(i64 num,i64 base){
    vector<i64>in;
    deque<char>ch;
    while(num){
        i64 k=num%base;
        num=num/base;
        if(k==10){
            in.pb(-1);
            ch.pb('A');
        }
        else if(k==11){
            in.pb(-1);
            ch.pb('B');
        }
        else if(k==12){
            in.pb(-1);
            ch.pb('C');
        }
        else if(k==13){
            in.pb(-1);
            ch.pb('D');
        }
        else if(k==14){
            in.pb(-1);
            ch.pb('E');
        }
        else if(k==15){
            in.pb(-1);
            ch.pb('F');
        }
        else
            in.pb(k);
    }
    int szz=in.sz;
    for(int i=szz-1; i>=0; i--){
        if(in[i] == -1){
            cout << ch.back();
            ch.pop_back();
        }
        else
            cout << in[i];
    }
}

int correctBase(i64 base){
    i64 c;
    for(int i=0;n[i]!='\0'; i++){
        if( isdigit(n[i]) )
            c=n[i]-'0';
        else
            c=n[i]-'A'+10;

         if(c>=base) return 0;
    }
    return 1;
}

i64 deci(i64 base){
   int ln=strlen(n)-1;
   i64 d=0;
   i64 power=0;
   for(int i=ln; i>=skip; i--,power++){
        i64 p=Pow(base,power);
        i64 digit;
        if(!isdigit(n[i]))
            digit=(n[i]-'A'+10);
        else
            digit=(n[i]-'0');
        d += ( digit*p );
   }
   return d;
}

int main(){

    //filein;

    i64 cbase,tbase;
    while( scanf("%lld %lld %s",&cbase,&tbase,n) == 3 ){
        if(correctBase(cbase)){
            skip=0;
            while(n[skip]=='0'){
                skip++;
            }
            if( strcmp(n,"0") == 0 ){
                printf("%s base %lld = %s base %lld\n",n,cbase,n,tbase);
            }
            else if(cbase==tbase){
                printf("%s base %lld = ",n,cbase);
                int i=skip;
                while(n[i]!='\0'){
                    printf("%c",n[i]);
                    i++;
                }
                printf(" base %lld\n",tbase);
            }
            else if( cbase==10 ){
                i64 dec=atoll(n);
                printf("%s base %lld = ",n,cbase);
                convert(dec,tbase);
                printf(" base %lld\n",tbase);
            }
            else if(tbase==10){
                i64 dec=deci(cbase);
                printf("%s base %lld = %lld base %lld\n",n,cbase,dec,tbase);
            }
            else{
                i64 dec=deci(cbase);
                printf("%s base %lld = ",n,cbase);
                convert(dec,tbase);
                printf(" base %lld\n",tbase);
            }
        }
        else{
            printf("%s is an illegal base %lld number\n",n,cbase);
        }
    }
    return 0;
}
