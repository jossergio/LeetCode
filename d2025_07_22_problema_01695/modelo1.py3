class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        t = len (nums)
        acumulados = [0] * t
        acumulado = 0
        ultimos = dict ()
        ultimo = -1
        resposta = 0
        for i, v in enumerate (nums):
            if i == 0:
                acumulados [0] = v
                acumulado = v
                ultimo = 0
            else:
                acumulados [i] = acumulados [i - 1] + v
                if ultimos.get (v, -1) == -1 or ultimo > ultimos [v]:
                    acumulado += v
                else:
                    acumulado = acumulados [i] - acumulados [ultimos [v]]
                    ultimo = ultimos [v] + 1
            ultimos [v] = i
            resposta = max (resposta, acumulado)
        return resposta
