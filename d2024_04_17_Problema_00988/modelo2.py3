# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        resposta = ""
        fila = [(root, [])] # Há, pelo menos, um; forma uma tupla
        while len (fila) > 0:
            atual, palavra = fila.pop ()
            palavra = palavra + [chr (atual.val + ord ('a'))] # val é uma ordem e não um ASCII
            if atual.left == None and atual.right == None:
                p = "".join (palavra [::-1])
                resposta = p if resposta == "" else min (resposta, p)
            if atual.left != None:
                fila.append ((atual.left, palavra))
            if atual.right != None:
                fila.append ((atual.right, palavra))
        return resposta
    
