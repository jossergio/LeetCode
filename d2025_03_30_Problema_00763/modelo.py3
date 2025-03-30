class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        niveis = list ()
        niveis.append ([[s [0]], set ([s [0]])]) # Há, pelo menos, um; evita testes repetitivos no laço
        for c in s [1:]:
            incluido = -1
            for (i, n) in enumerate (niveis):
                if c in n [1]:
                    incluido = i
                    break
            if incluido == -1:
                niveis.append ([[c], set ([c])])
            else:
                niveis [-1][0].append (c)
                niveis [-1][1].add (c)
                for n in range (incluido + 1, len (niveis)):
                    niveis [incluido][0] += niveis [n][0]
                    niveis [incluido][1] |= niveis [n][1]
                niveis = niveis [:incluido + 1]
        return [len (a [0]) for a in niveis]
