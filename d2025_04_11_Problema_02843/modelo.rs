impl Solution {
    fn eh_simetrico (i: i32) -> bool {
        let mut cont = 0 as u32;
        let mut a = i as u32;
        while a > 0 {
            cont += 1;
            a /= 10;
        }
        if cont % 2 == 1 {
            return false
        }
        // else
        a = i as u32; // De novo
        let mut r1 = 0 as u32;
        for j in 1..=(cont / 2) {
            r1 += a % 10;
            a /= 10;
        }
        let mut r2 = 0 as u32;
        for j in (cont / 2 + 1)..=cont {
            r2 += a % 10;
            a /= 10;
        }
        r1 == r2
    }
    pub fn count_symmetric_integers(low: i32, high: i32) -> i32 {
        let mut cont = 0; // i32
        for i in low..=high {
            if Self::eh_simetrico (i) { cont += 1; }
        }
        cont
    }
}
