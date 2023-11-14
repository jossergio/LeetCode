class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        resposta = set ()
        i = 0
        t = len (s)
        ja = set ()
        while i < t:
            if not s [i] in ja:
                ja.add (s [i])
                j = t - 1
                tmp = set ()
                while j > i + 1 and not s [j] == s [i]:
                    j -= 1
                k = i + 1
                while k < j:
                    resposta.add ((s [i], s [k], s [j]))
                    k += 1
            i += 1
        return len (resposta)
    
