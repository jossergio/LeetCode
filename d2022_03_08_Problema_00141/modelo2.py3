# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        while head != None:
            
            if head.val == 100001: # Um valor acima dos que podem ser definidos
                return True
            
            head.val = 100001 # Altera o valor, para marcar passagem
            head = head.next
        
        return False

