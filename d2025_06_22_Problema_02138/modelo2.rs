impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        let t = s.len ();
        let mut resposta: Vec<String> = Vec::new ();
        let k = k as usize; // Só para alterar o tipo
        let mut i:usize = 0;
        while i + k <= t {
            resposta.push (String::from (&s [i..i + k]));
            i += k;
        }
        if i < t {
            resposta.push (String::from (&s [i..t]) + &String::from_iter (vec! [fill; k - (t - i)]));
        }
        resposta
    }
}
