# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    def arvoreParaLista (self, arvore: TreeNode) -> List [int]:
        if arvore != None:
            return self.arvoreParaLista (arvore.left) + [arvore.val] + self.arvoreParaLista (arvore.right)
        return []
    
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        
        lista = self.arvoreParaLista (root1)
        lista.extend (self.arvoreParaLista (root2))
        lista.sort ()
        return lista
        
