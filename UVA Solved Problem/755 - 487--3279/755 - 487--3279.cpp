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

map<char,char>value;
map<string,int>total;
map<string,int>iscount;
vector<string>numbers;

struct icompare_char {
  bool operator()(char c1, char c2) {
    return std::toupper(c1) < std::toupper(c2);
  }
};

struct compare { //from internet
  bool operator()(std::string const& s1, std::string const& s2) {
    if (s1.length() > s2.length())
      return true;
    if (s1.length() < s2.length())
      return false;
    return std::lexicographical_compare(s1.begin(), s1.end(),s2.begin(), s2.end(),icompare_char());
  }
};

void setValue(){
    value['A'] = '2';
    value['B'] = '2';
    value['C'] = '2';
    value['D'] = '3';
    value['E'] = '3';
    value['F'] = '3';
    value['G'] = '4';
    value['H'] = '4';
    value['I'] = '4';
    value['J'] = '5';
    value['K'] = '5';
    value['L'] = '5';
    value['M'] = '6';
    value['N'] = '6';
    value['O'] = '6';
    value['P'] = '7';
    value['R'] = '7';
    value['S'] = '7';
    value['T'] = '8';
    value['U'] = '8';
    value['V'] = '8';
    value['W'] = '9';
    value['X'] = '9';
    value['Y'] = '9';
}

string format(string num){
    int sz = num.size();
    int hy=0;
    string gen = "";
    for(int i=0; i<sz; i++){
        if(num[i]>=65 && num[i]<=90){
            if(hy==3)
                gen += "-";
            gen += value[num[i]];
            hy++;
        }
        else if(num[i]>=48 && num[i]<=57){
            if(hy==3)
                gen += "-";
            gen += num[i];
            hy++;
        }
    }
    return gen;
}

int main()
{
    setValue();
    int t;
    scanf("%d",&t);
    for(int T=0; T<t; T++){
        if(T)
            printf("\n");
        int n,tot=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            string tel;
            cin >> tel;
            tel = format(tel);
            total[tel]++;
            if(total[tel]>1){
                if(iscount[tel]==0){
                    iscount[tel] = 1;
                    numbers.push_back(tel);
                    tot++;
                }
            }
        }
        if(tot>0){
            sort(numbers.begin(), numbers.end(), compare());
            for(int i=0; i<tot; i++){
                printf("%s %d\n",numbers[i].c_str(),total[numbers[i]]);
            }
        }
        else{
            printf("No duplicates.\n");
        }
        total.clear();
        iscount.clear();
        numbers.clear();
    }
    return 0;
}

