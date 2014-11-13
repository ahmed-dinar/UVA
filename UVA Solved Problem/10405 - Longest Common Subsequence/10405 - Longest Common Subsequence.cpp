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

int dp[1010][1010];
char x[1010],y[1010];

int rec(int i,int j){
    if(x[i]=='\0' || y[j]=='\0') return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int cmn=0;
    if(x[i]==y[j]) cmn=1+rec(i+1,j+1);
    else{
        int a=rec(i+1,j);
        int b=rec(i,j+1);
        cmn=max(a,b);
    }
    return dp[i][j]=cmn;
}

int main(){
    while(gets(x)){
        gets(y);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",rec(0,0));
    }
    return 0;
}



