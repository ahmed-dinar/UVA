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



int clock(int h1,int h2,int s1,int s2,int temp1,int temp2,int temp3,int temp4)
{
    int co=1;
    while(1)
    {
        s2++;
        if(s2 == 10)
        {
                s1++;
                s2=0;
                if(s1==6)
                {
                    h2++;
                    s1 = 0;
                    if( h1 == 2)
                    {
                        if(h2 >= 4)
                        {
                            h1=0;
                            h2=0;
                            s1=0;
                            s2=0;
                        }
                    }
                    else if(h2 == 10)
                    {
                        h1++;
                        h2=0;
                        if(h1 == 3)
                        {
                            h1=0;
                            h2=0;
                            s1=0;
                            s2=0;
                        }
                    }
                }
        }

        if( temp1==h1 && temp2==h2 && temp3==s1 && temp4==s2) break;
        co++;
    }
    return co;
}


int main()
{
    int H1,M1,H2,M2;
    while(scanf("%d %d %d %d",&H1,&M1,&H2,&M2) == 4)
    {
        if(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) break;
        if(H1 == H2 && M1 == M2){
            printf("0\n");
            continue;
        }
        int ans = clock(H1/10,H1%10,M1/10,M1%10,H2/10,H2%10,M2/10,M2%10);
        printf("%d\n",ans);
    }
    return 0;
}
