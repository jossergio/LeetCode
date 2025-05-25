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
        # Os próximos passos fiz em etapas para facilitar visualização do código
        if len (iguais) > 0: # Junta
            total += sum ([contagem [a] for a in iguais if contagem [a] %2 == 0]) * 2 # Pega os iguais de contagem par
            total += sum ([contagem [a] - 1 for a in iguais if contagem [a] % 2 == 1]) * 2 # Pega todos que foram de contagem impar
            if len ([a for a in iguais if contagem [a] % 2 == 1]): # Verifica se há mais de um de contagem ímpar dentre os iguais
                total += 2 # Joga um deles como do meio
        return total
        