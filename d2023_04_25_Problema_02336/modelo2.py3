class SmallestInfiniteSet:

    def __init__(self):
        self.lista = [1]

    def popSmallest(self) -> int:
        retorno = self.lista.pop (0) # lista nunca é vazia
        if len (self.lista) == 0: # Ficou vazia...
            self.lista.append (retorno + 1) # ... joga, imediatamente, o próximo
        return retorno

    def addBack(self, num: int) -> None:
        if not num > self.lista [-1]: # Não é maior que o último?
            if not num in self.lista:
                self.lista.append (num)
                self.lista.sort ()


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)

