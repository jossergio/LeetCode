impl Solution {
    pub fn chalk_replacer(chalk: Vec<i32>, k: i32) -> i32 {
        let mut soma: i64 = 0;
        for v in &chalk {
            soma += *v as i64;
        }
        println! ("Soma: {soma}");
        let mut k = k; // Torna mutável
        while (k as i64 >= soma) { // Se passou da capacidade de i32, nunca será
            k -= soma as i32;
        }
        println! ("k: {k}");
        let mut i: usize = 0;
        while k >= chalk [i] { // Nunca vai ao final; não chega
            k -= chalk [i];
            i += 1;
        }
        i as i32
    }
}

