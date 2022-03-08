# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        
        lista = list ()
        
        while head != None:
            lista.append (head)
            try:
                if lista.index (head.next):
                    return True
            except:
                pass
            head = head.next
        
        return False

