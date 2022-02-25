class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        
        vs1 = version1.split (".")
        vs2 = version2.split (".")
        
        tamanho = len (vs1)
        
        if len (vs2) > tamanho:
            tamanho = len (vs2)
        
        vi1 = list ()
        vi2 = list ()
        
        for v in vs1:
            vi1.append (int (v))
            
        for v in vs2:
            vi2.append (int (v))
        
        while len (vi1) < tamanho:
            vi1.append (0)
            
        while len (vi2) < tamanho:
            vi2.append (0)
        
        for i in range (tamanho):
            if vi1 [i] < vi2 [i]:
                return -1
            elif vi1 [i] > vi2 [i]:
                return 1
        
        return 0
    
