#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../Lab3/BellFord.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BellFordTest
{
	TEST_CLASS(BellFordTest)
	{
	public:
		TEST_METHOD(wtf)
		{
			Assert::AreEqual(1,1);
		}
		TEST_METHOD(LightGraph)
		{
			try {
				Graph Test;
				string s = "Light.txt";
				Test.input(s);
				size_t res = 3, tmp = Test.BellFord(0, 3);
				Assert::AreEqual(tmp, res);
				Test.clear();
			}
			catch (char*)
			{
				Assert::AreEqual(1,0);
			}
		}
		TEST_METHOD(ExapleGraph)
		{
			try {
				Graph Test;
				Test.input();
				size_t res = 68, tmp = Test.BellFord(3, 0);;
				Assert::AreEqual(tmp, res);
				Test.clear();
			}
			catch (char*)
			{
				Assert::AreEqual(1, 0);
			}
		}
	};
}
