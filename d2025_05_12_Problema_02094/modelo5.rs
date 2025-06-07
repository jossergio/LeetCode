impl Solution {
    pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
        let mut cont = vec![0; 10];
        for v in digits {
            cont [v as usize] += 1;
        }
        let mut resposta = Vec::<i32>::new ();
        for n in (100..=999).step_by (2) {
            let (tmp, a1) = (n / 10, n % 10);
            let (tmp, a2) = (tmp / 10, tmp % 10);
            let a3 = tmp % 10;
            cont [a1] -= 1;
            cont [a2] -= 1;
            cont [a3] -= 1;
            if cont [a1] >= 0 && cont [a2] >= 0 && cont [a3] >= 0 {
                resposta.push (n as i32);
            }
            cont [a1] += 1;
            cont [a2] += 1;
            cont [a3] += 1;
        }
        resposta
    }
}
