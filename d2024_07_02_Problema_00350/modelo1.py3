class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        a1 = Counter (nums1)
        a2 = Counter (nums2)
        resposta = list ()
        for i, v in a1.items ():

            resposta.extend ([i] * min (v, a2.get (i, 0)))
        return resposta
    
