class Solution:
    def isPathCrossing(self, path: str) -> bool:
        atualX = 0
        atualY = 0
        mov = dict ()
        mov ['N'] = (0, 1)
        mov ['S'] = (0, -1)
        mov ['E'] = (1, 0)
        mov ['W'] = (-1, 0)
        movs = list ()
        movs.append ((atualX, atualY))
        for p in path:
            atualX += mov [p][0]
            atualY += mov [p][1]
            if (atualX, atualY) in movs:
                return True
            movs.append ((atualX, atualY))
        return False

