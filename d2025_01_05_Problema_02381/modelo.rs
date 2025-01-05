impl Solution {
    pub fn shifting_letters(s: String, shifts: Vec<Vec<i32>>) -> String {
        let t = s.len ();
        let mut tmp: Vec<i32> = vec![0; t];
        for a in shifts {
            tmp [a [0] as usize] += if a [2] == 0 { -1 } else { 1 };
            if (a [1] as usize) < t - 1 { // Só vai até o penúltimo
                tmp [(a [1] + 1) as usize] += if a [2] == 0 { 1 } else { - 1 }; // Restaura
            } // Não precisa do else
        }
        for i in 1..tmp.len () {
            tmp [i] += tmp [i - 1];
        }
        let letras = s.as_bytes ();
        let mut letras:Vec<i32> = letras.iter ().map (| &a | { a as i32 }).collect ();
        for (i, v) in tmp.iter ().enumerate () {
            letras [i] += *v;
            while letras [i] < b'a' as i32 {
                letras [i] = (b'z' as i32) - ((b'a' as i32) - letras [i]) + 1; // Repõe uma diferença de módulo
            }
            while letras [i] > b'z' as i32 {
                letras [i] = (b'a' as i32) + (letras [i] - (b'z' as i32)) -1; // Idem
            }
        }
        let letras: Vec<u8> = letras.iter ().map (| &a | { a as u8 }).collect ();
        String::from_utf8 (letras).unwrap ()
    }
}
