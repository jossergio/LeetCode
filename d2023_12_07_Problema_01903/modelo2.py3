class Solution:
    def largestOddNumber(self, num: str) -> str:
        impares = set (['1', '3', '5', '7', '9'])
        for i, c in enumerate (reversed (num)): # 0-begin
            if c in impares:
                return num [:len (num) - i]
        # else
        return "" # Não há

