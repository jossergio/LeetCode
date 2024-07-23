class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        resposta = list ()
        for a, q in sorted (Counter (nums).items (), key = lambda b: (b [1], -b [0])):
            resposta.extend ([a] * q)
        return resposta
    
