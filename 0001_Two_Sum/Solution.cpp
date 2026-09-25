#include <bits/stdc++.h>
using namespace std;

// LeetCode solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    // unordered_map<int, int>mp;
    // for(int i=0; i<nums.size(); i++){
    //     int diff = target - nums[i];

    //     if(mp.find(diff) != mp.end()){
    //         return {mp[diff] ,i};

    //     }
    //     mp[nums[i]]=i;
    // }  
    // return {};
//     unordered_map<int, int>mp;

//     for(int i=0; i<nums.size(); i++){
//         int complement = target - nums[i];

//         if(mp.find(complement) != mp.end()){
//             return{mp[complement],i};
//         }
//         mp[nums[i]]=i;
//     }
//     return {};
//     }
// };
  unordered_map<int, int>mp;

  for(int i = 0 ; i < nums.size(); i++){
    int complement = target - nums[i];

    if(mp.find(complement) != mp.end()){
        return {mp[complement], i};
    }
    mp[nums[i]] = i;
  }
  return {};
  }
};