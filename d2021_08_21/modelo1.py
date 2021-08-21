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
        
        # Deixei esse trecho de testes
        # if self.checar (board):
        #     print ("Tem solução!")
        # else:
        #     print ("Vai retornar uma solução inválida")

        self.checar (board)
        return board

