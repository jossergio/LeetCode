class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        contagem = defaultdict (int) # Armazena a contagem dos pares, de forma dinâmica
        iguais = set () # Para palavras de caracteres iguais
        total = 0 # Conterá o resultado
        for w in words:
            c1, c2 = w [0], w [1]
            if c1 == c2:
                contagem [w] += 1
                iguais.add (w)
            else:
                inverso = c2 + c1
                if contagem [inverso] > 0:
                    contagem [inverso] -= 1
                    total += 4
                else:
                    contagem [w] += 1
        contagemImpares = False # Se houver mais de um ímpar igual, tem que adicionar um deles no meio
        for a in iguais:
            if contagem [a] % 2 == 0:
                total += contagem [a] * 2
            else:
                total += (contagem [a] - 1) * 2 # De todos os ímpares, um será considerado para o centro
                contagemImpares = True
        return total + (2 if contagemImpares else 0)
        