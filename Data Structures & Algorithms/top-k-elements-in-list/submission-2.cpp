class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 0) return {};
        vector<pair<int,int>>result;
        vector<int>finalResult;
        unordered_map<int,int>freq;
        for(int i:nums){
            freq[i]++;
        }

        for(auto it:freq){
            result.push_back({it.first,it.second});
        }

        for(int i = 0; i<result.size()-1; i++){
            for(int j = 0; j<result.size()-i-1; j++){
                if(result[j].second<result[j+1].second){
                    pair<int,int>temp = result[j];
                    result[j] = result[j+1];
                    result[j+1] = temp;
                }
            }
        }
        for(int i = 0; i<k; i++){
            finalResult.push_back(result[i].first);
        }

        return finalResult;
    }
};
