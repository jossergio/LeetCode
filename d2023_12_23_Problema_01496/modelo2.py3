class Solution:
    def isPathCrossing(self, path: str) -> bool:
        atualX = 0
        atualY = 0
        mov = {'N': (0, 1), 'S': (0, -1), 'E': (1, 0), 'W': (-1, 0)}
        movs = {(atualX, atualY)} # set; insere a primeira tupla
        for p in path:
            atualX += mov [p][0]
            atualY += mov [p][1]
            if (atualX, atualY) in movs:
                return True
            movs.add ((atualX, atualY))
        return False

