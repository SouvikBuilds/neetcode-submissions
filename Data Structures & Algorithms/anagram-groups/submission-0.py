class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        groups = {}

        n = len(strs)

        for i in range(0,n):
            word = strs[i]

            key = "".join(sorted(word))

            if key not in groups:
                groups[key] = []
            
            groups[key].append(word)
        result = list(groups.values())
        
        return result