class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        lista = sorted (enumerate (heights), key = lambda a: a [1], reverse = True) # Para facilitar a visualização do código, desmembrei
        return [names [i] for i, x in lista]
        
