impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        
        if nums.len () == 0 {
            return 0
        }
        
        let mut k: usize = 0;
        let tamanho: usize = nums.len ();
        
        for i in 1..tamanho {
            if nums [k] != nums [i] {
                k += 1;
                nums [k] = nums [i]
            }
        }
        
        return (k + 1) as i32 // 0 - < k
    }
}

