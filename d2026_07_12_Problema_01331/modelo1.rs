impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        use std::collections::HashSet;
        use std::collections::HashMap;
        let mut unicos: Vec<i32> = Vec::from_iter (HashSet::<i32>::from_iter (arr.clone ().into_iter ()));
        unicos.sort ();
        let mut rank: HashMap<i32, i32> = HashMap::new ();
        for (i, v) in unicos.into_iter ().enumerate () {
            rank.insert (v, i as i32 + 1);
        }
        let mut arr = arr;
        let t = arr.len ();
        for i in 0..t {
            arr [i] = rank [&arr [i]];
        }
        arr
    }
}
