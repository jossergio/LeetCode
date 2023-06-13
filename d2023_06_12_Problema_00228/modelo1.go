func summaryRanges(nums []int) []string {
    
    var resposta [] string
    var i int // = 0
    var t int = len (nums)
    
    for i < t {
        
        inicio := i
        tmp := strconv.Itoa (nums [i])
        
        i++
        
        for i < t && nums [i] == nums [i - 1] + 1 {
            i++
        }
        
        if i != inicio + 1 {
            tmp = tmp + "->" + strconv.Itoa (nums [i - 1])
        }
        
        resposta = append (resposta, tmp)
    }
    
    return resposta
}

