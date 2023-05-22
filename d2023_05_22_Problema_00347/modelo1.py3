class Solution:
    def ordem (self, item):
        return item [1]
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        return [i [0] for i in nlargest (k, [(i, v) for i, v in Counter (nums).items ()], self.ordem)]
    
