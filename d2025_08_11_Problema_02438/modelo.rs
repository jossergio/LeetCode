impl Solution {
    pub fn product_queries(n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        const m: i64 = 1000000007;
        let mut i: i64 = 1; // Elemento da multiplicação e primeiro valor a ser inserido; pode chegar a valor maior
        let mut valores: Vec<i32> = Vec::new ();
        while i <= n as i64 {
            valores.push (i as i32);
            i *= 2;
        }
        let mut trabalho: Vec<i32> = Vec::new ();
        let mut n = n; // Torna mutável
        while n > 0 {
            let tmp = *valores.last ().unwrap_or (&0); // n nunca é zero, aqui
            if n >= tmp {
                n -= tmp;
                trabalho.push (tmp);
            }
            valores.pop ();
        }
        trabalho.reverse (); // Pois acaba ficando invertido
        let mut resposta: Vec<i32> = Vec::with_capacity (trabalho.len ());
        for q in queries {
            let mut acumulado: i64 = 1; // Elemento neutro
            for i in (q [0] as usize)..=(q [1] as usize) {
                acumulado = (acumulado * (trabalho [i] as i64)) % m;
            }
            resposta.push (acumulado as i32);
        }
        resposta
    }
}
