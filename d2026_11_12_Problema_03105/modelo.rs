impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        let mut asc: i32 = 1; // Menor possível; cintador pontual
        let mut desc: i32 = 1;
        let mut ma: i32 = 1; // Contador geral
        let mut md: i32 = 1;
        let t = nums.len ();
        for i in 1..t {
            if nums [i - 1] < nums [i] {
                asc += 1;
                if asc > ma {
                    ma = asc;
                }
            } else {
                asc = 1;
            }
            if nums [i - 1] > nums [i] {
                desc += 1;
                if desc > md {
                    md = desc;
                }
            } else {
                desc = 1;
            }
        }
        if ma > md { ma } else { md }
    }
}
