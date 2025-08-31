class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        linhas = [set () for _ in range (9)]
        colunas = [set () for _ in range (9)]
        caixas = [set () for _ in range (9)]

        for i in range (9):
            for j in range (9):
                tmp = board [i][j]
                if tmp != ".":
                    linhas [i].add (tmp)
                    colunas [j].add (tmp)
                    caixas [((i // 3) * 3) + j // 3].add (tmp)
        
        valores = [str (a) for a in range (1, 10)]

        def proximo (a: int, b: int) -> ():
            b += 1
            if b == 9: # Igual máquina de escrever
                a += 1
                b = 0
            return a, b

        def checar (i: int, j: int) -> bool:
            a, b = proximo (i, j) # Já prepara para o próximo, pois será visto mais de uma vez, no código
            if i < 9:
                if board [i][j] == ".":
                    cx = ((i // 3) * 3) + (j // 3) # Será utilizado mais de uma vez, além de melhorar o visual do código
                    tmp = set (valores) - (linhas [i] | colunas [j] | caixas [cx])
                    if len (tmp) == 0:
                        return False
                    # else
                    for v in tmp:
                        board [i][j] = v
                        linhas [i].add (v)
                        colunas [j].add (v)
                        caixas [cx].add (v)
                        if checar (a, b):
                            return True
                        # else
                        board [i][j] = "." # Retorna ao estado anterior
                        linhas [i].remove (v)
                        colunas [j].remove (v)
                        caixas [cx].remove (v)
                    return False # Se chegar aqui, não encontrou
                else:
                    return checar (a, b) # Testa o próximo
            # else i < 9
            return True # Chegou aqui e encontrou

        checar (0, 0)

