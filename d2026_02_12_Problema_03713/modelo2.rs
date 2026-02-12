impl Solution {
    pub fn longest_balanced(s: String) -> i32 {
        let s = s.as_bytes ();
        let t = s.len ();
        let mut resposta: usize = 0; // As parcelas de cálculo são desse tipo
        for i in 0..t {
            let mut cont = vec![0; 26];
            for j in i..t {
                let k = (s [j] - b'a') as usize;
                cont [k] += 1;
                if cont
                    .iter ()
                    .all (
                        | v | *v == 0 || *v == cont [k]
                    ) {
                    resposta = resposta.max (j - i + 1);
                }
            }
        }
        resposta as i32
    }
}
