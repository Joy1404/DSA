#include<bits/stdc++.h>
using namespace std;
void explainset(){
    set<int>st;
    // sorting is done in ascending order and unique elements are stored
    st.insert(1);//1
    st.insert(2);//1,2
    st.emplace(2);//1,2
    st.insert(4);//1,2,4
    st.insert(3);//1,2,3,4

    //functionality of insert in vector
    //can be used also that also increases efficiency

    //begin,end,rbegin,rend,size,empty,swap
     //1,2,3,4,5
     auto it=st.find(3); //it returns the iterator which points to the element
     //1,2,3,4,5
    auto it=st.find(6); //if not found it returns end
    //1,4,5
    st.erase(5); //takes log(n)

    int count=st.count(1); //returns 1 if found else 0

    auto it=st.find(3);
    st.erase(it); //takes constant time

    //1,2,3,4,5
    auto it1=st.find(2);
    auto it2=st.find(4);
    st.erase(it1,it2); //erases all elements in the range [it1,it2) //after erasing 1,4,5
    //lower_bound, upper_bound function works in the same way 
    //lower_bound returns the first element which is greater than or equal to the given element
    //upper_bound returns the first element which is greater than the given element
    //lower_bound and upper_bound takes log(n) time
    //lower_bound and upper_bound returns the iterator
    //lower_bound and upper_bound can be used to find the range of elements in the set
    auto it1=st.lower_bound(2);
    auto it2=st.upper_bound(4);
}