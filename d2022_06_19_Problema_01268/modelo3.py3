class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        
        products.sort ()
        
        resp = list ()
        
        for i in range (len (searchWord)):
            
            tmp = list ()
            
            products = [p for p in products if p [:i + 1] == searchWord [:i + 1]]
            
            for q in products [:3]:
                tmp.append (q)
           
            resp.append (tmp)
            
        return resp
    
