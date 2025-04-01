use std::collections::HashSet;
impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut nums = nums.clone (); // Sombreia
        nums.sort ();
        nums [1..].into_iter ().fold ((false, nums [0]), | acum, &a | if a == acum.1 { (true, a) } else { (acum.0 || false, a) }).0
    }
}
