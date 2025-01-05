impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let mut nums = nums.clone ();
        nums.sort ();
        nums [nums.len () / 2]
    }
}

