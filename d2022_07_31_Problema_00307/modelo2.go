type NumArray struct {
    nums [] int
    somatorios [] int
}


func Constructor(nums []int) NumArray {
    var base NumArray
    
    base.nums = nums

    var tamanhoSomatorios int = int (math.Ceil (float64 (len (nums)) / math.Sqrt (float64 (len (nums)))))
    
    base.somatorios = make ([] int, tamanhoSomatorios)

    for i, v := range nums {
        base.somatorios [i / tamanhoSomatorios] += v
    }
    
    return base
}


func (this *NumArray) Update(index int, val int)  {
    
    var pSomatorios int = index / len (this.somatorios)
    
    this.somatorios [pSomatorios] += val - this.nums [index]
    
    this.nums [index] = val
}


func (this *NumArray) SumRange(left int, right int) int {
    var soma int
    var tamanhoSomatorios = len (this.somatorios)
    var inicio int = left / tamanhoSomatorios
    var final int = right / tamanhoSomatorios
    
    if inicio == final {
        for i := left; i <= right; i++ {
            soma += this.nums [i]
        }
    } else {
        
        for i := left; i <= ((inicio + 1) * tamanhoSomatorios) - 1; i++ {
            soma += this.nums [i]
        }
        
        for i := inicio + 1; i <= final - 1; i++ {
            soma += this.somatorios [i]
        }
        
        for i:= final * tamanhoSomatorios; i <= right; i++ {
            soma += this.nums [i]
        }
    }
    
    return soma
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(index,val);
 * param_2 := obj.SumRange(left,right);
 */

