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

struct node
{
    i64 complete_word;
    node *next[27];
    node() {
        complete_word = 0;
    for(int i=0;i<26; i++)
        next[i]=NULL;
    }
};

node *root;

i64 Insert(char *s,int sz){
    node *word = root;
    i64 total=0,temp,res=0;
    for(int i=0;i<sz;i++){
        int w=s[i]-'0';
        if(word->next[w]==NULL){
            word->next[w] = new node();
        }
        word = word->next[w];
        word->complete_word++;
        res = Max(res,word->complete_word*(i+1));
        /*if(total==0){
            total = word->complete_word;
            temp = total;
        }
        else{
            if(temp==word->complete_word){
                total += word->complete_word;
            }
            else{
                res = Max(res,total);
                total = 0;
            }
        }*/
    }
    return res;
}

void Clear(node *n){
    for(int i=0;i<26; i++)
        if(n->next[i])
            Clear(n->next[i]);
    delete(n);
}

/*int Search(char *s,int sz){
    node *word = root;
    for(int i=0;i<sz;i++){
        int w=s[i]-'0';
        if(word->next[w]==NULL) return false;
        word = word->next[w];
    }
    return word->complete_word;
}
*/

int main()
{
    //filein;
    //fileout;;

    int t;
    sc(t);
    while(t--){
        int n;
        i64 res=0;
        root = new node();
        char s[210];
        sc(n);
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int ln=strlen(s);
            i64 r = Insert(s,ln);
            res = Max(res,r);
        }
        printf("%lld\n",res);
        Clear(root);
    }
    return 0;
}

