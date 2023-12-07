#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr_10.3/10.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string filename = "1.txt";
			int g = IfFileOpen(filename);

			Assert::AreEqual(g, 0);
		}
	};
}
