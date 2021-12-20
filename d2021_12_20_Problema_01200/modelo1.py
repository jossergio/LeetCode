class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        resposta = list () # Também será temporário
        arr.sort () # Agiliza o algoritmo
        menor = arr [1] - arr [0]
        # Para ter um referencial inicial
        # Pela definição do problema, sempre há dois ou mais
        for i in range (len (arr) - 1):
            # Se está ordenado, não precisa de um laço interno para comparar com todos!
            a = arr [i]
            b = arr [i + 1] # Já está ordenado. Ou seja, o seguinte sempre é maior
            diferenca = b - a
            if diferenca <= menor: # Se maior, nesse ponto, nem precisa comparar
                menor = diferenca # Repetitivo? Talvez. Vê a linha abaixo sem um outro if
                resposta.append ([a, b, diferenca])
        return [[e [0], e [1]] for e in resposta if e [2] == menor]
        
