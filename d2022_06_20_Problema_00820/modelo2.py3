class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        
        unicos = set (words)
        
        for palavra in words:
            for i in range (len (palavra) - 1, 0, -1):
                unicos.discard (palavra [i:])
                
        return sum (len (palavra) + 1 for palavra in unicos)
    
