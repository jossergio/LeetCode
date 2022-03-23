func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    
    t1 := len (nums1)
    t2 := len (nums2)
    
    if t1 == 0 && t2 == 0 { // Se vierem ambos vazios
        return 0
    }
    
    var i1, i2 int // = 0
    tamanhoTotal := ((t1 + t2) / 2) + 1 // Não precisa mesclar todos
    var ult, ant int
    
    rotacionarUltimo := func (i int) {
        ant = ult
        ult = i
    }
    
    for tamanhoTotal > 0 {
        
        if i1 < t1 && i2 < t2 {
            if nums1 [i1] <= nums2 [i2] {
                rotacionarUltimo (nums1 [i1])
                i1++
            } else {
                rotacionarUltimo (nums2 [i2])
                i2++
            }
        } else {
            if i1 < t1 {
                rotacionarUltimo (nums1 [i1])
                i1++
            } else {
                rotacionarUltimo (nums2 [i2])
                i2++
            }
        }
        
        tamanhoTotal--
    }
    
    if (t1 + t2) % 2 == 0 {
        return (float64 (ult) + float64 (ant)) / 2
    }
    
    return float64 (ult)
}

