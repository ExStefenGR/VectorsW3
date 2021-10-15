#include <iostream>
#include <vector>
//Stefanos Triantafyllidis
//As a self-challenge I will not look at anything else other than the slides provided for the lecture
int main()
{
	std::vector<long long>highscores(0);
	highscores.reserve(10);
	bool done = false;
	while (!done)
	{
		auto capacityOfScores = highscores.capacity();
		auto sizeOfScores = highscores.size();
		long long newScore = 0;
		std::cout << "Size of Highscores vector: " << std::endl;
		std::cout << sizeOfScores << std::endl;
		std::cout << "Capacity of Highscores vector: " << std::endl;
		std::cout << capacityOfScores << std::endl << std::endl;
		if (!(std::cin >> newScore))
		{
			std::cin.clear();
			while (std::cin.get() != '\n');
			std::cout << "Invalid Data type, use numbers" << std::endl << std::endl;
			continue;
		}
		switch (newScore)
		{
		case 0:
		{
			/*Part of excersice b2, there should be an easier
			less complicated way to do this since I cannot insert
			values with there is no push_back at the beginning*/
			if (sizeOfScores > 0)
			{
				highscores.insert(highscores.begin() + 1, 100);
				highscores.insert(highscores.begin() + 3, 200);
				highscores.insert(highscores.end(), 300);
				std::cout << "Scores listed below using the Iterator method" << std::endl << std::endl;
				for (auto it = highscores.begin(); it != highscores.end(); it++)
				{
					std::cout << *it << std::endl;
				}
				done = true;
			}
			else
			{
				std::cout << "Cannot Iterate through no data!" << std::endl << std::endl;
				break;
			}
		}
		case 1:
			if (sizeOfScores <= 0)
			{
				std::cout << "Cannot remove more Scores!" << std::endl << std::endl;
				break;
			}
			highscores.erase(highscores.end() - 1);
			break;
		default:
			highscores.push_back(newScore);
			break;
		}
	}
	return 0;
}