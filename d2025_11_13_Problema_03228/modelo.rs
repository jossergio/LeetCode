impl Solution {
    pub fn max_operations(s: String) -> i32 {
        let mut contador = 0;
        let mut uns = 0;
        let mut zero = false; // Era zero, anteriormente
        for &b in s.as_bytes () {
            if b == b'1' {
                if zero {
                    contador += uns;
                }
                zero = false;
                uns += 1;
            } else {
                zero = true;
            }
        }
        contador + if zero { uns } else { 0 }
    }
}
