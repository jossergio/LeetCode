class Solution(object):
    indices = list ()
    lista = list ()
    
    def inclua (self, i):
        ordem = list (i)
        ordem.sort ()
        try:
            indice = self.indices.index (ordem)
            self.lista [indice].append (i)

        except:
            self.lista.append (list ())
            self.lista [len (self.lista) - 1].append (i)
            self.indices.append (ordem)

    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        self.indices = list ()
        self.lista = list ()
        for a in strs:
            self.inclua (a)
        return self.lista

