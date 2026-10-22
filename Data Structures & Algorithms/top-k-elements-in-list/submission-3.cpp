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

        sort(result.begin(),result.end(),[](auto a, auto b){
            return a.second>b.second;
        });
        for(int i = 0; i<k; i++){
            finalResult.push_back(result[i].first);
        }

        return finalResult;
    }
};
