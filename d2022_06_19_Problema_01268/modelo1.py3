class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        
        products.sort ()
        
        resp = list ()
        
        for i in range (len (searchWord)):
            
            tmp = [p for p in products if p [0:i + 1] == searchWord [0:i + 1]]
            
            resp.append (tmp [0:3])
            
        return resp
    
