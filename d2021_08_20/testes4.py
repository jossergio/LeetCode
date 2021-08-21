#coding: utf-8

# Um teste de vera, pego de resposta errada
# Teria que returnar True. Porém, estava retornando False
# Nesse teste, retornou verdadeiro, como esperado

import modelo1

c = modelo1.Solution ()

board = [[".","8","7","6","5","4","3","2","1"],
["2",".",".",".",".",".",".",".","."],
["3",".",".",".",".",".",".",".","."],
["4",".",".",".",".",".",".",".","."],
["5",".",".",".",".",".",".",".","."],
["6",".",".",".",".",".",".",".","."],
["7",".",".",".",".",".",".",".","."],
["8",".",".",".",".",".",".",".","."],
["9",".",".",".",".",".",".",".","."]]

print (c.isValidSudoku (board))

