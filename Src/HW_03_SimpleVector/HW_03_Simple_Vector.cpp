#include "HW_03_Simple_Vector.h"

#include <iostream>
#include <string>

int HW_03_SimpleVectorMain()
{
	SimpleVector<int> Test;
	for(int Idx = 0; Idx < 15; ++Idx)
	{
		Test.push_back(rand() % 20);
	}

	for(int Idx = 0; Idx < Test.size(); ++Idx)
	{
		std::cout << std::to_string(Test[Idx]) + " ";
	}
	std::cout << "\n";
	
	Test.sortData();
	for (int Idx = 0; Idx < Test.size(); ++Idx)
	{
		std::cout << std::to_string(Test[Idx]) + " ";
	}

	{
		SimpleVector<int> Test2(Test);
		Test2.push_back(30);
	}
	
	return 0;
}