# Makefile for the banking system project

banking_system: main.cpp Bank.cpp Users.cpp Accounts.cpp TransactionAccount.cpp CreditAccount.cpp SavingsAccount.cpp
	@ g++ main.cpp Bank.cpp Users.cpp Accounts.cpp TransactionAccount.cpp CreditAccount.cpp SavingsAccount.cpp -o banking_system

clean:
	@ rm -f banking_system
