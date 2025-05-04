impl Solution {
    pub fn push_dominoes(dominoes: String) -> String {
        let t = dominoes.len ();
        let dominoes = dominoes.as_bytes ();
        let letra = |i: i32| -> u8 {
            if i > 0 { return b'R'; }
            // else
            if i < 0 { return b'L'; }
            // else // == 0
            b'.'
        }; // letra
        let mut tensoes = vec![0 as i32; t];
        let mut f = 0 as i32; // i32
        // Mede os direitos
        for i in 0..t {
            match dominoes [i] {
                b'R' => f = t as i32,
                b'L' => f = 0,
                _ => f = i32::max (0, f - 1)
            }
            tensoes [i] = f;
        }
        f = 0; // Redefine
        // Mede os esquerdos
        for i in (0..t).rev () {
            match dominoes [i] {
                b'L' => f = t as i32,
                b'R' => f = 0,
                _ => f = i32::max (0, f - 1)
            }
            tensoes [i] -= f;
        }
        String::from_utf8 (tensoes.into_iter ().map (|n| letra (n)).collect::<Vec<u8>> ()).unwrap ()
    }
}
