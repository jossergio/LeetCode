# coding: utf-8

class Solution(object):
    def tratarEmail (self, email):
        partes = email.split ("@")
        primario = partes [0].split ("+")
        tmp = [letra for letra in primario [0] if letra != "."]
        partes [0] = "".join (tmp)
        return "@".join (partes)

    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """

        tratados = set ()
        for email in emails:
            tratados.add (self.tratarEmail (email))
        return len (tratados)

