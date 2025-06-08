impl Solution {
    fn buscar (i: &mut usize, n: i32, m: i32, v: &mut Vec<i32>) {
        let limite = m + 10; // Para não passar dos limites, kkkk; deste nível
        let mut m = m; // Torna mutável, aqui
        while *i < v.len () && m <= n && m < limite {
            v [*i] = m;
            *i += 1;
            Self::buscar (i, n, m * 10, v);
            m += 1;
        }
    }
    pub fn lexical_order(n: i32) -> Vec<i32> {
        let mut resposta = vec![0; n as usize];
        let mut i: usize = 0;
        for a in 1..9 {
            Self::buscar (&mut i, n, 1, &mut resposta)
        }
        resposta
    }
}
