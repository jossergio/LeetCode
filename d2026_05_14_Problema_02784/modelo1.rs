impl Solution {
    pub fn is_good(nums: Vec<i32>) -> bool {
        let mut nums = nums; // Torna mutável
        nums.sort ();
        let t = nums.len ();
        let mut n = 1usize;
        while n < t {
            if n as i32 != nums [n - 1] {
                return false;
            }
            n += 1;
        }
        if n == t as usize && nums [n - 1] == (n - 1) as i32 {
            return true;
        }
        // else
        false
    }
}
