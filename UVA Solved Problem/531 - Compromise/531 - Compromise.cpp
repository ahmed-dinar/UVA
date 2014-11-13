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

char x[110][32],y[110][32];
int p,q,space;
int dp[110][110];

int match(int i,int j)
{
    if(i>=p || j>=q) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int c=0;
    if( strcmp(x[i],y[j]) == 0 ){
        c = 1+match(i+1,j+1);
    }
    else{
        int e=match(i+1,j);
        int f=match(i,j+1);
        c=max(e,f);
    }
    return dp[i][j]=c;
}

void print(int i,int j)
{
    if(i>=p || j>=q)
    {
        cout << endl;
        return;
    }
    if( strcmp(x[i],y[j]) == 0 ){
        if(space == 0)
            space =1;
        else
            printf(" ");
        printf("%s",x[i]);
        print(i+1,j+1);
    }
    else{
        if(dp[i+1][j]>dp[i][j+1]) print(i+1,j);
        else
            print(i,j+1);
    }
}

int main()
{
    char a[4000];
    char N[4000],M[4000];
    int ca=0;
    while( cin.getline(a,4000) )
    {
        int flag1=0,flag2=0;
        if(a[0] != '#')
        {
            flag1=1;
            strcat(N,a);
            while( cin.getline(a,4000)  )
            {
                if(a[0] == '#') break;

                strcat(N," ");
                strcat(N,a);
            }
        }

        while(  cin.getline(a,4000) )
        {
            if(a[0] == '#') break;

            strcat(M,a);
            strcat(M," ");
            flag2=1;
        }

        if(flag2==0 && flag1==0)
            continue;

        char *cut;
        cut = strtok(N," ,.';:!/?`~#*-+.'|=_&^%$@");
        p=0;
        while(cut != NULL)
        {
            strcpy(x[p],cut);
            p++;
            cut = strtok(NULL," ,.';:!/?`~#*-+.'|=_&^%$@");
        }
        cut = strtok(M," ,.';:!/?`~#*-+.'|=_&^%$@");
        q=0;
        while(cut != NULL)
        {
            strcpy(y[q],cut);
            q++;
            cut = strtok(NULL," ,.';:!/?`~#*-+.'|=_&^%$@");
        }
        memset(&dp,-1,sizeof(dp));
        match(0,0);
        space=0;
        print(0,0);
        N[0]='\0';
        M[0]='\0';
    }
    return 0;
}
