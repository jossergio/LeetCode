class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        altura = len (heights)
        largura = len (heights [0])
        resposta = [[set () for _ in range (largura)] for _ in range (altura)]

        # Constantes
        PACIFICO = "Pacífico"
        ATLANTICO = "Atlântico"

        def buscar (i: int, j: int, oceano: str):
            if oceano not in resposta [i][j]:
                resposta [i][j].add (oceano)
                if i > 0 and heights [i - 1][j] >= heights [i][j]:
                    buscar (i - 1, j, oceano)
                if i < altura - 1 and heights [i + 1][j] >= heights [i][j]:
                    buscar (i + 1, j, oceano)
                if j > 0 and heights [i][j - 1] >= heights [i][j]:
                    buscar (i, j - 1, oceano)
                if j < largura - 1 and heights [i][j + 1] >= heights [i][j]:
                    buscar (i, j + 1, oceano)

        for i in range (altura):
            buscar (i, 0, PACIFICO)
            buscar (i, largura - 1, ATLANTICO)
        for j in range (largura):
            buscar (0, j, PACIFICO)
            buscar (altura - 1, j, ATLANTICO)
        
        return [[i, j] for i in range (altura) for j in range (largura) if len (resposta [i][j]) == 2]
