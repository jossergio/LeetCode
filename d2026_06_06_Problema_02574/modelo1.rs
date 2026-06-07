impl Solution {
    pub fn left_right_difference(nums: Vec<i32>) -> Vec<i32> {
        let t = nums.len ();
        let mut r = vec![0; t];
        let mut esq = nums [0];
        let mut dir = nums [t - 1];
        for i in 1..t {
            if r [i] == 0 {
                r [i] = esq;
            } else {
                r [i] = i32::abs (r [i] - esq);
            }
            let j = t - i - 1; // Facilita a visualização
            if r [j] == 0 {
                r [j] = dir;
            } else {
                r [j] = i32::abs (r [j] - dir);
            }
            esq += nums [i];
            dir += nums [j];
        }
        r
    }
}
