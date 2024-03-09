class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        # Fiz separado para melhor visualização e entendimento
        # Mas poderia ser em uma linha
        conjunto1 = set (nums1)
        comuns = conjunto1.intersection (set (nums2))
        if len (comuns) == 0:
            return -1
        # else
        return sorted (comuns)[0]
    
