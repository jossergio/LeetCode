struct Bank {
    t: usize,
    contas: Vec<i64>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Bank {

    fn new(balance: Vec<i64>) -> Self {
        Self { t: balance.len (), contas: balance.clone () }
    }
    
    fn transfer(&mut self, account1: i32, account2: i32, money: i64) -> bool {
        let (account1, account2) = (account1 as usize - 1, account2 as usize - 1); // Só para mudar o tipo e ajustar 0-begin
        if account1 < self.t && account2 < self.t && money <= self.contas [account1] {
            self.contas [account1] -= money;
            self.contas [account2] += money;
            return true;
        }
        // else
        false
    }
    
    fn deposit(&mut self, account: i32, money: i64) -> bool {
        let account = account as usize - 1; // Só para mudar o tipo e ajustar 0-begin
        if account < self.t {
            self.contas [account] += money;
            return true;
        }
        // else
        false
    }
    
    fn withdraw(&mut self, account: i32, money: i64) -> bool {
        let account = account as usize - 1; // Só para mudar o tipo e ajustar 0-begin
        if account < self.t && money <= self.contas [account] {
            self.contas [account] -= money;
            return true;
        }
        // else
        false
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * let obj = Bank::new(balance);
 * let ret_1: bool = obj.transfer(account1, account2, money);
 * let ret_2: bool = obj.deposit(account, money);
 * let ret_3: bool = obj.withdraw(account, money);
 */
 