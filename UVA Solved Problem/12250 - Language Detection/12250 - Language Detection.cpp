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

map<string,string>country;

void language()
{
    country["HELLO"] = "ENGLISH";
    country["HOLA"] = "SPANISH";
    country["HALLO"] = "GERMAN";
    country["BONJOUR"] = "FRENCH";
    country["CIAO"] = "ITALIAN";
    country["ZDRAVSTVUJTE"] = "RUSSIAN";
}

int main()
{
    language();
    char helo[16];
    int ca=0;
    while(gets(helo))
    {
        if(strcmp(helo,"#") == 0)
            break;

        if(country[helo] == "")
            cout << "Case " << ++ca << ": " << "UNKNOWN" << endl;
        else
            cout << "Case " << ++ca << ": " <<country[helo]  << endl;
    }
    return 0;
}



