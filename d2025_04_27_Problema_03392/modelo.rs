impl Solution {
    pub fn count_subarrays(nums: Vec<i32>) -> i32 {
        let mut resp = 0; // i32
        let t = nums.len ();
        for i in 0..=(t - 3) {
            if ((nums [i] + nums [i + 2]) * 2) == nums [i + 1] {
                resp += 1;
            }
        }
        resp
    }
}
