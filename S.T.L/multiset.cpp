#include<bits/stdc++.h>
using namespace std;
void explainmultiset(){
    //everything is same as set
    //except that it allows duplicate elements
    multiset<int>ms;
    ms.insert(1);//1
    ms.insert(1);//1,1
    ms.insert(1);//1,1,1

    ms.erase(1);//all 1's are removed

    int cnt=ms.count(1);//0
    //count returns the number of elements in the multiset that are equal to 1
    //if no such element is found, it returns 0
    ms.erase(ms.find(1));//this will not remove anything as 1 is not present in the multiset
    //erase function removes the first occurrence of the element
    //find function returns an iterator to the first occurrence of the element
    //if no such element is found, it returns ms.end()
    //ms.end() is an iterator that points to the end of the multiset
    //it is used to check if the element is present in the multiset or not
    // ms.erase(ms.find(1),ms.find(1)+1);

}