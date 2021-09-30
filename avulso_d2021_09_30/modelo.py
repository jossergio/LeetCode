class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        numero = list ()
        if x == 0:
            numero.append (str (0))
        else:
            if x < 0:
                numero.append ("-")
                x = -x
        while x != 0:
            numero.append (str (x % 10))
            x /= 10
        retorno = int ("".join (numero))
        if (retorno > 2 ** 31 - 1) or (retorno < (-2) ** 31): retorno = 0
        return retorno

