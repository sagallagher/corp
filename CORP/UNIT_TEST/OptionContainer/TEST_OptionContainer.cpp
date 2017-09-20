
#include"CppUnitTest.h"
#include"../../CORP/OptionContainer/OptionContainer.h"
#include<iostream>

std::string generateKey(int keyNumber, std::string& tag) { return ("key" + tag).c_str() + keyNumber;  }


bool PushPullTest() {
	OptionContainer container;

	std::string int_tag = "int";
	std::string bool_tag = "bool";
	std::string string_tag = "string";

	// fill container with keys associated with int values
	// all keys will have value of 1
	for (int i = 0; i < 10; i++) {
		container.push(generateKey(i, int_tag), "1");
	}
	
	// pull keys associated with int values
	for (int i = 1; i < 10; i++) {
		// make sure all values are 1
		if (container.pull(generateKey(i,int_tag), 0) != 1) {
			std::cerr << "Error pulling int valuet\tExpected\t1\tActual:\t" << container.pull(generateKey(i, int_tag), 0) << std::endl;
			return false;
		}
	}

	// fill container with keys associated with bool values
	// all keys have value of true
	for (int i = 0; i < 10; i++) {
		container.push(generateKey(i,bool_tag), "true");
	}

	// pull keys associated with bool values
	for (int i = 0; i < 10; i++) {
		// make sure all values are true
		if (!container.pull(generateKey(i,bool_tag), false)) {
			std::cerr << "Error pulling int valuet\tExpected\ttrue\tActual:\t" << container.pull(generateKey(i, bool_tag), false) << std::endl;
			return false;
		}
	}

	for (int i = 0; i < 10; i++) {
		container.push(generateKey(i,string_tag), "string");
	}

	// pull keys associated with int values
	// BUG: calling pull(string, bool); should be calling pull(string,string)
	/*for (int i = 0; i < 10; i++) {
		// make sure all values are 0
		std::string no = "nsso";
		if (container.pull(generateKey(i, string_tag), "not_string") == false) {
			return false;
		}
	}
	*/
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