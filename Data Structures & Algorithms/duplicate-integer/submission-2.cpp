class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i<size-1; i++){
            for(int j = 0; j<size-i-1; j++){
                int temp;
                if(nums[j]>nums[j+1]){
                    temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
            }
        }

        for(int i = 1; i<size; i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }

        return false;
    }
};