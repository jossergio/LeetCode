type NumArray struct {
    nums [] int
}


func Constructor(nums []int) NumArray {
    var base NumArray
    base.nums = make ([] int, len (nums))
    copy (base.nums, nums)
    return base
}


func (this *NumArray) Update(index int, val int)  {
    this.nums [index] = val
}


func (this *NumArray) SumRange(left int, right int) int {
    var soma int
    
    for i := left; i <= right; i++ {
        soma += this.nums [i]
    }
    
    return soma
}


/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(index,val);
 * param_2 := obj.SumRange(left,right);
 */

