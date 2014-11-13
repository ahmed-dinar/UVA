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
    char c[82],test[10],symbol;
    float n,k;
    gets(test);
    int t=atoi(test),ln;
    while(t--){
        gets(c);
        ln=strlen(c);
        n=0;
        for(int i=0; i<ln; i++){
            symbol=c[i];
            if(!isdigit(c[i+1])){
                k=1;
            }
            else{
                string j;
                i++;
                while(isdigit(c[i])){
                    j.push_back(c[i]);
                    i++;
                }
                k=atof(j.c_str());
                i=i-1;
            }
            if(symbol=='C')
                n=n+(k*12.01);
            else if(symbol=='H')
                n=n+(k*1.008);
            else if(symbol=='O')
                n=n+(k*16.00);
            else if(symbol=='N')
                n=n+(k*14.01);
        }
        printf("%.3f\n",n);
    }
    return 0;
}
