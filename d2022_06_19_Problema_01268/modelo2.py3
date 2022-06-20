class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        
        products.sort ()
        
        resp = list ()
        
        for i in range (len (searchWord)):
            
            tmp = list ()
            
            try: # index provoca erro se não encontrar
                base = [x [:i + 1] for x in products].index (searchWord [:i + 1])
            except:
                resp.append ([])
                continue
            
            for j in range (base, base + 3):
                if j < len (products) and products [j][:i + 1] == searchWord [:i + 1]:
                    tmp.append (products [j])
                else:
                    break
            
            resp.append (tmp)
            
        return resp
    
