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
		std::cout << capacityOfScores << std::endl;

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
			std::cout << "Scores listed below using the Iterator method" << std::endl << std::endl;
			for (auto it = highscores.begin(); it != highscores.end(); it++)
			{
				std::cout << *it << std::endl;
			}
			done = true;
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