class Solution:
    def minLength(self, s: str) -> int:
        buscar = True
        while buscar:
            tmp = s.find ("AB")
            if tmp == -1:
                tmp = s.find ("CD")
            if tmp == -1:
                buscar = False
            else:
                s = s [0:tmp] + s [tmp + 2:]
        return len (s)
    
