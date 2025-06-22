impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        let k = k as usize; // Só para alterar o tipo
        let mut tmp = Vec::from_iter (s.chars ());
        if s.len () % k != 0 { // Não vi forma por cálculo direto para preencher (ou tive preguiça de raciocinar)
            tmp.extend (vec![fill; k - (s.len () % k)]);
        }
        let mut resposta: Vec<String> = Vec::new ();
        let t = tmp.len () / k; // Aqui, não sobra resto, pois foi preenchido
        for i in 0..t {
            resposta.push (String::from_iter (&tmp [(i * k)..(i * k + k)]));
        }
        resposta
    }
}
