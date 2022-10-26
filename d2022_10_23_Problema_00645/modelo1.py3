class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        todos = set ([x for x in range (1, len (nums) + 1)])
        for i in nums:
            todos.discard (i)
        contados = Counter (nums)
        for i, v in contados.items ():
            if v == 2:
                return [i, todos.pop ()]
        # todos ficou com o que não tá na lista
        # contados tem o valor 2 no item duplicado
        return # Só para ter um no final

