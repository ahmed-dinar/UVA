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

int repeat[5000]={0};


void pre()
{
    for(int i=1; i<=5000; i++){

         int temp = i;
         int fl = 1;
         int flag[5000]={0};
         while(temp!=0){
            if(flag[temp%10] > 0)
            {
                fl = 0;
                break;
            }
            flag[temp%10]++;
            temp = temp/10;
         }
         if(fl != 0){
            repeat[i] = 1;
         }
    }
}


int main()
{
    pre();
    int n,m;
    while(scanf("%d %d",&n,&m) == 2){
        int co=0;
        for(int j=n; j<=m; j++){

            if(repeat[j] == 1){
                co++;
            }
        }
        cout<< co << endl;
    }
    return 0;
}
