#pragma once
#include <iostream>
#include <string>
#include<Windows.h>
#include<vector>
#include<string>
#include <cstdlib> 
#include <chrono>
#include <tuple>


class bean
{
private:
	int beanCount{ 0 };
	int moneyCount{ 0 };
	int beanMoneyValue{ 0 };

	//Tuples will be the main way to serialize the beans and give them qualities.
	std::vector<std::tuple <int, std::string, int> > beanTuple = { {0, "NULL", 0 }};

public:
	bean()
	{
		std::cout << "Welcome to the mean bean machine. Press Keypad 1 to make a bean, 2 to sell it, 3 to list every bean you have.\n";
	}


	void getBeanCount();
	void addBeanCount();
	void subBeanCount();
	std::string addRandomColor();
	int diceRoller();
	void modifyBean();
	int beanIndividualValue(std::string color);

};