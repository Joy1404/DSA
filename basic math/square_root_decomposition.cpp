#include<bits/stdc++.h>
using namespace std;
class NumArray {
public:
vector<int>nums;
vector<int>blocks;
int n;
int blocksize;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        blocksize= ceil(sqrt(n));
        blocks.resize(blocksize,0);
        // build the blocks
        for(int i=0;i<n;i++){
            int blockidx = i / blocksize;
            blocks[blockidx]+=nums[i];
        }
    }
    
    void update(int index, int val) {
        int blockidx = index/ blocksize;
        blocks[blockidx]-=nums[index];
        blocks[blockidx]+=val;
        nums[index] = val;

    }
    
    int sumRange(int left, int right) {
        int sum =0;
        int  stblock = left / blocksize;
        int endblock = right / blocksize;
        // case1: left and right are in the same block
        if(stblock==endblock){
            for(int i=left;i<=right;i++){
                sum+=nums[i];
            }
            return sum;
        }
        //case2: left and right are in different blocks
        //left partial sum (l to end of the start block)
        int endofstblock = (stblock+1)*blocksize -1;
        for(int i=left;i<=endofstblock;i++) sum+=nums[i];
        // middle complete blocks sum
        for(int b = stblock+1;b<=endblock-1;b++) sum+=blocks[b];
        // right partial sum (start of the end block to r)
        int stofendblock = (endblock* blocksize);
        for(int i=stofendblock;i<=right;i++) sum+=nums[i];
        return sum;
    }
};
int main(){
    vector<int>nums = {1,3,5};
    NumArray* obj = new NumArray(nums);
    cout<<obj->sumRange(0,2)<<endl;
    obj->update(1,2);
    cout<<obj->sumRange(0,2)<<endl;
}