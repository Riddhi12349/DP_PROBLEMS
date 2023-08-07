/*
PROBLEM-LINK
https://leetcode.com/problems/number-of-music-playlists/
*/

//********* ASKED BY - GOOGLE , COURSEERA *********
class Solution {
public:
    
    using ll = long long;
    ll dp[102][102];
    const int mod = 1e9+7;

    ll find(int n ,int goal, int k ,int usedSongs) {
        
        // have 2 choices either to take a used song or
        //take a new song
    
    if(goal == 0){
        return usedSongs == n;
    } 

    if(goal < 0){
        return 0;
    }

    if(dp[usedSongs][goal]  != -1){
        return dp[usedSongs][goal];
    }

   // basically picking a new song or not picking and when not picking utilizing old one based on condition that for using a old song k other songs should have been played....

    ll ways_usedSongs =
    find(n , goal-1 , k , usedSongs)*max(usedSongs-k,0) %mod;
    
     ll ways_newSongs = 
    find(n , goal-1 ,k , usedSongs + 1)*(n-usedSongs)% mod;    
   

    dp[usedSongs][goal] = (ways_usedSongs + ways_newSongs)% mod;
     
     return dp[usedSongs][goal];
    }

    int numMusicPlaylists(int n , int goal , int k){
      
      memset(dp , -1 , sizeof(dp));     
      return  find(n , goal , k , 0);
    
    }
};
