use std::collections::BinaryHeap;
impl Solution {
    pub fn maximum_happiness_sum(happiness: Vec<i32>, k: i32) -> i64 {
        let mut b: BinaryHeap<i64> = BinaryHeap::from_iter (happiness.into_iter ().map (| v | v as i64));
        let mut resposta = 0i64;
        let mut dec = 0i64;
        let mut k = k; // Torna mutável
        while k > 0 && !b.is_empty () {
            let tmp = b.pop ().unwrap () - dec;
            if tmp > 0 {
                resposta += tmp;
            } else {
                break; // Não haverá maior que zero
            }
            dec += 1;
            k -= 1
        }
        resposta
    }
}
