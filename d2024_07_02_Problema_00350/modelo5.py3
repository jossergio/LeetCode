class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        a = Counter (nums1)
        resposta = list ()
        for i in nums2:
            if a.get (i, 0) > 0:
                resposta.append (i)
                a [i] -= 1
        return resposta
    
