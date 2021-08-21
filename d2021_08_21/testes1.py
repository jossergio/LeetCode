# Por questões de formatação da impressão do resultado dos testes
# melhor rodar no Python 3

import modelo1

def mostrarQuadro (q):
    print ("= = = = =")
    for a in range (9):
        print ("[", end = "")
        for b in range (9):
            print (q [a][b], end = "")
            if b < 8:
                print (" ", end = "")
        print ("]")



c = modelo1.Solution ()

board = [["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]]
  
print ("Modelo antes da solução:")
mostrarQuadro (board)
c.solveSudoku (board)
print ("Modelo após a solução")
mostrarQuadro (board)

