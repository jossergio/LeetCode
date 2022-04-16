# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
    valores = list ()
    
    def leituraReversa (self, raiz: TreeNode):
        if raiz != None:
            self.leituraReversa (raiz.right)
            self.valores.append (raiz.val)
            self.leituraReversa (raiz.left)
    
    def converter (self, raiz: TreeNode):
        if raiz != None:
            raiz.val += sum (self.valores [0:self.valores.index (raiz.val)])
            # Sempre haverá o valor em index
            self.converter (raiz.left)
            self.converter (raiz.right)
    
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        self.valores.clear ()
        
        self.leituraReversa (root)
        
        self.converter (root)
        
        return root
    
