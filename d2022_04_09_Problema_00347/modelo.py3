class Solution:
    def ordem (f, item):
        return item [1]
    
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        
        tmp = dict ()
        
        for n in nums:
            tmp [n] = tmp.get (n, 0) + 1
        
        hq = list ()
        
        for i in tmp.items ():
            heappush (hq, i)
            
        return [i [0] for i in nlargest (k, hq, key = self.ordem)]

