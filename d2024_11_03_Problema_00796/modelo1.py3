class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if s == goal: # Já é
            return True
        # else
        if len (s) != len (goal): # Vai que; LeetCode
            return False
        r = list () # string vazia
        a = list (s)
        g = list (goal)
        while len (a) > 0:
            r += a.pop (0)
            if g [0: len (a)] == a and \
            g [len (a):] == r:
                return True
        return False # Passou pir tudo e não achou
    
