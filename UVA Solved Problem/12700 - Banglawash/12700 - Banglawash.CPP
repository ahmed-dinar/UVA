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
#include<time.h>

using namespace std;

int main()
{
    int T,N,ca=0;
    scanf("%d",&T);
    while(T--){
        char m[13];
        scanf("%d",&N);
        scanf("%s",m);
        int b=0,w=0,t=0,a=0;
        for(int i=0; i<N; i++){
            if(m[i]=='B')
                b++;
            else if(m[i]=='W')
                w++;
            else if(m[i]=='T')
                t++;
            else if(m[i]=='A')
                a++;
        }
        if(a==N)
            printf("Case %d: ABANDONED\n",++ca);
        else if(N==b || (b+a == N) )
            printf("Case %d: BANGLAWASH\n",++ca);
        else if(N==w || (w+a == N) )
            printf("Case %d: WHITEWASH\n",++ca);
        else if(a==N)
            printf("Case %d: ABANDONED\n",++ca);
        else if(b>w)
            printf("Case %d: BANGLADESH %d - %d\n",++ca,b,w);
        else if(b<w)
            printf("Case %d: WWW %d - %d\n",++ca,w,b);
        else if(w==b)
            printf("Case %d: DRAW %d %d\n",++ca,b,t);
    }
    return 0;
}
