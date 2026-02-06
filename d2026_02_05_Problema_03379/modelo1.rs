impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let t = nums.len ();
        let mut res = vec![0; t];
        for i in 0..t {
            let mut base = nums [i].abs () as usize;
            if nums [i] == 0 {
                base = i;
            } else if nums [i] > 0 {
                base = (i + base) % t;
            } else { // < 0
                if i < base {
                    base = (t - (base % t - i)) % t;
                } else {
                    base = i - base;;
                }
            }
            res [i] = nums [base];
        }
        res
    }
}
