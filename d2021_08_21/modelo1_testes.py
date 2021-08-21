class Solution(object):
    valores = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
    
    def podeUsar (self, q, a, b, i):
        for zz in range (9):
            if q [a][zz] == i or q [zz][b] == i:
                return False
        for za in range (3):
            for zb in range (3):
                if q [3 * (a // 3) + za][3 * (b // 3) + zb] == i:
                    return False
        return True
    
    def mostrarQuadro (self, q):
        print ("= = = = =")
        for a in range (9):
            print ("[", end = "")
            for b in range (9):
                print (q [a][b], end = "")
                if b < 8:
                    print (" ", end = "")
            print ("]")

    def checar (self, quadro):
        temPonto = False
        # self.mostrarQuadro (quadro)
        # input ("Enter:")
        for a in range (9):
            for b in range (9):
                if quadro [a][b] == ".":
                    temPonto = True
                    for item in self.valores:
                        if self.podeUsar (quadro, a, b, item):
                            quadro [a][b] = item
                            if self.checar (quadro):
                                return True
                            else: # if checar quadro
                                quadro [a][b] = "." # Retorna ao estado anterior
                    return False
        return not temPonto # O quadro está completo e passou. Devo otimizar?
    
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        
        if self.checar (board):
            print ("Tem solução!")
        else:
            print ("Vai retornar uma solução inválida")
        return board

c = Solution ()

board = [["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]]
  
c.solveSudoku (board)
c.mostrarQuadro (board)

