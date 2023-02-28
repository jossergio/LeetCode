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

        def montar (no: Optional [TreeNode]) -> List [Optional [TreeNode]]:
            if not no == None:
                esquerda = montar (no.left)
                direita = montar (no.right)
                indice = (esquerda if not esquerda == None else tuple (), no.val, direita if not direita == None else tuple ()) # Para facilitar visualmente
                subarvores [indice] += 1
                if subarvores [indice] == 2: # Se outro número, ou já foi ou ainda vai
                    resposta.append (no)
                return indice
            return None # Só para constar; nem precisaria

        esquerda = montar (root.left)
        direita = montar (root.right)
        # Não precisa juntar, pois a árvore principal é única
        return resposta
    
