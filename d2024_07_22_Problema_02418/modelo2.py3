class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [nome for altura, nome in sorted (zip (heights, names), reverse = True)]
        
