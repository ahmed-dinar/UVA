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
	int n;
	while(cin >> n)
	{
        if(n==0) break;
        else if(n == 2)
        {
            cout << "1" << endl;
            continue;
        }
	   int co=0;
	   while(n >= 3 )
	   {
	       co = co + n/3;
	       n = ( (n/3) + (n%3) );
	       if( n == 2 || n == 4  )
	       {
	           n = n+1;
	       }
	   }
	   cout << co << endl;
	}
    return 0;
}





















