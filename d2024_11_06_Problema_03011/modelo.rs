impl Solution {
    fn contar (k: i32) -> u8 {
        let mut c: u8 = 0;
        for i in 0..(std::mem::size_of::<i32> () * 8) { // Total de bits
            if (k & (1 << i)) > 0 {
                c += 1;
            }
        }
        c
    }
    pub fn can_sort_array(nums: Vec<i32>) -> bool {
        let mut tmp: Vec<i32> = Vec::new ();
        let mut grupos: Vec<(i32, i32)> = Vec::new (); // O menor e o maior; não precisamos dos demais
        for i in nums { // Não usaremos mais nums, depois daqui
            match tmp.last () {
                None => tmp.push (i), // Nem precisamos testar len
                Some (&v) =>
                    if Self::contar (v) == Self::contar (i) {
                        tmp.push (i);
                    } else {
                        tmp.sort ();
                        match tmp.last () {
                            None => (), // Há; sempre haverá
                            Some (&q) => grupos.push ((tmp [0], q)),
                        }
                        tmp.clear ();
                        tmp.push (i);
                    }
            } // match tmp.last
        }
        if tmp.len () > 0 { // Adiciona o que sobrou
            tmp.sort ();
            match tmp.last () {
                None => (), // Idem, acima
                Some (&q) => grupos.push ((tmp [0], q)),
            }
        }
        for g in 1..grupos.len () {
            if grupos [g - 1].1 > grupos [g].0 {
                return false;
            }
        }
        true // Passou
    }
}

