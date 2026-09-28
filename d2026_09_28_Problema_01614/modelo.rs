impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut atual = 0;
        let mut maximo = 0;
        for c in s.bytes () {
            if c == b'(' {
                atual += 1;
                maximo = maximo.max (atual);
            } else if c == b')' {
                atual -= 1;
            }
        }
        maximo
    }
}
