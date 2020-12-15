#include "bean.h"

void bean::getBeanCount()
{
	std::cout << "You have " << beanCount << " Beans total.\n";
}	

//RNG for bean color and value

int bean::diceRoller()
{
	int roll;
	int min = 1;
	int max = 5;
	roll = std::rand() % (max - min + 1) + min;
	return roll;
}

int bean::beanIndividualValue(std::string color)
{
	if (color == "Blue")
	{
		return 1;
	}
	
	else if (color == "Red")
	{
		return 1;
	}

	else if (color == "Purple")
	{
		return 1;
	}

	else if (color == "Green")
	{
		return 2;
	}

	else if (color == "Orange")
	{
		return 3;
	}
	
	else
	{
		return 0;
	}

}

std::string bean::addRandomColor()
{
	int rollResult{ -1 };
	std::string colors[] = { "NULL", "Blue", "Red", "Purple", "Green", "Orange" };
	rollResult = diceRoller();

	return colors[rollResult];
}




void bean::addBeanCount()
{
		beanCount += 1;
		bean::addRandomColor();
		beanTuple.push_back(std::make_tuple(beanCount, addRandomColor(), beanIndividualValue(addRandomColor())));
		std::cout << "Generated bean number " << std::get<0>(beanTuple[beanCount]) << 
			" that is colored " << std::get<1>(beanTuple[beanCount]) << " and worth "
			<< std::get<2>(beanTuple[beanCount]) << " cents."
			<< std::endl;
}

//sell the bean and get money banked for it.

void bean::subBeanCount()
{
	if (beanCount > 0)
	{
	
	int n = beanTuple.size();
	int j{ 0 };
	j = std::get<2>(beanTuple[n - 1]);
	moneyCount = moneyCount + j;
	beanMoneyValue = j;
	std::cout << j << std::endl;
	std::cout << "You Gained " << beanMoneyValue << " cents from bean sales\n";
		beanTuple.pop_back();
		beanCount -= 1;
		if (beanCount < 0)
		{
			beanCount = 0;
		}
	}

	else
	{
		std::cout << "Get more beans first silly!\n";
	}
}

void bean::modifyBean()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			bean::addBeanCount();
			bean::getBeanCount();
			
			Sleep(1000);

		}
		
		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			bean::subBeanCount();
			bean::getBeanCount();

			Sleep(1000);
		}

		if (GetAsyncKeyState(VK_NUMPAD3))
		{
			//list everything
			int n = beanTuple.size();
			for (int i = 1; i < n; i++)
			{
				std::cout << std::get<0>(beanTuple[i]) << " "
				<< std::get<1>(beanTuple[i]) << " "
				<< std::get<2>(beanTuple[i]) << " "
				<< std::endl;
			}
			std::cout << "You have " << moneyCount << " cents of sales\n";
			Sleep(1000);
		}
	}
}
