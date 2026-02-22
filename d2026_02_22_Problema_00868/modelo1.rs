impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut uns: Vec<i32> = (0..32)
            .filter (| i | n & (1 << i) != 0)
            .collect ();
        let mut resposta = 0; // Infere i32
        for i in 1..uns.len () {
            resposta = resposta.max (uns [i] - uns [i - 1]);
        }
        resposta
    }
}
