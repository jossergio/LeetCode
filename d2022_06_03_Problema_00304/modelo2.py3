class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        self.matriz = matrix

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        
        resposta = 0
        
        for linha in self.matriz [row1:row2 + 1]:
            for item in linha [col1:col2 + 1]:
                resposta += item
        
        return resposta

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)

