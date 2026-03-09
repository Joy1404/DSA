#include<bits/stdc++.h>
using namespace std;
// approach : we will use two vectors to store the number of people who know the celebrity and the number of people whom the celebrity knows. we will iterate through the matrix and update the two vectors accordingly. finally we will check if there is any person who is known by n-1 people and knows 0 people. if there is such a person then we will return the index of that person as the celebrity. otherwise we will return -1.
// time complexity : O(n^2) where n is the number of people in the party as we are iterating through the matrix of size n*n.
// space complexity : O(n) where n is the number of people in the party as we are using two vectors of size n to store the number of people who know the celebrity and the number of people whom the celebrity knows.
int findcelebrity(vector<vector<int>>& arr, int n){
    vector<int> knowme(n,0);
    vector<int> iknow(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                // if i==j then we will ignore it as it is not a valid case as a person cannot know himself.
                // if(i==j){
                //     continue;
                // }
                knowme[j]++;
                iknow[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(knowme[i]==n-1 && iknow[i]==0){
            return i;
        }
    }
    return -1;
}
// approach : we will use two pointers to find the celebrity. we will initialize the two pointers to the first and the last index of the matrix. we will check if the person at the top pointer knows the person at the bottom pointer. if he knows then we will move the top pointer to the next index. if he does not know then we will move the bottom pointer to the previous index. finally we will check if there is any person who is known by n-1 people and knows 0 people. if there is such a person then we will return the index of that person as the celebrity. otherwise we will return -1.
// time complexity : O(n) where n is the number of people in the party as we are iterating through the matrix of size n*n only once.
// space complexity : O(1) as we are not using any extra space to store the number of people who know the celebrity and the number of people whom the celebrity knows. we are using only two pointers to find the celebrity.
int celebrity(vector<vector<int>>& mat, int n){
    int top = 0;
    int bottom = n-1;
    while(top<bottom){
        if(mat[top][bottom]==1){ // if the person at the top pointer knows the person at the bottom pointer then we will move the top pointer to the next index as the person at the top pointer cannot be the celebrity.
            top++;
        }
        else if(mat[bottom][top]==1){ // if the person at the bottom pointer knows the person at the top pointer then we will move the bottom pointer to the previous index as the person at the bottom pointer cannot be the celebrity.
            bottom--;
        }
        else{ // if the person at the top pointer does not know the person at the bottom pointer and the person at the bottom pointer does not know the person at the top pointer then we will move both the pointers to the next index as both the persons cannot be the celebrity.
            top++;
            bottom--;
        }
    }
    if(top>bottom){
        return -1;
    }
    for(int i=0;i<n;i++){
        if(i==top){
            continue;
        }
        if( (mat[top][i]==0 && mat[i][top]==1)){
           
        }else{
            return -1;
    }
}
return top;
}
int main(){
    // vector<vector<int>> arr = {{0,1,0},{0,0,0},{0,1,0}};
    vector<vector<int>> arr = {{1,1,0},{0,1,0},{0,1,1}};
    int n = 3;
    cout<<findcelebrity(arr,n)<<endl;
    cout<<celebrity(arr,n)<<endl;
}