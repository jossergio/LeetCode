impl Solution {
    fn somar_um (b: &mut Vec<u8>) {
        let t = b.len ();
        let mut vai_um = 1; // É, justamente, o que será adicionado
        for i in (0..t).rev () {
            if b [i] == 1 && vai_um == 1 {
                b [i] = 0; // vai_um permanece
            } else {
                if b [i] == 1 || vai_um == 1 {
                    b [i] = 1; // Talvez seja redundante
                    vai_um = 0; // Idem
                    break; // Não precisa seguir daqui
                }
            }
        }
        if vai_um == 1 {
            b.insert (0, 1);
        }
    }
    fn dividir_por_dois (b: &mut Vec<u8>) {
        b.pop ();
    }
    pub fn num_steps(s: String) -> i32 {
        let mut s = Vec::from_iter (s.bytes ().map (| c | c - b'0'));
        let mut resposta = 0;
        // Obs.: pela definição do problema, s [0] sempre é 1
        while s.len () > 1 {
            if s.last () == Some (&1) {
                Self::somar_um (&mut s);
            } else {
                Self::dividir_por_dois (&mut s);
            }
            resposta += 1;
        }
        resposta
    }
}
