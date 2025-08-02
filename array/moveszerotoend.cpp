#include <iostream>
#include<vector>
using namespace std;
// time complexity: O(2n)
// space complexity: O(x) // where x is the number of non-zero elements in the array
//brute force approach
// 1. create a new array
// 2. copy all non-zero elements to the new array
// 3. fill the rest of the new array with zeros
// 4. copy the new array back to the original array
// void moveszero(int arr[],int n){
//     vector<int>temp;
//     for(int i=0;i<n;i++){
//         if(arr[i]!=0){
//             temp.push_back(arr[i]);
//         }
//     }
//     int nz=temp.size();
//     for(int i=0;i<nz;i++){
//         arr[i]=temp[i];
//     }
//     for(int i=nz;i<n;i++){
//         arr[i]=0;
//     }
// }
// better approach
// time complexity: O(2n)
// space complexity: O(1)
// 1. use two pointers
// 2. one pointer to iterate through the array
// 3. another pointer to keep track of the position to place the next non-zero element
// 4. when a non-zero element is found, place it at the position of the second pointer and increment the second pointer
// 5. after the first pointer has iterated through the array, fill the rest of the array with zeros
// void moveszero(int arr[], int n)
// {
//     int idx = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != 0)
//         {
//             arr[idx] = arr[i];
//             idx++;
//         }
//     }
//     for (int i = idx; i < n; i++)
//     {
//         arr[i] = 0;
//     }
// }

//optimal approach
// time complexity: O(n)
// space complexity: O(1)
// 1. use two pointers
// 2. one pointer to iterate through the array
// 3. another pointer to keep track of the position of the next zero element
// 4. when a zero element is found, place it at the position of the second pointer and increment the second pointer
// 5. when a non-zero element is found, swap it with the element at the position of the second pointer and increment the second pointer
// 6. after the first pointer has iterated through the array, the rest of the array will be filled with zeros
void moveszero(int arr[],int n){
    int j=-1; // pointer to keep track of the position of the next zero element
    // find the first zero element
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }

}
int main()
{
    int arr[7] = {2, 0, 1, 3, 4, 0, 6};
    moveszero(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
