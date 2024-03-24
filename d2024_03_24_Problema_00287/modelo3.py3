class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        existe = [False] * (len (nums) + 1) # Os valores em nums são 1-begin
        for n in nums:
            if existe [n]:
                return n
            else:
                existe [n] = True
        return 0 # Só para ter algo aqui
        
