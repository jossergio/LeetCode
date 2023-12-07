class Solution:
    def largestOddNumber(self, num: str) -> str:
        impares = set (['1', '3', '5', '7', '9'])
        for i in range (len (num) - 1, -1, -1): # 0-begin
            if num [i] in impares:
                return num [:i + 1]
        # else
        return "" # Não há

