class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        
        contar = [0] * 7 # Conta cada número, sendo 0 desprezado na lista
        embaixos = [0] * 7 # Similar
        emCimas = [0] * 7
        
        for i in range (len (tops)): # Tanto faz tops ou bottons
            contar [tops [i]] += 1
            if tops [i] != bottoms [i]:
                contar [bottoms [i]] += 1
                embaixos [bottoms [i]] += 1
                emCimas [tops [i]] += 1
            
        numero, maximo = 0, 0
        
        for i in range (1, len (contar)):
            if contar [i] > maximo:
                maximo = contar [i]
                numero = i
                
        if maximo != len (tops) or numero == 0: # tops ou bottons, tanto faz
            return -1
        
        return embaixos [numero] if embaixos [numero] < emCimas [numero] else emCimas [numero]
    
            