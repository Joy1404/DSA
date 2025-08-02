#include<bits/stdc++.h>
using namespace std;
void explainmap(){
    map<int, int> mpp;
    //key is unique and sorted but value can be duplicate
    map<int,pair<int,int>> mpp2;
    map<pair<int,int>,int> mpp3;

    mpp[1]=2;
    mpp.emplace(3,1);
    mpp.insert({2,4});//{1,2},{2,4},{3,1}
    mpp3[{2,3}] = 10;

    for(auto it:mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<mpp[1]<<endl;
    cout<<mpp[5]<<endl; // if key is not present it will insert the key with value 0

    auto it = mpp.find(3);
    cout<<it->second<<endl; // it will return the value associated with the key 3
  auto it=mpp.find(5); //if key is not found it will return mpp.end()

  auto it2 = mpp.lower_bound(2); //it will return the first element which is greater than or equal to 2
  auto it3 = mpp.upper_bound(2); //it will return the first element which is greater than 2
  

  //erase,swap,size,empty are same as above
}