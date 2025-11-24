impl Solution {
    pub fn max_sum_div_three(nums: Vec<i32>) -> i32 {
        let soma: i32 = nums.iter ().sum ();
        if soma % 3 == 0 {
            return soma; // Sumariamente
        }
        // else
        let mut a_1: Vec<i32> = nums.iter ().filter_map (| &v | if v % 3 == 1 { Some (v) } else { None }).collect ();
        let mut a_2: Vec<i32> = nums.iter ().filter_map (| &v | if v % 3 == 2 { Some (v) } else { None }).collect ();
        a_1.sort ();
        a_2.sort ();
        let mut max_3 = (soma / 3) * 3;
        let dif = soma - max_3;
        if dif == 2 {
            if a_1.len () >= 2 && a_2.len () >= 1 {
                return (soma - a_2 [0]).max (
                    soma - a_1 [0] - a_1 [1]
                );
            }
            // else
            if a_2.len () >= 1 { // a_1.len == 0
                return soma - a_2 [0]
            }
            // else
            if a_1.len () >= 2 {
                return soma - a_1 [0] - a_1 [1];
            }
            return 0; // Não há possibilidades
        }
        // else
        // Só pode ser 1
        if a_1.len () >= 1 && a_2.len () >= 2 {
            (soma - a_1 [0]).max (soma - a_2 [0] - a_2 [1])
        } else if a_1.len () >= 1 { // a_2 < 2
            soma - a_1 [0]
        } else if a_2.len () >= 2 { // a_1 < 1
            soma - a_2 [0] - a_2 [1]
        } else {
            0 // Impossível
        }
    }
}
