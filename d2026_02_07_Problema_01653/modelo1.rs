impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let t = s.len ();
        let mut a = vec![0; t];
        let mut b = vec![0; t];
        let s: Vec<char> = s.chars ().collect ();
        if s [0] == 'a' {
            a [0] = 1;
        }
        if s [t - 1] == 'b' {
            b [t - 1] = 1;
        }
        for i in 1..t {
            if s [i] == 'a' {
                a [i] = a [i - 1] + 1;
            } else {
                a [i] = a [i - 1];
            }
            if s [t - i - 1] == 'b' {
                b [t - i - 1] = b [t - i] + 1;
            } else {
                b [t - i - 1] = b [t - i];
            }
        }
        let mut resposta = i32::MAX;
        for i in 0..t {
            resposta = resposta.min (t as i32 - (a [i] + b [i]));
        }
        resposta
    }
}
