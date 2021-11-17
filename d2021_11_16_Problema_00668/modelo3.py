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
            for j in xrange (i, (n + 1) * i, i):
                numeros.append (j)
        numeros.sort ()
        return numeros [k - 1]

