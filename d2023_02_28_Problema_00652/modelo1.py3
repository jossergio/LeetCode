# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def montar (self, no: Optional [TreeNode]) -> List [Optional [TreeNode]]:
        if not no == None:
            esquerda = self.montar (no.left)
            direita = self.montar (no.right)
            indice = (esquerda if not esquerda == None else tuple (), no.val, direita if not direita == None else tuple ()) # Para facilitar visualmente
            self.subarvores [indice] += 1
            if self.subarvores [indice] == 2: # Se outro número, ou já foi ou ainda vai
                self.resposta.append (no)
            return indice
        return None # Só para constar; nem precisaria
            
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.subarvores = defaultdict (int)
        self.resposta = list ()
        esquerda = self.montar (root.left)
        direita = self.montar (root.right)
        # Não precisa juntar, pois a árvore principal é única
        return self.resposta
    
