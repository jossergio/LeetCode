impl Solution {
    pub fn can_arrange(arr: Vec<i32>, k: i32) -> bool {
        let mut freq: Vec<i32> = vec![0; k as usize]; // A plataforma manda números negativos
        for v in &arr {
            let i = ((v % k) + k) % k;
            freq [i as usize] += 1;
        }
        println! ("{freq:?}");
        let k = k as usize; // Só para mudar o tipo
        for i in 1..(k / 2 + 1) {
            if freq [i] != freq [k - i] {
                return false;
            }
        }
        freq [0] % 2 == 0 // Os divisores estão em zero e formam pares
    }
}

