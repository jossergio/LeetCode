class Solution:
    def reverseVowels(self, s: str) -> str:
        b = list (s)
        i = 0
        j = len (b) - 1
        vogais = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        while i < j:
            while i < j and b [i] not in vogais:
                i += 1
            while j > i and b [j] not in vogais:
                j -= 1
            if i < j:
                b [i], b [j] = b [j], b [i]
            i += 1
            j -= 1
        return "".join (b)
    
