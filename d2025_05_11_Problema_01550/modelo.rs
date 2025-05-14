impl Solution {
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let mut cont: u32 = 0;
        for a in arr {
            if a & 1 == 1 { // Ímpar
                cont += 1;
            } else {
                cont = 0;
            }
            if cont == 3 {
                return true;
            }
        }
        false // Não achou
    }
}
