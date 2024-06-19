use std::collections::HashMap;
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut valores = HashMap::new ();
        valores.insert (b'I', 1);
        valores.insert (b'V', 5);
        valores.insert (b'X', 10);
        valores.insert (b'L', 50);
        valores.insert (b'C', 100);
        valores.insert (b'D', 500);
        valores.insert (b'M', 1000);
        let b = s.as_bytes ();
        let mut tmp = valores [&b [0]];
        let mut acumulado: i32 = 0;
        for v in &b [1..] {
            if tmp < valores [v] {
                if tmp == 0 {
                    tmp = valores [v];
                } else {
                    acumulado += valores [v] - tmp;
                    tmp = 0;
                }
            } else { // if tmp < valores
                acumulado += tmp;
                tmp = valores [v];
            }
        }
        acumulado += tmp;
        acumulado
    }
}

