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

#define ll long long

map<string,int>iscount;
map<string,ll>total;
vector<string>numbers;

int main()
{
    string num;
    ll tot=0;
    while(cin>>num){
        if(iscount[num]==0){
           iscount[num] = 1;
           numbers.push_back(num);
           tot++;
        }
        total[num]++;
    }
    for(ll i=0; i<tot; i++){
        printf("%s %lld\n",numbers[i].c_str(),total[numbers[i]]);
    }
    return 0;
}

