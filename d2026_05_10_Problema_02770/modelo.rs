impl Solution {
    fn buscar (nums: &Vec<i32>, i: usize, target: i32, memo: &mut Vec<i32>) -> i32 {
        if memo [i] == -2 {
            memo [i] = -1; //Base
            for j in (i + 1)..nums.len () {
                if i32::abs (nums [i] - nums [j]) <= target {
                    let tmp = Self::buscar (nums, j, target, memo);
                    if tmp != -1 {
                        memo [i] = memo [i].max (1 + tmp);
                    }
                }
            }
        }
        memo [i]
    }
    pub fn maximum_jumps(nums: Vec<i32>, target: i32) -> i32 {
        let t = nums.len ();
        let mut memo = vec![-2; t];
        memo [t - 1] = 0; // Final
        Self::buscar (&nums, 0, target, &mut memo)
    }
}
