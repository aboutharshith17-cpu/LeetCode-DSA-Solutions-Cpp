#include <bits/stdc++.h>
using namespace std;

// LeetCode solution

class Solution{
    public:
      bool isPalindrome(int x){
        if(x < 0) return false;
      int dup = x;
      long long revNum=0;
      while(x > 0){
        int digit = x % 10;
        revNum = revNum * 10 + digit;
        x /= 10;
      }
      return revNum == dup;
      }
};