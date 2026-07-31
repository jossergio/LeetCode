class Solution:
    def smallestPalindrome(self, s: str) -> str:
        d = Counter (s)
        inicio = ""
        final = ""
        for a in range  (ord ('a'), ord ('z') + 1):
            c = chr (a)
            tmp = d [c] // 2
            inicio += c * tmp
            final = c * tmp + final
            d [c] %= 2
        return inicio + "".join ([c for c, q in d.items () if q == 1]) + final
