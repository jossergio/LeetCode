impl Solution {
    pub fn triangular_sum(nums: Vec<i32>) -> i32 {
        let mut nums = nums; // Torna mutável
        while nums.len () > 1 {
            for i in 0..(nums.len () - 1) {
                nums [i] = (nums [i] + nums [i + 1]) % 10;
            }
            nums.pop ();
        }
        nums [0]
    }
}
