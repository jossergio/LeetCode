class Solution:
    
    fibs = dict ()
    maior = -1
    
    def fib(self, n: int) -> int:
        
        if self.fibs.get (n) == None:
            for k in range(self.maior + 1, n + 1): # range não retorna o ultimo
                if k <= 1:
                    self.fibs [k] = k
                else:
                    self.fibs [k] = self.fibs [k - 1] + self.fibs [k - 2] # Com certeza já existem
                    
        self.maior= max (self.maior, n)
        return self.fibs [n]
    
