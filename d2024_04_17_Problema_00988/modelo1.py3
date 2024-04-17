# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        palavras = []
        
        def buscar (no, palavra):
            palavra = [chr (no.val + 97)] + palavra # Há, pelo menos, um
            # val é uma ordem e não um valor ASCII
            if no.left == None and no.right == None:
                palavras.append ("".join (palavra))
            else:
                if no.left != None:
                    buscar (no.left, palavra) # val é uma ordem, não um ASCII
                if no.right != None:
                    buscar (no.right, palavra)
                    
        buscar (root, [])
        return sorted (palavras) [0]

