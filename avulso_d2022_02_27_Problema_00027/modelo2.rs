impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        
        let mut k = nums.len (); // usize
        let mut i:usize = 0;
        
        while (i < k) {
            if nums [i] == val {
                k -= 1;
                nums [i] = nums [k];
            } else {
                i += 1;
            }
        }
        
        return k as i32 // k é o tamanho final do vetor
    }
}

