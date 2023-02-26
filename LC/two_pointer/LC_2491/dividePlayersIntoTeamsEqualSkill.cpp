class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int s = skill.front() + skill.back(), n = skill.size();
        long long chemistry = skill.front() * skill.back();
        
        for(int i = 1; i < n/2; i++) {
            if(skill[i] + skill[n-i-1] != s) return -1;
            chemistry += (skill[i] * skill[n-i-1]);
        }
        
        return chemistry;
    }
};