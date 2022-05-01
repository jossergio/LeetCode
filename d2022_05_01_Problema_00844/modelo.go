func r (s string) string {
    
    var r string // = ""
    
    for _, c := range s {
        if c == '#' {
            if len (r) > 0 {
                r = r [:len (r) - 1]
            }
        } else {
            r += string (c)
        }
        
    }
    
    return r
}


func backspaceCompare(s string, t string) bool {
    
    return r (s) == r (t)
    
}

