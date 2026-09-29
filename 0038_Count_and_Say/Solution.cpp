#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n<=0) return "";
        string cur ="1";

        for(int i=1;i<n;++i){
            string next_seq = "";
            int count =1;
        
        for(int j=0;j<cur.length();++j){
            if(j+1<cur.length()&&cur[j]==cur[j+1]){
                count++;
            }else{
                next_seq+=to_string(count)+cur[j];
                count=1;
            }
        }     
        cur=next_seq;
      }
      return cur;
    }
};