#include "gmock/gmock.h"
#include "baseball.cpp"
#include "baseball_test.h"

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	void assertIllegalArgument(string guessNumber) {
		//game.guess() 수행 후, Exception이 발생해야 PASS 이다.
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};


TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strickes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, 2s0b_1) {
	GuessResult result = game.guess("124");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(2, result.strickes);
	EXPECT_EQ(0, result.balls);
}


TEST_F(BaseballFixture, 2s0b_2) {
	GuessResult result = game.guess("423");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(2, result.strickes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, 1s2b_1) {
	GuessResult result = game.guess("132");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(1, result.strickes);
	EXPECT_EQ(2, result.balls);
}

TEST_F(BaseballFixture, 1s2b_2) {
	GuessResult result = game.guess("213");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(1, result.strickes);
	EXPECT_EQ(2, result.balls);
}
TEST_F(BaseballFixture, 1s2b_3) {
	GuessResult result = game.guess("321");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(1, result.strickes);
	EXPECT_EQ(2, result.balls);
}
int main() {
	testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}