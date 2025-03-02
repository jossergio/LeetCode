impl Solution {
    pub fn apply_operations(nums: Vec<i32>) -> Vec<i32> {
        let mut tmp = nums.clone ();
        let t = tmp.len ();
        for i in 0..(t - 1) {
            if tmp [i] == tmp [i + 1] {
                tmp [i] *= 2;
                tmp [i + 1] = 0;
            }
        }
        let mut i: usize = 0;
        let mut zero: usize = 0;
        while i < t && zero < t {
            if tmp [zero] == 0 {
                while i < t && tmp [i] == 0 {
                    i += 1;
                }
                if i != t {
                    tmp [zero] = tmp [i];
                    tmp [i] = 0;
                }
            }
            zero += 1;
            i += 1;
        }
        tmp
    }
}
