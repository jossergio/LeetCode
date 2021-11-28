func maxSubArray(nums []int) int {
    var referencial int = 0 // Referencial
    // A referência inicial será a propria soma do vetor
    for _, v := range nums {
        referencial += v
    }
    for len (nums) > 0 {
        soma := 0
        for _, v := range nums {
            soma += v
            if soma > referencial {
                referencial = soma
            } // if soma > referecial
        } // for range nums
        nums = nums [1:]
    } // len (nums) > 0
    return referencial
}

