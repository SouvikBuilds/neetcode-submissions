class Solution:
    def isPalindrome(self, s: str) -> bool:
        output = False
        cleaned = ""
        formattedstring = s.strip().lower()

        for word in formattedstring:
            if word.isalnum():
                cleaned+=word
        
        if cleaned == cleaned[::-1]:
            output = True
        else:
            output = False

        return output