impl Solution {
    pub fn has_alternating_bits(n: i32) -> bool {
        let mut anterior: Option<i32> = None;
        let mut n = n;
        while n > 0 {
            if anterior == None {
                anterior = Some (n & 1);
            } else {
                let tmp = n & 1;
                if Some (tmp) == anterior {
                    return false;
                }
                // else
                anterior= Some (tmp);
            }
            n >>= 1;
        }
        true // Passou nos testes e não teve reprovação
    }
}
