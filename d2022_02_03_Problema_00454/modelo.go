func fourSumCount(nums1 []int, nums2 []int, nums3 []int, nums4 []int) int {
    
    
    var resposta int // = 0
    
    var tamanho int = len (nums1) // Iguais
    
    for i := 0; i < tamanho; i++ {
        
        for j := 0; j < tamanho; j++ {
            
            for k := 0; k < tamanho; k++ {
                for l := 0; l < tamanho; l++ {
                    
                    if nums1 [i] + nums2 [j] + nums3 [k] + nums4 [l] == 0 {
                        resposta++
                    }
                    
                }
                
            }
            
        }
        
    }
    
    return resposta
}

