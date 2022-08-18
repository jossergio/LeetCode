func pegarMaximo (a, b int) int {
    if a > b {
        return a
    }
    return b
}

func maxProduct(nums []int) int {
    
    var maximo int // = 0
    var t int = len (nums)
    
    for i := 0; i < t; i++ {
        for j := i + 1; j < t; j++ {
            maximo = pegarMaximo (maximo, (nums [i] - 1) * (nums[j] - 1))
        }
    }
    return maximo
}

