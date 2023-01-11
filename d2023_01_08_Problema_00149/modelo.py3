class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        resposta = 0
        for i, c1 in enumerate (points):
            coefs = defaultdict (int) # Sempre reinicia a cada iteração, usando, sempre, o atual como base
            for c2 in points [i + 1:]:
                if c2 [0] - c1 [0] == 0: # Coeficiente angular infinito; não forma função; definir cAngular e cLinear para um valor constante base
                    ## Escolhidos valores do próprio ponto base
                    cAngular = c1 [0]
                    cLinear = c1 [1]
                else:
                    cAngular = (c2 [1] - c1 [1]) / (c2 [0] - c1 [0])
                    cLinear = c1 [1] - cAngular * c1 [0] # Pode-se escolher o ponto referência
                coefs [(cAngular, cLinear)] += 1
                resposta = max (resposta, coefs [(cAngular, cLinear)])
        return resposta + 1 # O ponto inicial base é acrescentado aqui
    
