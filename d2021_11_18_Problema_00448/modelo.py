class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort ()
        indice = 1
        indiceNums = 0
        resultado = list ()
        while indiceNums < len (nums):
            while indice < nums [indiceNums]:
                resultado.append (indice)
                indice += 1
            
            while indiceNums < len (nums) and indice == nums [indiceNums]:
                indiceNums += 1
            indice += 1

        while indice <= indiceNums:
            resultado.append (indice)
            indice += 1

        return resultado

