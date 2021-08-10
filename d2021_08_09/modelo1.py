class Solution:
    valores = {"0": 0, "1": 1, "2": 2, "3": 3, "4": 4, "5": 5, "6": 6, "7": 7, "8": 8, "9": 9}

    def addStrings(self, num1: str, num2: str) -> str:
        valor1 = 0
        valor2 = 0
        t1 = len (num1)
        t2 = len (num2)
        retorno = list ()
        for a in range (t1 - 1, -1, -1):
            valor1 += self.valores [num1 [a]] * 10**(t1 - a - 1)
        for a in range (t2 - 1, -1, -1):
            valor2 += self.valores [num2 [a]] * 10**(t2 - a - 1)
        temp = valor1 + valor2
        chaves = list ()
        for k, _ in self.valores.items ():
            chaves.append (k)
        if temp == 0:
            retorno.insert (0, "0")
        else:
            while temp > 0:
                retorno.insert (0, chaves [temp % 10])
                temp = temp // 10
        return "".join (retorno)

