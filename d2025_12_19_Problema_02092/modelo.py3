class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        # O parâmetro n não me foi necessário
        tempos = set () # Conterá todos os momentos que foram identificados; só para organização
        temposEncontros = defaultdict (list) # Conterá o pessoal que tem encontro em cada momento
        for m in meetings:
            tempos.add (m [2]) # o momento é o 3o item (0-begin)
            temposEncontros [m [2]].append (set ([m [0], m [1]]))
        resposta = set ([0, firstPerson]) # Esses dois já constam na lista; iniciadores
        for t in sorted (tempos): # sorted para seguir a linha crescente de tempo
            tmp = temposEncontros [t]
            alterou = True # Pressupõe
            while alterou and len (tmp) != 1:
                alterou = False # Define
                for i in range (len (tmp) - 1):
                    for j in range (i + 1, len (tmp)):
                        if not tmp [i].isdisjoint (tmp [j]):
                            tmp [i].update (tmp [j])
                            tmp.pop (j)
                            alterou = True
                            break;
                    if alterou:
                        break
            for encontro in tmp:
                if not resposta.isdisjoint (encontro):
                    resposta.update (encontro)
        return sorted (resposta)
