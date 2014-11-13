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
	int t;
	cin >> t;
	while(t--)
    {
        int hour,minitue;
        char ch;
        scanf("%d%c%d",&hour,&ch,&minitue);
        if(minitue == 0)
        {
            if(hour != 12)
                hour = 12 - hour;

            if(hour<10)
                printf("0%d:00\n",hour);
            else
                printf("%d:00\n",hour);
        }
        else
        {
            if(hour == 12)
                hour = 11;
            else if(hour == 11)
                hour = 12;
            else
                hour = 12 - hour-1;
            minitue = 60 - minitue;
            if(hour<10)
            {
                if(minitue<10)
                    printf("0%d:0%d\n",hour,minitue);
                else
                    printf("0%d:%d\n",hour,minitue);
            }
            else
            {
                if(minitue<10)
                    printf("%d:0%d\n",hour,minitue);
                else
                    printf("%d:%d\n",hour,minitue);
            }
        }
    }

    return 0;
}





















