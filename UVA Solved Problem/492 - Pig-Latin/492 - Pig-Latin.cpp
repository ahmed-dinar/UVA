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
#include<unistd.h>

using namespace std;

#define ll long long

bool vowel(char x){
    if(x=='a'||x=='A'||x=='e'||x=='E'||x=='i'||x=='I'||x=='o'||x=='O'||x=='u'||x=='U')
        return true;

    return false;
}

int main()
{
    string s;
    char c[100000],vow;
    while( getline(cin,s) ){
        int l=s.size(),j=0,fl=0;
        for(int i=0; i<l; i++){

            if( (s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122) ){
                if(fl==0){
                    fl=1;
                    vow=s[i];
                }
                c[j]=s[i];
                j++;
            }
            else
            {
                if(j>0){
                    c[j]='\0';
                    if(!vowel(vow)){
                        for(int k=1; k<j; k++)
                            printf("%c",c[k]);
                        printf("%c%s",vow,"ay");
                    }
                    else{
                        printf("%s",c);
                        printf("%s","ay");
                    }
                    j=0;
                    fl=0;
                }
                printf("%c",s[i]);
            }
        }
        if(j>0){
            c[j]='\0';
            if(!vowel(vow)){
                for(int k=1; k<j; k++)
                    printf("%c",c[k]);
                printf("%c%s",vow,"ay");
            }
            else{
                printf("%s",c);
                printf("%s","ay");
            }
        }
        printf("\n");
    }
    return 0;
}



