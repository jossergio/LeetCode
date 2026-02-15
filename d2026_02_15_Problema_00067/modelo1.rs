impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let valor = | c | c as i32 - b'0' as i32;
        let mut a: Vec<i32> = a.bytes ().map (| c | valor (c)).collect (); // Sombreia
        let mut b: Vec<i32> = b.bytes ().map (| c | valor (c)).collect (); // Idem
        a.reverse ();
        b.reverse ();
        let dif = a.len () as i32 - b.len () as i32;
        match dif.signum () {
            -1 => a.extend_from_slice (&vec![0; dif.abs () as usize]),
            1 => b.extend_from_slice (&vec![0; dif as usize]),
            _ => () // Só pode ser zero
        }
        let mut resposta: Vec<i32> = Vec::new ();
        let mut vai_um: i32 = 0;
        for (v1, v2) in a.into_iter ().zip (b.into_iter ()) {
            let soma; // Infere i32
            (soma, vai_um) = match v1 + v2 + vai_um {
                0 => (0, 0),
                1 => (1, 0),
                2 => (0, 1),
                _ => (1, 1) // Só pode ser 3
            };
            resposta.push (soma);
        }
        if vai_um > 0 {
            resposta.push (1);
        }
        String::from_utf8 (
            resposta
                .into_iter ()
                .rev ()
                .map (| v | (v + b'0' as i32) as u8)
                .collect::<Vec<_>> ()
        ).unwrap ()
    }
}
