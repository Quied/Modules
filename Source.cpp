#include <iostream>
#include <list>

#include "pch.h"


class Quied : public testing::Test {

public:

	std::list < std::pair<int, std::string>> this_fl;

	static void Set() {
		std::cout << "set" << std::endl;
	}

	virtual void SetFl() {

		this_fl.push_front(std::make_pair(42, "cpp"));
		this_fl.push_front(std::make_pair(84, "cpp"));
		this_fl.push_front(std::make_pair(168, "cpp"));

	}

	virtual void TearDown() { this_fl.clear(); }

};

TEST_F(Quied, Find) {

	std::list<std::pair<int, std::string>> ::iterator it = this_fl.begin();
	ASSERT_NE(it, this_fl.end());

}

TEST_F(Quied, Size) {

	ASSERT_EQ(this_fl.max_size(), 3);

}

int main(int argc, char* argv[]) {

	std::cout << "This" << std::endl;
	
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}