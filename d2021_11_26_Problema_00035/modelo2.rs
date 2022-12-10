impl Solution {
    pub fn busca_binaria (nums: &Vec<i32>, target: i32, i: usize, j: usize) -> usize {
        if i > j {
            return i
        }
        // else
        let meio: usize = (i + j) / 2;
        if nums [meio] == target {
            return meio
        }
        // else
        if target > nums [meio] {
            return Solution::busca_binaria (nums, target, meio + 1, j)
        }
        // else
        return Solution::busca_binaria (nums, target, i, meio - 1)

    }
    
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        if target < nums [0] {
            return 0
        }
        // else
        if target > nums [nums.len () - 1] {
            return nums.len () as i32
        }
        // else
        // Os testes anteriores, além de agilizarem, impedem o erro "under", pois o tipo usize não assume valor negativo, quando necessário
        return Solution::busca_binaria (&nums, target, 0, nums.len () - 1) as i32;
    }
}

