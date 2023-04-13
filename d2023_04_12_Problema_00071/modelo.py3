class Solution:
    def simplifyPath(self, path: str) -> str:
        sep = path.split ("/")
        res = list ()
        for p in sep:
            if p == "..":
                if len (res) > 0:
                    res.pop ()
            elif len (p) > 0 and p != ".":
                res.append (p)
        return "/" + "/".join (res)
    
