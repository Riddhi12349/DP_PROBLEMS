/*
Problem_Link : https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> dp(n , 1) , cnt(n , 1);
        int maxi = 1;

 for(int i = 0 ; i < n ; i++){
     for(int prv = 0 ; prv < i ; prv++){
        if((nums[prv] < nums[i])  && (1 + dp[prv] > dp[i])){
            
            dp[i] = 1 + dp[prv];
            // that element get attached to their seq
             cnt[i] = cnt[prv];
        }
        
        else  if((nums[prv] < nums[i]) && (1 + dp[prv] == dp[i])){
                    cnt[i] += cnt[prv];
                }
        }
            // keeping track of maxlen
            maxi = max(maxi , dp[i]);

        }

         int tot = 0;
         for(int i = 0 ; i < n  ; i++){
             if(dp[i] == maxi)  tot += cnt[i];
         }

         return tot;
    }
};
