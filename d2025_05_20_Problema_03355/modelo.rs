impl Solution {
    pub fn is_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> bool {
        let t = nums.len ();
        let mut acums: Vec<i32> = vec! [0; t + 1];
        for a in queries {
            acums [a [0] as usize] += 1;
            acums [a [1] as usize + 1] -= 1;
        }
        for i in (1..=t) {
            acums [i] += acums [i - 1];
        }
        (0..t).all (|a| nums [a] <= acums [a])
    }
}
