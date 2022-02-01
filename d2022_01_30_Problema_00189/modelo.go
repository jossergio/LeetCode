func rotate(nums []int, k int)  {
    
    k %= len (nums)
    
    if k == 0 {
        return // Não precisa, fecha ciclo
    }
    
    var resposta [] int = nums [len (nums) - k:]
    
    resposta = append (resposta, nums [0:len (nums) - k]...)
    
    for i, v := range resposta {
        nums [i] = v
    }
    
}

