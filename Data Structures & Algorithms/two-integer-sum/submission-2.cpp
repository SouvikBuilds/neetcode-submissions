class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>myMap;
        vector<int>result;
        for(int i = 0; i < nums.size(); i++){
            int complement = target-nums[i];
            if(myMap.contains(complement)){
                result.push_back(myMap[complement]);
                result.push_back(i);
            }else{
                myMap[nums[i]] = i;
            }
        }

        return result;
    }
};
