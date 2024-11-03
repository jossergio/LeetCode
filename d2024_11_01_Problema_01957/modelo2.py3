class Solution:
    def makeFancyString(self, s: str) -> str:
        p1 = 2
        a = list (s)
        for p2 in range (2, len (a)):
            if not (a [p2] == a [p1 - 1] and \
            a [p2] == a [p1 - 2]):
                a [p1] = a [p2]
                p1 += 1
        return "".join (a [:p1])
    
