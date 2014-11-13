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


int main()
{
    string m;
    int len;
    while( scanf("%d",&len)==1 )
    {
        cin >> m;
        int sz=m.size();
        if(sz<=len){
            cout << endl;
            continue;
        }
        map<string,int>mp;
        string ans;
        int mx=0;
        sz=sz-len+1;
        for(int i=0; i<sz; i++){
            int k=i;
            string sub;
            for(int j=0; j<len; j++){
                sub += m[k];
                k++;
            }
            mp[sub]++;
            if(mp[sub]>mx){
                mx=mp[sub];
                ans = sub;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
