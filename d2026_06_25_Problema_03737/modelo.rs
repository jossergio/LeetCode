impl Solution {
    pub fn count_majority_subarrays(nums: Vec<i32>, target: i32) -> i32 {
        let mut resp = 0;
        let mut t = nums.len ();
        for i in 0..t {
            let mut cont = 0;
            for (j, &v) in nums.iter ().skip (i).enumerate () {
                if v == target {
                    cont += 1;
                }
                if 2 * cont > j + 1 {
                    resp += 1
                }
            }
        }
        resp
    }
}
