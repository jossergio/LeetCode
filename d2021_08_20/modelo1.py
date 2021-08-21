#coding: utf-8

class Solution(object):
    valores = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]
    mapaValoresH = dict ()
    mapaValoresV = dict ()
    mapaValoresGrupo = list ()
    
    def zerarMapa (self, inicio):
        for a in self.valores:
            self.mapaValoresH [a] = False
        self.mapaValoresV = self.mapaValoresH.copy ()
        if inicio:
            self.mapaValoresGrupo = list ()
            for b in range (0, 9):
                self.mapaValoresGrupo.append (dict (self.mapaValoresH.copy ()))

    def contem (self, mapa, v):
        if mapa [v]:
            return True
        mapa [v] = True
        return False

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        self.zerarMapa (True)
        for a in range (0, 9):
            self.zerarMapa (False)
            for b in range (0, 9):
                if board [a][b] != ".":
                    if self.contem (self.mapaValoresH, board [a][b]):
                        return False
                    if self.contem (self.mapaValoresGrupo [3 * (a // 3) + (b // 3)], board [a][b]):
                        return False
                if board [b][a] != ".":
                    if self.contem (self.mapaValoresV, board [b][a]):
                        return False
        return True

