impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let valor = | c | if c == b'0' { 0 } else { 1 };
        let converter = | s: String | s.bytes ().map (| c | valor (c)).collect::<Vec<_>> ();
        let mut a = converter (a); // Sombreia
        let mut b = converter (b); // Idem
        a.reverse ();
        b.reverse ();
        {
            // Ajusta para o tamanho do maior
            let dif = a.len () as i32 - b.len () as i32;
            match dif.signum () {
                -1 => a.extend_from_slice (&vec![0; dif.abs () as usize]),
                1 => b.extend_from_slice (&vec![0; dif as usize]),
                _ => () // Só pode ser zero
            }
        }
        let mut resposta: Vec<char> = Vec::with_capacity (a.len () + 1); // Tanto faz; aqui, são do mesmo tamanho; já prevê vai um no último passo
        let mut vai_um: i32 = 0;
        let mut soma: i32 = 0; // Para não ficar definindo dentro do laço; também organizar o retorno de somar
        for (v1, v2) in a.into_iter ().zip (b.into_iter ()) {
            (soma, vai_um) = match v1 + v2 + vai_um {
                0 => (0, 0),
                1 => (1, 0),
                2 => (0, 1),
                _ => (1, 1) // Só pode ser 3
            };
            resposta.push (if soma == 0 { '0' } else { '1' });
        }
        if vai_um > 0 {
            resposta.push ('1');
        }
        String::from_iter (
            resposta
                .into_iter ()
                .rev ()
        )
    }
}
