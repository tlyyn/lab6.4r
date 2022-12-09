#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6.4r/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int A[] = { 4, 0, -4, 2 };
			int t = CountElementArray(A, 4, -10, 0, 0);
			Assert::AreEqual(2, t);
		}
	};
}
