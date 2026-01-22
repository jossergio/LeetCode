impl Solution {
    pub fn minimum_pair_removal(nums: Vec<i32>) -> i32 {
        let mut nums = nums;
        let mut resposta = 0; // i32
        loop {
            if nums.len () == 1 { break; } // Não há mais o que fazer
            // else
            let mut menor = nums [0] + nums [1]; // Base
            let mut menor_i: usize = 0;
            let mut tem = false;
            for i in 1..nums.len () {
                tem = tem || (nums [i] < nums [i - 1]);
                let tmp = nums [i] + nums [i - 1];
                if tmp < menor {
                    menor = tmp;
                    menor_i = i - 1; // Toma como base esse
                }
            }
            if !tem { break; }
            // else
            nums.remove (menor_i + 1);
            nums.remove (menor_i); // Atenção para a ordem, por conta do shift left
            nums.insert (menor_i, menor);
            resposta += 1;
        }
        resposta
    }
}
