#include <bits/stdc++.h>
using namespace std;

// LeetCode solution
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;++i){
            int s=0;
            int x=nums[i];
            while(x>0){
                s+=x%10;
                x/=10;
            }
            if(s==i){
                return i;
            }
        }
        return -1;
    }
};