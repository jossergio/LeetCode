impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut resposta = digits;
        let mut vai_um = 1; // Já faz a adição de um
        resposta.reverse (); // Fica mais fácil nessa ordem
        for v in resposta.iter_mut () {
            *v += 1;
            vai_um = *v / 10;
            *v %= 10;
            if vai_um == 0 {
                break; // Não precisa ir adiante
            }
        }
        if vai_um == 1 {
            resposta.push (1); // Adiciona o dígito
        }
        resposta.reverse (); // Traz à ordem base
        resposta
    }
}
