#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<deque>
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
    char test[10];
    char ch[130];
    vector<char>Q;
    gets(test);
    int t=atoi(test),flag;
    while(t--){
        gets(ch);
        if(ch==""){
            printf("Yes\n");
            continue;
        }
        int ln=strlen(ch);
        flag=1;
        for(int i=0; i<ln ; i++){
            if(ch[i]=='(' || ch[i]=='['){
                Q.push_back(ch[i]);
            }
            else if(ch[i]==')' && !Q.empty() && Q.back()=='('){
                Q.pop_back();
            }
            else if( ch[i]==')' && ( Q.empty() ||  Q.back()!='(' )){
                flag=0;
                break;
            }
            else if(ch[i]==']' && !Q.empty() && Q.back()=='['){
                Q.pop_back();
            }
            else if( ch[i]==']' && ( Q.empty() ||  Q.back()!='[' )){
                flag=0;
                break;
            }
        }
       if(flag==1 && Q.empty())
            printf("Yes\n");
        else
            printf("No\n");
        Q.clear();
    }
    return 0;
}



