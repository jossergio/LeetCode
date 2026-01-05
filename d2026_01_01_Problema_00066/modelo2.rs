impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut resposta: Vec<i32> = Vec::with_capacity (digits.len () + 1); // Terá, no máximo, isso
        let mut vai_um = 1; // Já faz a adição por um
        for v in digits.into_iter ().rev () {
            resposta.push ((v + vai_um) % 10);
            vai_um = (v + vai_um) / 10;
        }
        if vai_um == 1 {
            resposta.push (1); // Adiciona esse dígito
        }
        resposta.reverse ();
        resposta
    }
}
