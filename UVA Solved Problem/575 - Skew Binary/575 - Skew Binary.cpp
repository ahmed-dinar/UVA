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
    char n[1000000];
    while(gets(n))
    {
        if(strcmp(n,"0") == 0)
            break;
        long long k=1,ans=0;

        for(long long i=strlen(n)-1; i>=0; i--){
            long long p = (n[i]-48);
            ans = ans + (p * (pow(2,k) - 1) );
            k++;
        }
        cout << ans<< endl;
    }
    return 0;
}



