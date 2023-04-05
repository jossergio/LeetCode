class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        heap = [(-valor, idx) for idx, valor in enumerate (nums)] # Valor negativo, para inverter a ordem no heap
        heapify (heap)
        while True:
            valor, idx = heappop (heap)
            if idx != 0 and nums [idx] > nums [idx - 1]:
                idx2 = heap.index ((-nums [idx - 1], idx - 1))
                nums [idx] -= 1
                nums [idx - 1] += 1
                heap [idx2] = (-nums [idx - 1], idx - 1)
                heap.append ((-nums [idx], idx))
                heapify (heap)
            else:
                heappush (heap, (valor, idx)) # Repõe
                break
        print (heap)
        valor, idx = heappop (heap)
        return -valor # Retorna a positivo
    
