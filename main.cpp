#include<bits/stdc++.h>
#include <random>
using namespace std;

int main(){
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n;
    in>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        int x,y;
        in>>x>>y;
        v.push_back({x,y});
    }
    default_random_engine generator;
    
    while(v.size()>2){
        uniform_int_distribution<int> d(0,v.size()-1);
        int r = d(generator);
        cout<<r<<endl;
        int a = v[r].first;
        int b = v[r].second;
        v.erase(v.begin()+r);

        for(int i=0;i<v.size();i++){
            if(v[i].first==b ){
                v.push_back({a,v[i].second});
                v.erase(v.begin()+i);
                i--;
                
            }
            else if(v[i].second==b ){
                v.push_back({a,v[i].first});
                v.erase(v.begin()+i);
                i--;
            }
        }

        for(int i=0;i<v.size();i++)
        {
            if(v[i].first==v[i].second)
            {
                v.erase(v.begin()+i);
                i--;
            }
        }

        
    }
    out<<v.size()<<'\n';
    for(auto it:v){
        out<<it.first<<" "<<it.second<<'\n';
    }

    

    

}