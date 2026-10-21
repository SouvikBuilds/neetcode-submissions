class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>freq;
        for(int i:nums){
            freq[i]++;
        }

        for(auto it:freq){
            if(it.second>1){
                return true;
            }
        }

        return false;
    }
};