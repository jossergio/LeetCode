impl Solution {
    pub fn get_sneaky_numbers(nums: Vec<i32>) -> Vec<i32> {
        let mut cont = std::collections::HashMap::<i32, i32>::new ();
        for n in nums {
            cont.entry (n).and_modify (| v | *v += 1).or_insert (1);
        }
        cont.into_iter ().filter_map (| (i, q ) | if q == 2 { Some (i)} else { None }).collect::<Vec<i32>> ()
    }
}
