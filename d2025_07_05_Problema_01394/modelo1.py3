class Solution:
    def findLucky(self, arr: List[int]) -> int:
        cont = Counter (arr)
        print (cont)
        for i in sorted (cont.keys (), reverse = True):
            print (i, cont [i])
            if cont [i] == i:
                return i
        return -1
