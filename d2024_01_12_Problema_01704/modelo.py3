class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vogais = set (['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])
        t = len (s) // 2 # len s sempre é par, pela definição do problema
        return len ([a for a in s [:t] if a in vogais]) == len ([a for a in s [t:] if a in vogais])

