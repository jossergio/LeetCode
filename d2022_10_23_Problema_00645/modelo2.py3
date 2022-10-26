class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        todos = set ([x for x in range (1, len (nums) + 1)])
        contados = Counter (nums)
        resposta = list ()
        for i, v in contados.items ():
            todos.discard (i)
            if v == 2:
                resposta.append (i)
                
        # todos ficou com o que não tá na lista
        # contados tem o valor 2 no item duplicado
        return resposta + [todos.pop ()]

