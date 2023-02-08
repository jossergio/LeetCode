class Solution:
    def jump(self, nums: List[int]) -> int:
        resposta = 0
        esquerda, direita = 0, 0
        while (direita < len (nums) - 1):
            maximaDistancia = 0 # Lembrar que o problema cita que o final é alcançável
            for i in (range (esquerda, direita + 1)):
                maximaDistancia = max (maximaDistancia, i + nums [i])
            esquerda, direita = direita + 1, maximaDistancia
            resposta += 1
        return resposta
    
