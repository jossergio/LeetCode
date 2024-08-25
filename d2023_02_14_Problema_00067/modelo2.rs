impl Solution {
    fn adicionar (a: i32, b: i32, vai_um: i32) -> (i32, i32) {
        let mut total: i32 = a + b + vai_um;
        if total == 0 {
            return (0, 0);
        }
        else if total == 1 {
            return (1, 0);
        } else if total == 2 {
            return (0, 1);
        }
        // else
        return (1, 1); // A soma é um e vai um, por exceção
    }
    pub fn add_binary(a: String, b: String) -> String {
        let mut resposta: Vec<char> = Vec::new ();
        let mut a_t = a.len (); // ATENÇÃO!!! São usize;
        let mut b_t = b.len ();
        let a = a.as_bytes (); // ATENÇÃO!!! Sombreia as variáveis de entrada
        let b = b.as_bytes ();
        let mut vai_um: i32 = 0;
        while a_t > 0 || b_t > 0 {
            let mut a_valor: i32 = 0; // Haverá um teste para possível modificação adiante
            let mut b_valor: i32 = 0; // Idem
            if a_t > 0 {
                a_t -= 1;
                a_valor = if a [a_t] == b'1' { 1 } else { 0 };
            }
            if b_t > 0 {
                b_t -= 1;
                b_valor = if b [b_t] == b'1' { 1 } else { 0 };
            }
            (a_valor, vai_um) = Self::adicionar (a_valor, b_valor, vai_um); // Reaproveita variável
            resposta.push (if a_valor == 1 { '1' } else { '0' });
        }
        if vai_um == 1 {
            resposta.push ('1');
        }
        let mut total = String::new ();
        resposta.reverse ();
        for a in resposta {
            total.push (a);
        }
        total
    }
}

