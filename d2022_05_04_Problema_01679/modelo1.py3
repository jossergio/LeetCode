import numpy
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        
        resposta = 0
        
        # Transforma em numpy
        numsArr = numpy.array (nums)

        ns = numpy.unique ([n for n in numsArr if n < (k + 1) // 2])
        
        for v in ns:
            resposta += min (numsArr [numpy.where (numsArr == v)].size, numsArr [numpy.where (numsArr == k - v)].size)
            
        if k % 2 == 0:
            resposta += (numsArr [numpy.where (numsArr == (k // 2))].size) // 2
            
        return resposta
    
