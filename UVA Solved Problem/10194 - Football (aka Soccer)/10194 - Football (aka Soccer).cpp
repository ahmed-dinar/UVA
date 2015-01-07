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
template<class T>T Pow(T n,T p) { T res=n; for(T i=1;i<p; i++){ res *= n; } return res; }
template<class T>bool isPrime(T n){ for(T i=2; i*i<=n; i++){ if(n%i==0) return false; } return true; }

struct score
{
    string name;
    int points,played,wins,goals_scored,goals_dif;
    score(string name,int points,int played,int wins,int goals_scored,int goals_dif) : name(name),points(points),played(played),wins(wins),goals_scored(goals_scored),goals_dif(goals_dif) {}
    bool operator<( const score& p ) const {
        if( points == p.points ){
            if( wins==p.wins ){
                if( goals_dif == p.goals_dif ){
                    if( goals_scored == p.goals_scored ){
                        if( played == p.played ){
                            string a1="",a2="";
                            for(int i=0;name[i]!='\0';i++) a1+=tolower(name[i]);
                            for(int i=0;p.name[i]!='\0';i++) a2+=tolower(p.name[i]);
                            return a1 < a2 ;
                        }
                        else
                            return played < p.played;
                    }
                    else
                        return goals_scored > p.goals_scored;
                }
                else
                    return goals_dif > p.goals_dif;
            }
            else
                return wins > p.wins;
        }
        else
            return points > p.points;
    }
};

map<string,int>points,played,wins,ties,losses,goals_scored,goals_against;
vector<score>score_board;

void getResult(string result){
    int i;
    string s="",team1;
    int g1,g2;
    for(i=0;  ;i++){
        if(result[i]=='@'){
            g1=atoi(s.c_str());
            s="";
            break;
        }
        else if( result[i]=='#' ){
            team1=s;
            s="";
        }
        else
            s+=result[i];
    }
    for(int j=i+1;result[j]!='\0';j++){
        if( result[j]=='#' ){
            g2=atoi(s.c_str());
            s="";
        }
        else
            s+=result[j];
    }
    played[team1]++;
    goals_scored[team1]+=g1;
    goals_against[team1]+=g2;
    played[s]++;
    goals_scored[s]+=g2;
    goals_against[s]+=g1;
    if( g1==g2 ){
        points[team1]++;
        ties[team1]++;
        points[s]++;
        ties[s]++;
    }
    else if( g1>g2 ){
        points[team1]+=3;
        wins[team1]++;
        losses[s]++;
    }
    else{
        points[s]+=3;
        wins[s]++;
        losses[team1]++;
    }
}

int main(){

    //filein;

    int t,T=0,n,games;
    string TourName,result;
    string team[35];
    scanf("%d\n",&t);
    while(t--){
        getline(cin,TourName);
        scanf("%d\n",&n);
        REP(i,n)
            getline(cin,team[i]);

        scanf("%d\n",&games);
        while(games--){
            getline(cin,result);
            getResult(result);
        }
        REP(i,n)
            score_board.pb( score(team[i],points[team[i]],played[team[i]],wins[team[i]],goals_scored[team[i]],goals_scored[team[i]]-goals_against[team[i]]) );
        sort( all(score_board) );
        if(T) nl;
        printf("%s\n",TourName.c_str());
        REP(i,score_board.sz){
            score res=score_board[i];
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,res.name.c_str(),res.points,res.played,res.wins,ties[res.name],losses[res.name],res.goals_dif,res.goals_scored,goals_against[res.name]);
        }
        score_board.cl;points.cl;played.cl;wins.cl;ties.cl;losses.cl;goals_scored.cl;goals_against.cl;
        T=1;
    }
    return 0;
}
