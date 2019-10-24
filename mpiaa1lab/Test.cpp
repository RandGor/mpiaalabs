#define CATCH_CONFIG_MAIN
#include "merge.h"
#include "catch.hpp"

TEST_CASE("TestAddPerson")

{
	vector<Info> Mas;
	AddPerson(Mas, { 1999,"Michael", "SurName " });
	REQUIRE(Mas.size() == 1);

}

TEST_CASE("Test OnePerson ")

{
	vector<Info> Mas;
	AddPerson(Mas, { 1999,"Michael", "SurName " });
	CHECK(isSorted<YEAR>(Mas));

}

TEST_CASE("Sorted by Name")

{
	vector<Info> Mas;
	AddPerson(Mas, { 1999,"Zoe", "SurName " });
	AddPerson(Mas, { 1999,"Bernard", "SurName " });
	AddPerson(Mas, { 1999,"Michael", "SurName " });
	AddPerson(Mas, { 1999,"Warren", "SurName " });
	AddPerson(Mas, { 1999,"Dante", "SurName " });
	MergeSort<NAME>(Mas);
	CHECK_FALSE(isSorted<NAME>(Mas));

}

TEST_CASE("NonSorted by Name")

{
	vector<Info> Mas;
	vector<vector<Info>> Bucket(N_MAX);
	AddPerson(Mas, { 1999,"Zoe", "SurName " });
	AddPerson(Mas, { 1999,"Bernard", "SurName " });
	AddPerson(Mas, { 1999,"Michael", "SurName " });
	AddPerson(Mas, { 1999,"Warren", "SurName " });
	AddPerson(Mas, { 1999,"Dante", "SurName " });
	CHECK_FALSE(isSorted<NAME>(Mas));

}

TEST_CASE("Sorted by Year")

{
	vector<Info> Mas;
	vector<vector<Info>> Bucket(N_MAX);
	AddPerson(Mas, { 1932,"Zoe", "SurName " });
	AddPerson(Mas, { 1999,"Bernard", "SurName " });
	AddPerson(Mas, { 1986,"Michael", "SurName " });
	AddPerson(Mas, { 1999,"Warren", "SurName " });
	AddPerson(Mas, { 1923,"Dante", "SurName " });
	MergeSort<YEAR>(Mas);
	CHECK_FALSE(isSorted<YEAR>(Mas));

}

TEST_CASE("NonSorted by Year")

{
	vector<Info> Mas;
	vector<vector<Info>> Bucket(N_MAX);
	AddPerson(Mas, { 1932,"Zoe", "SurName " });
	AddPerson(Mas, { 1999,"Bernard", "SurName " });
	AddPerson(Mas, { 1986,"Michael", "SurName " });
	AddPerson(Mas, { 1999,"Warren", "SurName " });
	AddPerson(Mas, { 1923,"Dante", "SurName " });
	CHECK_FALSE(isSorted<YEAR>(Mas));

}
