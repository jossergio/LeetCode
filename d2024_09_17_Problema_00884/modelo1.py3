class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        return \
        [s for s, c in (Counter (s1.split (" ")) + \
        Counter (s2.split (" "))).items () if c == 1]
    
