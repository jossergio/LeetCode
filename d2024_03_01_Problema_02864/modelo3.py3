class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        t = len (s)
        c = s.count ("1") - 1 # Tira, para repor no final
        return "".join (["1"] * c + ["0"] * (t - c - 1) + ["1"]) # Tira um dos zeros
    
