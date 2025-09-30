impl Solution {
    pub fn triangular_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums; // Torna mutável
        while nums.len () != 1 {
            let t = nums.len ();
            let mut tmp: Vec<i32> = Vec::with_capacity (t);
            for i in 0..(t - 1) {
                tmp.push ((nums [i] + nums [i + 1]) % 10);
            }
            nums = tmp;
        }
        nums [0]
    }
}
