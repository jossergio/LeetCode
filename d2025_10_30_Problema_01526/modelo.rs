impl Solution {
    pub fn min_number_operations(target: Vec<i32>) -> i32 {
        let mut resposta = target [0];
        let t = target.len ();
        for i in 1..t {
            if target [i] > target [i - 1] {
                resposta += target [i] - target [i - 1];
            }
        }
        resposta
    }
}
