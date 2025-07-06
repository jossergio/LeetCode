class Solution:
    def findLucky(self, arr: List[int]) -> int:
        cont = Counter (arr)
        for i in sorted (cont.keys (), reverse = True):
            if cont [i] == i:
                return i
        return -1
