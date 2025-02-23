// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use core::cell::RefCell;
use std::rc::Rc;
use std::collections::HashSet;

struct FindElements {
    valores: HashSet<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl FindElements {
    fn montar (t: &mut HashSet<i32>, no: &Option<Rc<RefCell<TreeNode>>>, v: i32) {
        if let Some (n) = no {
            t.insert (v);
            Self::montar (t, &n.borrow ().left, 2 * v + 1);
            Self::montar (t, &n.borrow ().right, 2 * v + 2);
        }
    }

    fn new(root: Option<Rc<RefCell<TreeNode>>>) -> Self {
        let mut tmp = HashSet::<i32>::new ();
        Self::montar (&mut tmp, &root, 0);
        Self { valores: tmp }
    }
    
    fn find(&self, target: i32) -> bool {
        self.valores.contains (&target)
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * let obj = FindElements::new(root);
 * let ret_1: bool = obj.find(target);
 */
 