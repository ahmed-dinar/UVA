#include<bits/stdc++.h>

using namespace std;

struct icompare_char {
  bool operator()(char c1, char c2) {
    return c1 < c2;
  }
};

struct compare {
  bool operator()(std::string const& s1, std::string const& s2) {
    return std::lexicographical_compare(s1.begin(), s1.end(),
                                        s2.begin(), s2.end(),
                                        icompare_char());
  }
};

map<string,double>species;

int main(){
    int t;
    scanf("%d\n\n",&t);
    while(t--){
        string tree;
        vector<string>name;
        double total = 0;
        while( getline(cin,tree) ){
            if(tree.size()==0) break;
            if(species[tree]==0) name.push_back(tree);
            species[tree]++;
            total++;
        }
        sort(name.begin(),name.end(),compare());
        int sz = name.size();
        for(int i=0; i<sz; i++)
            printf("%s %.4lf\n",name[i].c_str(),((species[name[i]])*100)/total);

        if(t) nl;
        species.clear();
    }
    return 0;
}
