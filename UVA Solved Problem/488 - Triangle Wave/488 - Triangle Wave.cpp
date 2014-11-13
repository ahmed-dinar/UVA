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

void wave(int n){
    for(int i=1; i<=n;i++){
        for(int j=1; j<=i; j++)
            printf("%d",i);
        printf("\n");
    }
    for(int i=n-1; i>=1;i--){
        for(int j=1; j<=i; j++)
            printf("%d",i);
        printf("\n");
    }
}

int main()
{
    int t,a,f;
    scanf("%d",&t);
    int tm=t;
    while(t--){
        scanf("%d %d",&a,&f);
        for(int k=0; k<f; k++){
            wave(a);
            if(k!=f-1)
                printf("\n");
        }
        if(t)
            printf("\n");
    }
	return 0;
}











