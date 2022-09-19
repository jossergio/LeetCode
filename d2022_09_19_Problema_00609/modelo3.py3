class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        
        def pegarConteudo (arq):
            itens = arq.split ("(")
            return itens [0], itens [1][:-1]
        
        mapa = {}
        
        for a in paths:
            
            tmp = a.split (" ")
            caminho = tmp [0] # O primeiro item é o caminho (path)
            tmp.pop (0) # Tira o primeiro item; o caminho
            
            for item in tmp:
                a, c = pegarConteudo (item)
                mapa.setdefault (c, []) # Uma lista vazia, caso ainda não haja
                mapa [c].append (caminho + "/" + a)
                
        resposta = []
        
        for i, item in mapa.items ():
            
            if len (item) < 2:
                continue
                
            resposta.append (item)
            
        return resposta
    
