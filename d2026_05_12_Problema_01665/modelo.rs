impl Solution {
    pub fn minimum_effort(tasks: Vec<Vec<i32>>) -> i32 {
        let mut tasks = tasks; // Torna mutável
        tasks.sort_by (
            | a, b | (a [1] - a [0]).cmp (&(b [1] - b [0]))
        );
        let mut resposta = 0;
        for task in tasks {
            resposta = i32::max (resposta + task [0], task [1]);
        }
        resposta
    }
}
