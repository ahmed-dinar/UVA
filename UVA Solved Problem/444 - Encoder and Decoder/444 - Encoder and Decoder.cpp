#include<bits/stdc++.h>

using namespace std;

#define pf(x) printf("%d",x)
#define pfd(x,y) printf("%d %d",x,y)
#define pfl(x) printf("%ld",x)
#define pfll(x) printf("%lld",x)
#define pfllu(x)
#define nl printf("\n")
#define cs(x) printf("Case %d: ",x)
#define csn(x) printf("Case %d:\n",x)
#define all(x) x.begin(),x.end()
#define Find(x,n) find(all(x),n)
#define pi acos(-1.0)
#define i64 long long
#define pb(x) push_back(x)
#define mset(x,v) memset(x,v,sizeof(x))
#define sc(n) scanf("%d",&n)
#define scl(n) scanf("%ld",&n)
#define scll(n) scanf("%lld",&n)
#define scd(n,m) scanf("%d %d",&n,&m)
#define scdl(n,m) scanf("%ld %ld",&n,&m)
#define scdll(n,m) scanf("%lld %lld",&n,&m)
#define filein freopen("in.txt","r",stdin)
#define fileout freopen("my.txt","w",stdout)
#define inf 100000
#define MAX 50001
#define MOD 4294967296

bool isUpper(char ch){ return ( ch>='A' && ch<='Z' ) ?  true :  false; }
bool isLower(char ch){ return ( ch>='a' && ch<='z')  ?  true :  false; }
bool isLetter(char ch){ return ( ch>='A' && ch<='Z' || ch>='a' && ch<='z') ?  true :  false; }
bool isDigit(char ch){ return ( ch>='0' && ch<='9') ?  true :  false; }
char toLower(char ch){ return (isUpper(ch)) ? (ch+32) : ch; }
char toUpper(char ch){ return (isLower(ch)) ? (ch-32) : ch; }

template<class T>bool isEven(T a){ return (a%2==0);}
template<class T>T sq(T a){ return (a*a); }
template<class T>T gcd(T a,T b){ return b==0 ? a : gcd(b,a%b); }
template<class T>T lcm(T a,T b){ return (a/gcd(a,b))*b; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>T Max(T n,T p) { return (n>=p) ? n : p; }
template<class T>T ABS(T n) { return (n<0) ?  (-n) :  n; }

map<char,string>ascii;
map<int,char>reascii;

void pre(){
    ascii['a']="79";
    ascii['b']="89";
    ascii['c']="99";
    ascii['d']="001";
    ascii['e']="101";
    ascii['f']="201";
    ascii['g']="301";
    ascii['h']="401";
    ascii['i']="501";
    ascii['j']="601";
    ascii['k']="701";
    ascii['l']="801";
    ascii['m']="901";
    ascii['n']="011";
    ascii['o']="111";
    ascii['p']="211";
    ascii['q']="311";
    ascii['r']="411";
    ascii['s']="511";
    ascii['t']="611";
    ascii['u']="711";
    ascii['v']="811";
    ascii['w']="911";
    ascii['x']="021";
    ascii['y']="121";
    ascii['z']="221";
    ascii['A']="56";
    ascii['B']="66";
    ascii['C']="76";
    ascii['D']="86";
    ascii['E']="96";
    ascii['F']="07";
    ascii['G']="17";
    ascii['H']="27";
    ascii['I']="37";
    ascii['J']="47";
    ascii['K']="57";
    ascii['L']="67";
    ascii['M']="77";
    ascii['N']="87";
    ascii['O']="97";
    ascii['P']="08";
    ascii['Q']="18";
    ascii['R']="28";
    ascii['S']="38";
    ascii['T']="48";
    ascii['U']="58";
    ascii['V']="68";
    ascii['W']="78";
    ascii['X']="88";
    ascii['Y']="98";
    ascii['Z']="09";
    ascii[' ']="23";
    ascii['!']="33";
    ascii[',']="44";
    ascii['.']="64";
    ascii[':']="85";
    ascii[';']="95";
    ascii['?']="36";
    reascii[65]='A';
    reascii[66]='B';
    reascii[67]='C';
    reascii[68]='D';
    reascii[69]='E';
    reascii[70]='F';
    reascii[71]='G';
    reascii[72]='H';
    reascii[73]='I';
    reascii[74]='J';
    reascii[75]='K';
    reascii[76]='L';
    reascii[77]='M';
    reascii[78]='N';
    reascii[79]='O';
    reascii[80]='P';
    reascii[81]='Q';
    reascii[82]='R';
    reascii[83]='S';
    reascii[84]='T';
    reascii[85]='U';
    reascii[86]='V';
    reascii[87]='W';
    reascii[88]='X';
    reascii[89]='Y';
    reascii[90]='Z';
    reascii[97]='a';
    reascii[98]='b';
    reascii[99]='c';
    reascii[100]='d';
    reascii[101]='e';
    reascii[102]='f';
    reascii[103]='g';
    reascii[104]='h';
    reascii[105]='i';
    reascii[106]='j';
    reascii[107]='k';
    reascii[108]='l';
    reascii[109]='m';
    reascii[110]='n';
    reascii[111]='o';
    reascii[112]='p';
    reascii[113]='q';
    reascii[114]='r';
    reascii[115]='s';
    reascii[116]='t';
    reascii[117]='u';
    reascii[118]='v';
    reascii[119]='w';
    reascii[120]='x';
    reascii[121]='y';
    reascii[122]='z';
    reascii[32]=' ';
    reascii[33]='!';
    reascii[44]=',';
    reascii[46]='.';
    reascii[58]=':';
    reascii[59]=';';
    reascii[63]='?';
}


int main()
{
    pre();
    string a;
    while( getline(cin,a) ){
        int sz=a.size();
        for(int i=sz-1; i>=0; i--){
            if( a[i]>=48 && a[i]<=57 ){
                int k=0;
                k = k*10+(a[i]-48);
                i--;
                k = k*10+(a[i]-48);
                if(reascii[k] == 0){
                    i--;
                    k = k*10+(a[i]-48);
                }
                cout << reascii[k];
            }
            else
                cout << ascii[a[i]];
        }
        cout << endl;
    }
	return 0;
}
