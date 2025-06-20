impl Solution {
    pub fn partition_array(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums; // Sombreia e torna mutável
        let t = nums.len ();
        let mut i: usize = 0;
        nums.sort ();
        let mut r = 0; // i32
        while i < t {
            let f = nums [i];
            i += 1;
            r += 1;
            while i < t && nums [i] - f <= k {
                i += 1;
            }
        }
        r
    }
}
