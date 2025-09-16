impl Solution {
    fn mdc (a: i32, b: i32) -> i32 {
        let (mut a, mut b) = (a, b); // Torna mutável
        if a < b {
            (a, b) = (b, a); // Inverte
        }
        while b > 0 {
            let tmp = a % b;
            a = b;
            b = tmp;
        }
        a // Conterá a resposta
    }
    fn mmc (a: i32, b: i32) -> i32 {
        ((a as i64 * b as i64) / (Self::mdc (a, b) as i64)) as i32
    }
    pub fn replace_non_coprimes(nums: Vec<i32>) -> Vec<i32> {
        let mut resposta: Vec<i32> = Vec::new ();
        resposta.push (nums [0]); // Há, pelo menos, um
        for v in &nums [1..] { // Começa do segundo
            let mut incluir: i32 = *v;
            while resposta.len () > 0 && Self::mdc (*resposta.last ().unwrap (), incluir) > 1 {
                incluir = Self::mmc (incluir, resposta.pop ().unwrap ());
            }
            resposta.push (incluir);
        }
        resposta
    }
}
