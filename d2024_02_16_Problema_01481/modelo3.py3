class Solution:

    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:

        contagem = sorted ([a for a in Counter (arr).values ()])

        for i in range (len (contagem)):

            if k >= contagem [i]:

                k -= contagem [i]

            else:

                return len (contagem) - i

        return 0 # Só para ter uma exceção

