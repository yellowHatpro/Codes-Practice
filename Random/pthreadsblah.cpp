#include <bits/stdc++.h>
using namespace std;

class Account {
public:
  int balance;
  mutable std::mutex mtx;

  Account(int initialBalance) : balance(initialBalance) {}

  Account(const Account &other) : balance(other.balance) {}

  int getBalance() const {
    std::lock_guard<std::mutex> lock(mtx);
    return balance;
  }

  bool withdraw(int amount) {
    std::lock_guard<std::mutex> lock(mtx);

    if (amount <= balance) {
      balance -= amount;
      cout << "balance of david's withdrawal: " << balance << endl;
      return true;
    }
    return false;
  }

  void deposit(int amount) {
    std::lock_guard<std::mutex> lock(mtx);
    balance += amount;
    cout << "balance of david's deposit: " << balance << endl;
  }

  std::mutex &getMutex() const { return mtx; }
};

class Bank {
private:
  std::vector<Account> accounts;
  mutable std::mutex mtx;

public:
  Bank(int numAccounts, int initialBalance)
      : accounts(numAccounts, Account(initialBalance)) {}

  void transfer(int from, int to, int amount) {
    std::lock_guard<std::mutex> lock1(accounts[from].getMutex());
    std::lock_guard<std::mutex> lock2(accounts[to].getMutex());

    if (accounts[from].withdraw(amount)) {
      accounts[to].deposit(amount);
    }
  }

  int getTotalBalance() const {
    std::lock_guard<std::mutex> lock(mtx);
    int totalBalance = 0;
    for (const Account &account : accounts) {
      totalBalance += account.balance;
    }
    return totalBalance;
  }
};

int main() {
  const int numAccounts = 10;
  const int initialBalance = 10000;

  Bank bank(numAccounts, initialBalance);
  std::vector<std::thread> threads;

  // Transfer threads
  for (int i = 0; i < numAccounts; ++i) {
    threads.emplace_back([&bank, i, numAccounts, initialBalance]() {
      for (int j = 0; j < 10000; ++j) {
        int toAccount = rand() % numAccounts;
        int amount = rand() % initialBalance;
        bank.transfer(i, toAccount, amount);
      }
    });
  }

  // Deposit and Withdraw threads
  for (int i = 0; i < numAccounts; ++i) {
    threads.emplace_back([&bank, i, initialBalance]() {
      for (int j = 0; j < 10000; ++j) {
        int depositAmount = rand() % initialBalance;
        int withdrawAmount = rand() % initialBalance;
        bank.transfer(i, i, depositAmount - withdrawAmount);
      }
    });
  }

  // Join all threads
  for (std::thread &thread : threads) {
    thread.join();
  }

  // Output total balance
  std::cout << "Total balance: " << bank.getTotalBalance() << std::endl;

  return 0;
}
