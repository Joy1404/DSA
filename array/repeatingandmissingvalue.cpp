#include<bits/stdc++.h>
using namespace std;
vector<int>missingandrepeatingbruteforce(vector<int>& arr,int n){
    vector<int> ans;
    int missing = -1, repeating = -1;
    for(int i=1;i<=n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(ans[j] == i){
                count++;
            }
        }
        if(count == 0){
            missing = i; // Missing
            ans.push_back(i);
        } else if(count > 1){
            repeating = i; // Repeating
            ans.push_back(i);
        }
        if(missing != -1 && repeating != -1){
            break;
        }
    }
    return ans;
}
vector<int>missingandrepeatingbetter(vector<int> &arr, int n){
    vector<int> ans;
    int missing = -1, repeating = -1;
    vector<int> freq(n + 1, 0);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(freq[i] == 0){
            missing = i;
        } else if(freq[i] == 2){
            repeating = i;
        }
        if(missing != -1 && repeating != -1){
            break;
        }
    }
    return {missing, repeating};
}
vector<int>missingandrepeatingbruteforce2(vector<int> &arr, int n){
    int sum = 0,repeating = -1,missing = -1;
    for(int i= 0;i<arr.size();i++){
        sum += arr[i];
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[i] == arr[j]){
                repeating = arr[i];
            }
        }
    }
    int expected_sum = (n * (n + 1)) / 2;
   missing = expected_sum - (sum - repeating);
    return {missing, repeating};
}
vector<int>missingandrepeatingoptimal(vector<int> &arr , int n){
    int sum = 0,sum_sq=0, expected_sum = (n * (n + 1)) / 2;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        sum_sq+=arr[i]*arr[i];
    }
    int missing = -1, repeating = -1;
    int x = sum - expected_sum; // x = repeating - missing
    int y = sum_sq - (n * (n + 1) * (2 * n + 1)) / 6; // y = repeating^2 - missing^2
    // y = (repeating - missing)(repeating + missing)
    // => repeating + missing = y / x
    if(x != 0){
        int sum = y / x;
        missing = (sum - x) / 2;
        repeating = (sum + x) / 2;
    }
    return {missing, repeating};
}
vector<int>missingandrepeatingoptimal2(vector<int> &arr, int n) {
    int xor_all = 0, xor_missing_repeating = 0;
    for (int i = 1; i <= n; i++) {
        xor_all ^= i; // XOR of all numbers from 1 to n
    }
    for (int num : arr) {
        xor_missing_repeating ^= num; // XOR of all elements in the array
    }
    int xor_result = xor_all ^ xor_missing_repeating; // XOR of array and 1 to n
    int bitno = 0;
    while((1)){
        if((xor_result & (1 << bitno)) != 0){
            break;
        }
        bitno++;
    }
    // int set_bit = xor_result & -xor_result; // Get the rightmost set bit

    int missing = 0, repeating = 0;
    for (int i = 1; i <= n; i++) {
        if (i & (1 << bitno)) {
            missing ^= i; // Group with set bit
        } else {
            repeating ^= i; // Group without set bit
        }
    }
    for (int num : arr) {
        if (num & (1 << bitno)) {
            missing ^= num; // Group with set bit
        } else {
            repeating ^= num; // Group without set bit
        }
    }
    // Determine which is missing and which is repeating
    int cnt =0;
    for(int i=0;i<n;i++){
        if(arr[i] == repeating){
            cnt++;
        }
    }
    if(cnt==2){
        // If we found the repeating element twice, we can confirm it
        return {missing, repeating};
    }
    return {missing, repeating};
}
int main() {
    vector<int> arr = {2,3, 6, 4, 1, 1};
    int n = arr.size();
    vector<int> result = missingandrepeatingoptimal2(arr, n);
    cout << "Missing: " << result[0] << ", Repeating: " << result[1] << endl;
    return 0;
}