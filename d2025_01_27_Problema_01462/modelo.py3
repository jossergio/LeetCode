class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        pre = [set () for i in range (numCourses)]
        for p in prerequisites:
            pre [p [1]].add (p [0])
        feitos = [False] * numCourses
        def buscar (k):
            if not feitos [k]:
                feitos [k] = True
                tmp = set ()
                for b in pre [k]:
                    tmp |= buscar (b)
                pre [k] |= tmp
            return pre [k]
        for i, p in enumerate (pre):
            tmp = set ()
            for b in p:
                tmp |= buscar (b)
            pre [i] |= tmp
        resposta = [False] * len (queries)
        for i, q in enumerate (queries):
            resposta [i] = q [0] in pre [q[1]]
        return resposta
        