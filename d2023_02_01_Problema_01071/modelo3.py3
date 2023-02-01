class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if str1 + str2 != str2 + str1: # Ou seja, não são complementares e, consequentemente, não possuem divisor comum nas letras
            return ""
        return str1 [:gcd (len (str1), len (str2))] # O trecho comum é definido pelo MDC dos comprimentos
    
