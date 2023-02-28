# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        
        subarvores = defaultdict (int)
        resposta = list ()
        
        def montar (no: Optional [TreeNode]) -> str:
            if no == None:
                return "#"
            # else
            indice = str (no.val) + ";" + montar (no.left) + montar (no.right)
            subarvores [indice] += 1
            if subarvores [indice] == 2: # Se outro número, ou já foi ou ainda vai
                resposta.append (no)
            return indice # str
        
        esquerda = montar (root.left)
        direita = montar (root.right)
        # Não precisa juntar, pois a árvore principal é única
        return resposta
    
