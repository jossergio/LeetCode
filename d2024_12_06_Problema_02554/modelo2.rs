use std::collections::HashSet;
impl Solution {
    pub fn max_count(banned: Vec<i32>, n: i32, max_sum: i32) -> i32 {
        // Fiz por linhas, pois estava ficando difícil por em um alinha só
        let todos: HashSet<i32> = HashSet::from_iter ((1..=n));
        let banned = HashSet::from_iter (banned.iter ().map (|&v| v)); // Sombreia
        let mut possiveis: Vec<i32> = Vec::from_iter (todos.difference (&banned).map (|&v| v));
        possiveis.sort ();
        let mut soma: i32 = 0;
        let mut resposta: i32 = 0;
        for v in possiveis {
            soma += v;
            if soma > max_sum {
                break;
            }
            resposta += 1;
        }
        resposta
    }
}

