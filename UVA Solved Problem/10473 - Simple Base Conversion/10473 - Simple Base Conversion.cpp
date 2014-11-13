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


void hexa(long n)
{
    vector<long>in;
    deque<char>ch;
    while(n != 0)
    {
        int k=n%16;
        n=n/16;
        if(k==10){
            in.push_back(-1);
            ch.push_back('A');
        }
        else if(k==11){
            in.push_back(-1);
            ch.push_back('B');
        }
        else if(k==12){
            in.push_back(-1);
            ch.push_back('C');
        }
        else if(k==13){
            in.push_back(-1);
            ch.push_back('D');
        }
        else if(k==14){
            in.push_back(-1);
            ch.push_back('E');
        }
        else if(k==15){
            in.push_back(-1);
            ch.push_back('F');
        }
        else{
            in.push_back(k);
        }
    }
    int sz=in.size();
    for(int i=sz-1; i>=0; i--)
    {
        if(in[i] == -1){
            cout << ch.back();
            ch.pop_back();
        }
        else
            cout << in[i];
    }
    printf("\n");
}

void deci(char n[])
{
   int ln=strlen(n);
   int power=0;
   long d=0;
   for(int i=ln-1; i>=2; i--,power++)
   {
        if(!isdigit(n[i]))
        {
            if(n[i]=='A'){
                d += (10*pow(16,power));
            }
            else if(n[i]=='B'){
                d += (11*pow(16,power));
            }
            else if(n[i]=='C'){
                d += (12*pow(16,power));
            }
            else if(n[i]=='D'){
                d += (13*pow(16,power));
            }
            else if(n[i]=='E'){
                d += (14*pow(16,power));
            }
            else if(n[i]=='F'){
                d += (15*pow(16,power));
            }
        }
        else{
            int k = n[i]-'0';
            d += (k*pow(16,power));
        }
   }
   printf("%ld\n",d);
}


int main()
{
    char N[15];
    while(  gets(N) )
    {
        if(N[0]=='-')
            break;

        if(N[1]=='x')
            deci(N);
        else{
            long p=atol(N);
            printf("0x");
            hexa(p);
        }
    }
    return 0;
}
