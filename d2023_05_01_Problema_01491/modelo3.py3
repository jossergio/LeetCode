class Solution:
    def average(self, salary: List[int]) -> float:
        tamanho = len (salary) - 2 # O menor e o maior não entrarão
        menor = salary [0] # Para ter um referencial
        maior = salary [0] # Idem
        soma = salary [0] # Pois iniciaremos a partir da segunda posição
        for v in salary [1:]:
            soma += v
            menor = min (menor, v)
            maior = max (maior, v)
        return (soma - maior - menor) / tamanho

