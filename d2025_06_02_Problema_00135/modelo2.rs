impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        let t = ratings.len ();
        let mut doces = vec! [1; t];
        (1..t).for_each (|i|
            if ratings [i] > ratings [i - 1] { doces [i] = doces [i - 1] + 1 }
        );
        if t > 1 { // Como não temos uma condicional na forma para o laço interno, precisei inserir aqui
            (0..=(t - 2)).rev ().for_each (|i|
                if ratings [i] > ratings [i + 1] { doces [i] = i32::max (doces [i], doces [i + 1] + 1) }
            );
        }
        doces.into_iter ().sum ()
    }
}
