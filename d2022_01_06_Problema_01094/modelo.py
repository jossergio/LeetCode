class Solution:
    def ordem (self, i:List):
        return i [1]
    
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        trips.sort (key = self.ordem)
        tamanho = len (trips) - 1
        saldos = [0 for i in range (trips [tamanho][1] + 1)]
        # Os que descem depois não importam
        for t in trips:
            saldos [t [1]] += t [0]
            if t [2] < len (saldos):
                saldos [t [2]] -= t [0]
        cargaAtual = 0
        for saldo in saldos:
            cargaAtual += saldo
            if cargaAtual > capacity:
                return False
        return True

