
#include "CppUnitTest.h"
#include "../../CORP/OptionContainer/OptionContainer.h"

std::string generateKey(int keyNumber) { return "key" + keyNumber; }


bool PushPullTest() {
	OptionContainer Intcontainer;

	// fill container with keys associated with int values
	// all keys will have value of 0
	for (int i = 0; i < 100; i++) {
		Intcontainer.push(generateKey(i), "1");
	}
	
	// pull keys associated with int values
	for (int i = 0; i < 100; i++) {
		// make sure all values are false
		if (1 != Intcontainer.pull(generateKey(i), 0)) {
			return false;
		}
	}



	OptionContainer boolContainer;

	// fill container with keys associated with bool values
	// all keys have value of true
	for (int i = 0; i < 100; i++) {
		boolContainer.push(generateKey(i), "true");
	}

	// pull keys associated with int values
	for (int i = 0; i < 100; i++) {
		// make sure all values are 0
		if (!boolContainer.pull(generateKey(i), false)) {
			return false;
		}
	}


	OptionContainer stringContainer;

	for (int i = 0; i < 100; i++) {
		stringContainer.push(generateKey(i), "yes");
	}

	/*// pull keys associated with int values
	for (int i = 0; i < 100; i++) {
		// make sure all values are 0
		std::string no = "no";
		if (stringContainer.pull(generateKey(i), "123123") != no) {
			return false;
		}
	}*/

	return true;

}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CORP
{		
	TEST_CLASS(OptionContainer)
	{
	public:

		TEST_METHOD(pull)
		{
			Assert::AreEqual(true,::PushPullTest());
		}


	};
}