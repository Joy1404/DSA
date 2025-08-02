#include<bits/stdc++.h>
using namespace std;
unordered_set<int> s;
// it is not sorted
//lower_bound and upper_bound are not applicable for unordered_set
//rest all functions are same as set it doesnt store in any particular order it has better time complexity than
//set in more cases,except some when collision occurs

//worst case time complexity is O(n) when all elements are same
//average case time complexity is O(1) for all operations