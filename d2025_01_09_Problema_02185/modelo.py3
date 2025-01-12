class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        return len ( \
                   [a for a in words \
                   if a [:len (pref)] == pref])
