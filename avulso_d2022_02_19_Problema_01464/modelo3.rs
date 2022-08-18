impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        
        let mut nums = nums; // Só para sombrear e tornar mutável
        
        nums.sort_by (|a, b| b.cmp (a));
        
        return (nums [0] - 1) * (nums [1] - 1)
    }
}

