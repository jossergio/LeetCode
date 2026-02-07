impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let t = s.len ();
        let mut a = vec![0; t];
        let mut b = vec![0; t];
        let mut c_a = 0;
        let mut c_b = 0;
        let s: Vec<char> = s.chars ().collect ();
        for i in 0..t {
            a [t - i - 1] = c_a;
            b [i] = c_b;
            if s [t - i - 1] == 'a' {
                c_a += 1;
            }
            if s [i] == 'b' {
                c_b += 1;
            }
        }
        let mut resposta = t as i32; // O máximo que se pode remover
        for i in 0..t {
            resposta = resposta.min (a [i] + b [i]);
        }
        resposta
    }
}
