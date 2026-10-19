class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int>freq;
        for(int i = 0; i<nums.size(); i++){
            freq[nums[i]]++;
        }

        int repeatedInt;
        for(auto it:freq){
            if(it.second > 1){
                repeatedInt = it.first;
            }
        }

        return repeatedInt;
    }
};
