class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        menores = set ([min (linha) for linha in matrix])
        maiores = set ()
        for j in range (len (matrix [0])):
            maior = matrix [0][j]
            for i in range (len (matrix)):
                maior = max (maior, matrix [i][j])
            maiores.add (maior)
        return menores.intersection (maiores)
    
