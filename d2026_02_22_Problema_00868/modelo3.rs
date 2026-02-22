impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        (0..32).filter (| i | n & (1 << i) != 0)
            .fold ((0, Option::<i32>::None), | (mut maximo, anterior), atual | { // Irei utilizar <maximo> para receber o cálculo
                // Poderia ter feito essa função com uma sentença, gerando a resposta diretamente. Mas teria que utilizar else.
                if let Some (valor_anterior) = anterior {
                    maximo = maximo.max (atual - valor_anterior);
                }
                (maximo, Some (atual))
            }).0
    }
}
