class Solution:
    def bfs (self, i: int, caminhos: defaultdict [set], atinge: List [bool]):
        atinge [i] = True
        for x in caminhos [i]:
            if not atinge [x]:
                self.bfs (x, caminhos, atinge)
        
    def minScore(self, n: int, roads: List[List[int]]) -> int:
        atinge = [False for n in range (n + 1)] # O zero será desprezado
        caminhos = defaultdict (set)
        for x in roads:
            caminhos [x [0]].add (x [1])
            caminhos [x [1]].add (x [0])
        self.bfs (1, caminhos, atinge)
        return min ([x [2] for x in roads if atinge [x [0]] or atinge [x [1]]])

