class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        string1 = ""
        string2 = ""

        result = False

        for i in range(0,len(s)):
            char = s[i]
            string1+=char
        
        for j in range(0,len(t)):
            newChar = t[j]
            string2+=newChar
        
        if(sorted(string1) == sorted(string2)):
            result = True
        return result