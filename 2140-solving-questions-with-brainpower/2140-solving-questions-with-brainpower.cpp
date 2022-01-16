#define ll long long 

class Solution {
long long maxPoints(ll quesNo, bool cooldown, vector<vector<int>>& questions, vector<vector<ll>>& dp)
    {
        if(quesNo >= questions.size()) return 0;
        
        if(dp[quesNo][cooldown] != -1) return dp[quesNo][cooldown];
        
        if(!cooldown)
        {
            // Not in cooldown -> solve or skip
            ll solveThisQues = questions[quesNo][0] + maxPoints(quesNo+questions[quesNo][1], 1, questions, dp);
            ll skipThisQues = maxPoints(quesNo+1, 0, questions, dp);
            return dp[quesNo][cooldown] = max(solveThisQues, skipThisQues);
        }
        else
        {
            // In cooldown -> cannot solve the current question
            return dp[quesNo][cooldown] = maxPoints(quesNo+1, 0, questions, dp);
        }
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        ll n = questions.size(), quesNo = 0;
        bool cooldown = false;
        vector<vector<ll>> dp(n+1, vector<ll>(2,-1));
        
        return maxPoints(quesNo, cooldown, questions, dp);
    }
};