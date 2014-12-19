#include "stdafx.h"
#include "CppUnitTest.h"

#include <memory>

#include "stepper.h"
#include "stepper.cpp"
#include "actor.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(StepperUnitTests)
{
public:
	TEST_METHOD(StepperUnitTest) {
		Stepper(stepper);

		Assert::AreEqual(
			(unsigned long)(0),
			stepper.getStep(),
			L"Wrong step after initialization",
			LINE_INFO()
		);
		stepper.increment();
		Assert::AreEqual(
			(unsigned long)(1),
			stepper.getStep(),
			L"Wrong step after increment",
			LINE_INFO()
		);
		stepper.reset();
		Assert::AreEqual(
			(unsigned long)(0),
			stepper.getStep(),
			L"Wrong step after reset",
			LINE_INFO()
		);
	}
};
