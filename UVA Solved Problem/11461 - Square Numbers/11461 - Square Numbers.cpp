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

int flag[100001];

void squre(){
    int sq[100001]={0};
    for(int i=1;; i++){
        if(i*i>100000)
            break;
        sq[i*i]=1;
    }
    int f=1;
    for(int i=1; i<=100000; i++){
        if(sq[i] == 1){
            flag[i]=f;
            i++;
            while(sq[i] == 0){
                flag[i]=f;
                i++;
            }
            i=i-1;
            f++;
        }
    }
}

int main()
{
    squre();
    int a,b;
    while( scanf("%d %d",&a,&b) == 2){
        if(a==0 && b==0)
            break;
        printf("%d\n",flag[b]-flag[a-1]);
    }
    return 0;
}
