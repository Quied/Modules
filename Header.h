#pragma once
#include "pch.h"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}

using uint = unsigned int;

namespace quied {

	struct Bank {
	
		uint _balance = 1000;

		explicit Bank(const uint _bl) : _balance(_bl) {}
		Bank() {}


		void Deposit(uint a) { _balance = a; }
		bool WithDraw(uint a) { 
			if (a <= _balance) { return true; } return false;
		}
	};

	struct SomeAccount : testing::Test {

		Bank* acc;

		SomeAccount() {
			acc = new Bank;
		}

		~SomeAccount() {
			delete acc;
		}

	};

	struct Account_State {

		uint current_balance;
		uint withdraw_balance;
		uint final_balance;
		bool success;
		

	};

	struct WithdrawAccountTest : SomeAccount, testing::WithParamInterface<Account_State> {
		WithdrawAccountTest(){
			acc->_balance = GetParam().current_balance;
		}

	};

	TEST_P(WithdrawAccountTest, Finale_balance) {
		auto t = GetParam();
		auto w = acc->WithDraw(t.withdraw_balance);
		EXPECT_EQ(t.final_balance, acc->_balance);
		EXPECT_EQ(t.success, w);
	}

	TEST_F(SomeAccount, BankInfo) {
		EXPECT_EQ(1000, acc->_balance);
	}

	TEST_F(SomeAccount, Deposit) {
		acc->Deposit(700);	
		EXPECT_EQ(700, acc->_balance);
	}


	INSTANTIATE_TEST_CASE_P(Default, WithdrawAccountTest,
		testing::Values(
			Account_State{ 700, 1000, 555, true },
			Account_State{ 100, 200, 300, false }));


}