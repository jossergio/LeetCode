impl Solution {
    fn buscar (memo: &mut Vec<i32>, costs: &Vec<i32>, i: usize) -> i32 {
        if memo [i] == -1 {
            if i == memo.len () - 1 {
                memo [i] = 0;
            } else {
                memo [i] = i32::MAX;
                for j in 1..=3 {
                    if i + j < memo.len () {
                        memo [i] = memo [i].min (costs [i + j - 1] + j.pow (2) as i32 + Self::buscar (memo, costs, i + j));
                    }
                }
            }
        }
        memo [i]
    }
    pub fn climb_stairs(n: i32, costs: Vec<i32>) -> i32 {
        let mut memo = vec![-1; n as usize + 1];
        Self::buscar (&mut memo, &costs, 0)
    }
}
