impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let t = nums.len ();
        let mut acumulados = vec! [0; t]; // i32
        let mut acumulado = 0; // i32
        let mut ultimos = std::collections::HashMap::<i32, usize>::new ();
        let mut ultimo: usize = 0;
        let mut resposta = 0;
        for (i, v) in nums.into_iter ().enumerate () {
            if i == 0 {
                acumulados [0] = v;
                acumulado = v;
                ultimo = 0;
            } else {
                acumulados [i] = acumulados [i - 1] + v;
                if ultimos.get (&v) == None || ultimo > ultimos [&v] {
                    acumulado += v;
                } else {
                    acumulado = acumulados [i] - acumulados [ultimos [&v]];
                    ultimo = ultimos [&v] + 1;
                }
            }
            ultimos.insert (v, i);
            resposta = resposta.max (acumulado);
        }
        resposta
    }
}
