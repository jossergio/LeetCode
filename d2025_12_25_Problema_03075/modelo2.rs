impl Solution {
    pub fn maximum_happiness_sum(happiness: Vec<i32>, k: i32) -> i64 {
        let mut happiness = happiness; // Torna mutável
        happiness.sort_by (| a, b | b.cmp (&a));
        let mut resposta = 0i64;
        for i in 0..(k as usize).min (happiness.len ()) {
            let tmp = happiness [i] as i64 - i as i64;
            resposta += if tmp > 0 { tmp } else { 0 };
        }
        resposta
    }
}
