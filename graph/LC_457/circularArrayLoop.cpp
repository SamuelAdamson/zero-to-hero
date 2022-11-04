class Solution {
public:
    bool detectCycle(vector<int>& g, int i, int n) {
        bool sign = g[i] > 0;
        int slow = i, fast = (i + g[i] + n) % n; 
        
        while(slow != fast) {
            int next = (fast + g[fast] + n) % n;
            
            if(g[slow] > 0 != sign) return false;
            if(g[fast] > 0 != sign || g[next] > 0 != sign) return false;
            
            slow = (slow + g[slow] + n) % n;
            fast = (next + g[next] + n) % n;
        }
        
        return ((slow + g[slow] + n) % n) != slow;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++) nums[i] %= n;
        
        for(int i = 0; i < nums.size(); i++) {
            if(detectCycle(nums, i, n)) return true;
        }
        
        return false;
    }
};