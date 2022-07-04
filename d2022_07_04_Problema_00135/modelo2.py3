class Solution:
    def candy(self, ratings: List[int]) -> int:
        
        doces = [1 for x in range (len (ratings))]
        
        for i in range (1, len (ratings)):
            if ratings [i ] > ratings [i - 1]:
                doces [i] = doces [i - 1] + 1
                
        for i in range (len (ratings) - 2, -1, -1): # Lembrar que o último elemento em range não conta
            if ratings [i] > ratings [i + 1]:
                doces [i] = max (doces [i], doces [i + 1] + 1)
                
        return sum (doces)
    
