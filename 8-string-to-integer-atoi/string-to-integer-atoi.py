class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s:
            return 0
        
        sign = 1
        start = 0
        
        if s[0] == '-':
            sign = -1
            start = 1
        elif s[0] == '+':
            start = 1
            
        num = 0
        for i in range(start, len(s)):
            if s[i].isdigit():
                num = num * 10 + int(s[i])
            else:
                break
                
        num *= sign
        
        INT_MIN, INT_MAX = -2147483648, 2147483647
        if num < INT_MIN:
            return INT_MIN
        if num > INT_MAX:
            return INT_MAX
            
        return num