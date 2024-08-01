class Solution:
    def countSeniors(self, details: List[str]) -> int:
        return len ([a for a in details if int (a [11:13]) > 60]) # 11:12, inclusive
        
