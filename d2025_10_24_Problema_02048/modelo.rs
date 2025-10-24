use std::collections::HashMap;
impl Solution {
    fn eh_balanceado (n: i32) -> bool {
        let mut contar: HashMap<i32, i32> = HashMap::new ();
        let mut n = n;
        while n > 0 {
            let tmp = n % 10;
            contar.entry (tmp).and_modify (| v | *v += 1).or_insert (1);
            n /= 10;
        }
        for (i, v) in contar {
            if i != v {
                return false;
            }
        }
        true
    }
    pub fn next_beautiful_number(n: i32) -> i32 {
        for i in (n + 1).. {
            if Self::eh_balanceado (i) {
                return i;
            }
        }
        0
    }
}
