class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        for a, b in zip (sorted (target), sorted (arr)):
            if a != b: # Não possui correspondente
                return False
        return True # Passou em todos os testes de correspondência
    
