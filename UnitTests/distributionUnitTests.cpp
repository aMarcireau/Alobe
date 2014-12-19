#include "stdafx.h"
#include "CppUnitTest.h"

#include "tokenDistribution.h"
#include "tokenDistribution.cpp"
#include "tabulatedDistribution.cpp"
#include "tableDistribution.h"
#include "tableDistribution.cpp"
#include "generatedDistribution.cpp"
#include "constantDistribution.h"
#include "constantDistribution.cpp"
#include "exponentialDistribution.h"
#include "exponentialDistribution.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(DistributionUnitTests)
{
public:
	TEST_METHOD(TokenDistributionUnitTest) {
		TokenDistribution<unsigned long>(tokenDistribution);
		vector<unsigned long> elements = {0, 1};
		vector<pair<unsigned long, unsigned long> > tokensByElement = {{0, 1}, {1, 1}};
		Assert::IsFalse(
			find(elements.begin(), elements.end(), tokenDistribution.getDecision(tokensByElement)) == elements.end(), 
			L"Chosen element is not in the given list", 
			LINE_INFO()
		);
	}
	TEST_METHOD(TableDistributionUnitTest) {
		map<unsigned long, float> distribution = {{0, 0}, {2, 1.0}};
		TableDistribution tableDistribution(distribution);
		Assert::AreEqual(
			(float)(0.5),
			tableDistribution.getProbability(1),
			L"Extrapolation is not giving the expected value",
			LINE_INFO()
		);
		Assert::IsFalse(
			tableDistribution.getDecision(0),
			L"0 not always false",
			LINE_INFO()
		);
		Assert::IsTrue(
			tableDistribution.getDecision(2),
			L"1 not always true",
			LINE_INFO()
		);
	}
	TEST_METHOD(ConstantDistributionUnitTest) {
		ConstantDistribution constantDistribution(0.5);
		Assert::AreEqual(
			(float)(0.5),
			constantDistribution.getProbability(),
			L"Constant distribution is not storing the right value",
			LINE_INFO()
		);
	}
	TEST_METHOD(ExponentialDistributionUnitTest) {
		ExponentialDistribution exponentialDistribution(0, 2);
		Assert::AreEqual(
			(float)(0.25),
			exponentialDistribution.getProbability(1),
			L"Constant distribution is not storing the right value",
			LINE_INFO()
		);
	}
};
