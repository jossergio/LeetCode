class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        resposta = list ()
        arr.sort () # Agiliza o algoritmo
        menor = arr [1] - arr [0]
        # Para ter um referencial inicial
        # Pela definição do problema, sempre há dois ou mais
        for i in range (len (arr) - 1):
            # Se está ordenado, não precisa de um laço interno para comparar com todos!
            a = arr [i]
            b = arr [i + 1] # Já está ordenado. Ou seja, o seguinte sempre é maior
            diferenca = b - a
            if diferenca <= menor:
                if diferenca < menor:
                    menor = diferenca
                    resposta.clear () # Reinicia a resposta
                resposta.append ([a, b]) # Menor ou igual, limpo ou não, adiciona
        return resposta
        