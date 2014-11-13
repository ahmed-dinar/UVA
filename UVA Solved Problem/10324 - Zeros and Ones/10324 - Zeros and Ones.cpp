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

void swp(int *x,int *y)
{
    int tm=*x;
    *x = *y;
    *y = tm;
}

int main()
{
    char zo[1000010];
    int q,ln,c,a,b,ca=0;
    while( scanf("%s",zo) == 1){
        ln=strlen(zo);
        int fl[1000010]={0};
        c=1;
        for(int i=0; i<ln; i++){
            if(zo[i] == '1'){
                fl[i]=c;
                i++;
                while(zo[i] == '0'){
                    fl[i]=c;
                    i++;
                }
                c++;
                i=i-1;
            }
        }
        scanf("%d",&q);
        printf("Case %d:\n",++ca);
        while(q--){
            scanf("%d %d",&a,&b);
            if(a==b){
                printf("Yes\n");
                continue;
            }
            if(a>b)
                swp(&a,&b);
            int k = fl[b]-fl[a-1];
            int dis=b-a+1;
            if(k == 0)
                printf("Yes\n");
            else if(k == dis)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}

