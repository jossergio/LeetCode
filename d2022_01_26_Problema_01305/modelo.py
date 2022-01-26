# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    def arvoreParaLista (self, arvore):
        
        if arvore != None:
            return self.arvoreParaLista (arvore.left) + [arvore.val] + self.arvoreParaLista (arvore.right)
        
        return []
    
    def getAllElements(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: List[int]
        """
        
        lista = self.arvoreParaLista (root1)
        lista.extend (self.arvoreParaLista (root2))
        
        return sorted (lista)

