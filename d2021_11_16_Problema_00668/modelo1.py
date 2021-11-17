class Solution(object):
    def findKthNumber(self, m, n, k):
        """
        :type m: int
        :type n: int
        :type k: int
        :rtype: int
        """

        numeros = list ()
        for i in xrange (1, m + 1):
            for j in xrange (1, n + 1):
                numeros.append (i * j)
        numeros.sort ()
        return numeros [k - 1]

