impl Solution {
    pub fn separate_digits(nums: Vec<i32>) -> Vec<i32> {
        nums
            .into_iter ()
            .fold (vec![], | mut acum, mut atual | {
                let mut tmp: Vec<i32> = Vec::new ();
                while atual > 0 {
                    tmp.push (atual % 10);
                    atual /= 10;
                }
                tmp.reverse ();
                acum.extend (tmp);
                acum
            })
    }
}
