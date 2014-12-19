#include "stdafx.h"
#include "CppUnitTest.h"

#include <string>

#include "state.h"
#include "state.cpp"
#include "behavior.cpp"
#include "gender.cpp"
#include "female.h"
#include "female.cpp"
#include "male.h"
#include "male.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(BeingDependenciesUnitTests)
{
public:
	TEST_METHOD(StateUnitTest) {
		State state(2);
		state.decrement();
		Assert::AreEqual(
			(unsigned long)(2),
			state.getValue(),
			L"Wrong value after first decrement, but before applyChanges",
			LINE_INFO()
			);
		state.applyChanges();
		Assert::AreEqual(
			(unsigned long)(1),
			state.getValue(),
			L"Wrong value after first decrement",
			LINE_INFO()
		);
		state.decrement();
		state.applyChanges();
		Assert::AreEqual(
			(unsigned long)(0),
			state.getValue(),
			L"Wrong value after second decrement",
			LINE_INFO()
		);
		state.decrement();
		state.applyChanges();
		Assert::AreEqual(
			(unsigned long)(0),
			state.getValue(),
			L"Wrong value after third decrement",
			LINE_INFO()
		);
	}

	TEST_METHOD(GenderUnitTest) {
		Female(female);
		Male(male);

		Assert::AreEqual(
			(string)("female"),
			female.get(),
			L"Wrong value for female gender",
			LINE_INFO()
			);
		Assert::AreEqual(
			(string)("male"),
			male.get(),
			L"Wrong value for male gender",
			LINE_INFO()
		);
	}
};
