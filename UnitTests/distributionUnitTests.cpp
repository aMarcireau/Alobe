#include "stdafx.h"
#include "CppUnitTest.h"
#include "tokenDistribution.h"
#include "tokenDistribution.cpp"
#include "tabulatedDistribution.h"
#include "tabulatedDistribution.cpp"
#include "tableDistribution.h"
#include "tableDistribution.cpp"
#include "constantDistribution.h"
#include "exponentialDistribution.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

TEST_CLASS(DistributionUnitTests)
{
public:
	TEST_METHOD(TokenDistributionUnitTest) {
		TokenDistribution<unsigned long>(tokenDistribution);
		vector<unsigned long> elements = {0, 1, 2, 3, 4};
		vector<pair<unsigned long, unsigned long> > tokensByElement = {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}};
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
	}
	TEST_METHOD() {


	}
};
