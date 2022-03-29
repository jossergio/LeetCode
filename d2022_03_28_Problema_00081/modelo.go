func procurar (nums [] int, target int, i int, f int) bool {
    
    if i > f {
        return false
    }
    
    meio := (i + f) / 2
    
    if nums [meio] == target {
        return true
    } else {
        if i == f {
            return false
        }
    }
    
    if nums [i] < nums [f] {
        if target > nums [meio] {
            return procurar (nums, target, meio + 1, f)
        } else {
            return procurar (nums, target, i, meio - 1)
        }
    } else {
        return procurar (nums, target, i, meio - 1) || procurar (nums, target, meio + 1, f)
    }
    
    return false // Só para constar
}


func search(nums []int, target int) bool {
    return procurar (nums, target, 0, len (nums) - 1)
}

