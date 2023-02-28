# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def montar (self, no: Optional [TreeNode]) -> str:
        if no == None:
            return "#"
        # else
        indice = str (no.val) + ";" + self.montar (no.left) + self.montar (no.right)
        self.subarvores [indice] += 1
        print (indice, self.subarvores [indice])
        if self.subarvores [indice] == 2: # Se outro número, ou já foi ou ainda vai
            self.resposta.append (no)
        return indice # str
            
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.subarvores = defaultdict (int)
        self.resposta = list ()
        esquerda = self.montar (root.left)
        direita = self.montar (root.right)
        # Não precisa juntar, pois a árvore principal é única
        return self.resposta
    
