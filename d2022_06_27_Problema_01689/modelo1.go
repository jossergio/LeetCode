func minPartitions(n string) int {
    
    var resp int // = 0
    
    for i := 0; i < len (n); i++ {
        valor := int (n [i] - '0')
        if valor > resp {
            resp = valor
        }
    }
    
    return resp
}

