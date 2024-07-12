impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut vai_um: i32 = 1; // Já faz a soma
        let mut resposta: Vec<i32> = Vec::new ();
        for v in digits.iter ().rev () {
            resposta.push ((v + vai_um) % 10);
            vai_um = (v + vai_um) / 10;
        }
        if vai_um > 0 {
            resposta.push (vai_um);
        }
        resposta.reverse ();
        return resposta
    }
}

