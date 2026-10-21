class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() == 0){
            return {};
        }

        vector<vector<string>>result;
        unordered_map<string,vector<string>>myMap;

        for(string s:strs){
            string str = s;
            sort(str.begin(),str.end());

            myMap[str].push_back(s);
        }
        
        for(auto it:myMap){
            result.push_back(it.second);
        }
        return result;
    }
};
