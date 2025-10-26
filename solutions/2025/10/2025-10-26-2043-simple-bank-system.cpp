class Bank {
    private:
    vector<long long> accountBalances;
    int totalAccounts;

    public:
    /**
    * Constructor: Initialize bank with given account balances
    * @param balance: Initial balance for each account (1-indexed in usage)
    */
    Bank(vector<long long>& balance) {
        accountBalances = balance;
        totalAccounts = balance.size();
    }

    /**
    * Transfer money from one account to another
    * @param account1: Source account number (1-indexed)
    * @param account2: Destination account number (1-indexed)
    * @param money: Amount to transfer
    * @return: true if transfer successful, false otherwise
    */
    bool transfer(int account1, int account2, long long money) {

        if (account1 totalAccounts ||
        account2 totalAccounts ||
        accountBalances[account1 - 1] < money) {
            return false;
        }

        accountBalances[account1 - 1] -= money;
        accountBalances[account2 - 1] += money;
        return true;
    }

    /**
    * Deposit money into an account
    * @param account: Account number (1-indexed)
    * @param money: Amount to deposit
    * @return: true if deposit successful, false otherwise
    */
    bool deposit(int account, long long money) {

        if (account totalAccounts) {
            return false;
        }

        accountBalances[account - 1] += money;
        return true;
    }

    /**
    * Withdraw money from an account
    * @param account: Account number (1-indexed)
    * @param money: Amount to withdraw
    * @return: true if withdrawal successful, false otherwise
    */
    bool withdraw(int account, long long money) {

        if (account totalAccounts ||
        accountBalances[account - 1] < money) {
            return false;
        }

        accountBalances[account - 1] -= money;
        return true;
    }
};
/**
* Your Bank object will be instantiated and called as such:
* Bank* obj = new Bank(balance);
* bool param_1 = obj->transfer(account1, account2, money);
* bool param_2 = obj->deposit(account, money);
* bool param_3 = obj->withdraw(account, money);
*/