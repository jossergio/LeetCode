# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        lista = set ()
        
        while head:
            lista.add (head)
            if head.next in lista:
                return True
            head = head.next
        
        return False

