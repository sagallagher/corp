#include"CppUnitTest.h"
#include"../../CORP/OptionContainer/OptionContainer.h"
#include<iostream>

// generate a random config file
void generateTestConfigFile() {

}


// pull keys and ensure the proper value is returned
bool testParse() {

	return true;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CORP
{		
	TEST_CLASS(Config)
	{
	public:

		TEST_METHOD(parse)
		{
			Assert::AreEqual(true,::testParse());
		}

	};
}