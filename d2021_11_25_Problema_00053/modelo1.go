func maxSubArray(nums []int) int {
    var tamanho int = len (nums) // Será usado várias vezes
    var referencial int = 0 // Referencial
    // A referência inicial será a propria soma do vetor
    for _, v := range nums {
        referencial += v
    }
    for i := 0; i < tamanho; i++ {
        soma := 0
        for j := i; j < tamanho; j++ {
            soma += nums [j]
            if soma > referencial {
                referencial = soma
            } // if soma > referecial
        } // for j
    } // for i
    return referencial
}

