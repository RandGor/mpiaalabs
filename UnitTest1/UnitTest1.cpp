#include "pch.h"
#include "CppUnitTest.h"
#include "../mpiaa1lab/merge.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestAddPerson)
		{
			vector<Info> Mas;
			AddPerson(Mas, { 1999,"Michael", "SurName " });
			int result = 1;
			Assert::AreEqual(result, (int)Mas.size());
		}

		TEST_METHOD(TestOnePerson)
		{
			vector<Info> Mas;
			AddPerson(Mas, { 1999,"Michael", "SurName " });
			Assert::IsTrue(isSorted<YEAR>(Mas));
		}

		TEST_METHOD(TestnotIsSorted)
		{
			vector<Info> Mas;
			AddPerson(Mas, { 1999,"Zoe", "SurName " });
			AddPerson(Mas, { 1999,"Bernard", "SurName " });
			AddPerson(Mas, { 1999,"Michael", "SurName " });
			AddPerson(Mas, { 1999,"Warren", "SurName " });
			AddPerson(Mas, { 1999,"Dante", "SurName " });
			Assert::IsFalse(isSorted<NAME>(Mas));
		}

		TEST_METHOD(TestIsSorted)
		{
			vector<Info> Mas;
			AddPerson(Mas, { 1999,"Bernard", "SurName " });
			AddPerson(Mas, { 1999,"Dante", "SurName " });
			AddPerson(Mas, { 1999,"Michael", "SurName " });
			AddPerson(Mas, { 1999,"Warren", "SurName " });
			AddPerson(Mas, { 1999,"Zoe", "SurName " });
			Assert::IsTrue(isSorted<NAME>(Mas));
		}

		TEST_METHOD(SortedbyName)
		{
			vector<Info> Mas;
			AddPerson(Mas, { 1999,"Zoe", "SurName " });
			AddPerson(Mas, { 1999,"Bernard", "SurName " });
			AddPerson(Mas, { 1999,"Michael", "SurName " });
			AddPerson(Mas, { 1999,"Warren", "SurName " });
			AddPerson(Mas, { 1999,"Dante", "SurName " });
			MergeSort<NAME>(Mas);
			Assert::IsTrue(isSorted<NAME>(Mas));
		}

		TEST_METHOD(NonSortedbyName)
		{
			vector<Info> Mas;
			AddPerson(Mas, { 1999,"Zoe", "SurName " });
			AddPerson(Mas, { 1999,"Bernard", "SurName " });
			AddPerson(Mas, { 1999,"Michael", "SurName " });
			AddPerson(Mas, { 1999,"Warren", "SurName " });
			AddPerson(Mas, { 1999,"Dante", "SurName " });
			Assert::IsFalse(isSorted<NAME>(Mas));
		}

		TEST_METHOD(SortedbyYear)
		{
			vector<Info> Mas;
			AddPerson(Mas, { 1932,"Zoe", "SurName " });
			AddPerson(Mas, { 1999,"Bernard", "SurName " });
			AddPerson(Mas, { 1986,"Michael", "SurName " });
			AddPerson(Mas, { 1999,"Warren", "SurName " });
			AddPerson(Mas, { 1923,"Dante", "SurName " });
			MergeSort<YEAR>(Mas);
			Assert::IsTrue(isSorted<YEAR>(Mas));
		}

		TEST_METHOD(NonSortedbyYear)
		{
			vector<Info> Mas;
			AddPerson(Mas, { 1932,"Zoe", "SurName " });
			AddPerson(Mas, { 1999,"Bernard", "SurName " });
			AddPerson(Mas, { 1986,"Michael", "SurName " });
			AddPerson(Mas, { 1999,"Warren", "SurName " });
			AddPerson(Mas, { 1923,"Dante", "SurName " });
			Assert::IsFalse(isSorted<YEAR>(Mas));
		}
	};
}
