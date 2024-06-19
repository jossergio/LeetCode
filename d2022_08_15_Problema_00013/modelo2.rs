use std::collections::HashMap;
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut valores = HashMap::new ();
        valores.insert ('I' as u8, 1);
        valores.insert ('V' as u8, 5);
        valores.insert ('X' as u8, 10);
        valores.insert ('L' as u8, 50);
        valores.insert ('C' as u8, 100);
        valores.insert ('D' as u8, 500);
        valores.insert ('M' as u8, 1000);
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

