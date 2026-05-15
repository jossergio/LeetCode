impl Solution {
    pub fn is_good(nums: Vec<i32>) -> bool {
        let mut nums = nums; // Torna mutável
        nums.sort ();
        let t = nums.len ();
        for n in 1..t {
            if nums [n - 1] != (t.min (n)) as i32 {
                return false;
            }
        }
        nums [t - 1] == (t - 1) as i32
    }
}
