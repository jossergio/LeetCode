class Solution:
    def maximum69Number (self, num: int) -> int:
        n = list (str (num))
        maior = num # Será a referência
        for i, v in enumerate (n):
            if v == '6':
                tmp = list (n)
                tmp [i] = '9'
                maior = max (maior, int ("".join (tmp)))
        return maior
    
