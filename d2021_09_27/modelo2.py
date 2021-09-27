# coding: utf-8

class Solution(object):
    def tratarEmail (self, email):
        partes = email.split ("@")
        primario = partes [0].split ("+")
        partes [0] = "".join ([letra for letra in primario [0] if letra != "."])
        return "@".join (partes)

    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """

        return len (set ([self.tratarEmail (email) for email in emails]))

