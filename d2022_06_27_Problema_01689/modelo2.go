func minPartitions(n string) int {
    
    var resp int // = 0
    
    for _, v := range n {
        valor := int (v - '0')
        if valor > resp {
            resp = valor
        }
    }
    
    return resp
}

