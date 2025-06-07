use std::collections::HashMap;
impl Solution {
    pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
        let mut cont = digits.into_iter ().fold (HashMap::<i32, i32>::new (), |mut h, a| { h.entry (a).and_modify (|v| *v += 1).or_insert (1); h });
        for i in (0..=9) {
            if cont.get (&i) == None {
                cont.insert (i, -1); // Mantém todos
            }
        }
        let mut resposta = Vec::<i32>::new ();
        for n in (100..=999).step_by (2) {
            let (tmp, a1) = (n / 10, n % 10);
            let (tmp, a2) = (tmp / 10, tmp % 10);
            let a3 = tmp % 10;
            cont.entry (a1).and_modify (|v| *v -= 1);
            cont.entry (a2).and_modify (|v| *v -= 1);
            cont.entry (a3).and_modify (|v| *v -= 1);
            if cont [&a1] >= 0 && cont [&a2] >= 0 && cont [&a3] >= 0 {
                resposta.push (n);
            }
            cont.entry (a1).and_modify (|v| *v += 1);
            cont.entry (a2).and_modify (|v| *v += 1);
            cont.entry (a3).and_modify (|v| *v += 1);
        }
        resposta
    }
}
