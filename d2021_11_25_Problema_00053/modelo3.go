func maxSubArray(nums []int) int {
    var referencial int = -10000 // O problema define esse como o menor valor de cada unidade
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

