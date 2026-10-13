#include <bits/stdc++.h>
using namespace std;

// LeetCode solution

class Solution {
public:
    string longestPalindrome(string s) {
          if (s.empty()) return "";
        int l=0, len=0, n=s.length();
        
        for (int i=0; i<n;i++) {
            for (int k=0; k<2;k++) {
                int a=i, b=i+k;
                while (a>=0 && b< n && s[a] == s[b]) {
                    a--;
                    b++;
                }
                if (b-a-1>len) {
                    len=b-a-1;
                    l=a+1;
                }
            }
        }
        return s.substr(l, len);
    }
};