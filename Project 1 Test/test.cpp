#include "pch.h"
#include "../Project 1/Clock.h"
#include "../Project 1/Clock.cpp"
#include "../Project 1/Validator.h"
#include "../Project 1/Validator.cpp"

TEST(TestBasicClock, TestBasicClock) {

	Clock clock(0, 0, 0);
	EXPECT_EQ(clock.get12HourFormat(), "12:00:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "00:00:00");

	clock.addHour();
	EXPECT_EQ(clock.get12HourFormat(), "1:00:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "01:00:00");

	clock.addMinute();
	EXPECT_EQ(clock.get12HourFormat(), "1:01:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "01:01:00");

	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "1:01:01 AM");
	EXPECT_EQ(clock.get24HourFormat(), "01:01:01");
}


TEST(TestAdvancedClock, TestAdvancedClock) {
	Clock clock(1, 58, 59);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "1:59:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "01:59:00");

	clock = Clock(1, 59, 59);
	clock.addMinute();
	EXPECT_EQ(clock.get12HourFormat(), "2:00:59 AM");
	EXPECT_EQ(clock.get24HourFormat(), "02:00:59");

	clock = Clock(1, 59, 59);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "2:00:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "02:00:00");

	clock = Clock(12, 0, 0);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "12:00:01 PM");
	EXPECT_EQ(clock.get24HourFormat(), "12:00:01");

	clock.addMinute();
	EXPECT_EQ(clock.get12HourFormat(), "12:01:01 PM");
	EXPECT_EQ(clock.get24HourFormat(), "12:01:01");

	clock.addHour();
	EXPECT_EQ(clock.get12HourFormat(), "1:01:01 PM");
	EXPECT_EQ(clock.get24HourFormat(), "13:01:01");

	clock = Clock(11, 59, 59);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "12:00:00 PM");
	EXPECT_EQ(clock.get24HourFormat(), "12:00:00");

	clock = Clock(23, 59, 59);
	clock.addSecond();
	EXPECT_EQ(clock.get12HourFormat(), "12:00:00 AM");
	EXPECT_EQ(clock.get24HourFormat(), "00:00:00");
}

TEST(TestInvalidClock, TestInvalidClock) {
	bool exceptionThrown = false;

	try {
		Clock clock(24, 0, 0);
	}
	catch (std::invalid_argument ex) {
		exceptionThrown = true;
	}

	EXPECT_TRUE(exceptionThrown);

	exceptionThrown = false;
	try {
		Clock clock(0, 60, 0);
	}
	catch (std::invalid_argument ex) {
		exceptionThrown = true;
	}

	EXPECT_TRUE(exceptionThrown);

	exceptionThrown = false;
	try {
		Clock clock(0, 0, 60);
	}
	catch (std::invalid_argument ex) {
		exceptionThrown = true;
	}

	EXPECT_TRUE(exceptionThrown);
}

TEST(TestValidator, TestValidator) {
	const int min = 1;
	const int max = 5;

	Validator validator(min, max);


	EXPECT_FALSE(validator.isValid(min - 1));
	EXPECT_FALSE(validator.isValid(max + 1));
	EXPECT_TRUE(validator.isValid(min));
	EXPECT_TRUE(validator.isValid(max));
	EXPECT_TRUE(validator.isValid(min + 1));
	EXPECT_TRUE(validator.isValid(max - 1));

	EXPECT_EQ(validator.getMinValue(), min);
	EXPECT_EQ(validator.getMaxValue(), max);

}

TEST(TestInvalidValidator, TestInvalidValidator) {
	bool exceptionThrown = false;

	try {
		Validator validator(5, 3);
	}
	catch (std::invalid_argument ex) {
		exceptionThrown = true;
	}
	EXPECT_TRUE(exceptionThrown);

}