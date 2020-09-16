#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::string sequence_1 = " ";
	std::string sequence_2 = " ";
	std::string lcs = "";
	std::cout << "please enter two sequnces separated by space: " << std::endl;
	std::cin >> sequence_1 >> sequence_2;
	
	auto size_1 = sequence_1.size() + 1;
	auto size_2 = sequence_2.size() + 1;

	std::vector <std::vector <int>> lcs_matrix(size_1, std::vector <int> (size_2, 0));

	for (auto i = 1U; i < size_1; ++i)
	{
		for (auto j = 1U; j < size_2; ++j)
		{
			if (sequence_1[i - 1] == sequence_2[j - 1])
			{
				lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1;
			}
			else
			{
				lcs_matrix[i][j] = std::max(lcs_matrix[i - 1][j], lcs_matrix[i][j - 1]);
			}
		}
	}
	
	auto i = size_1 - 1;
	auto j = size_2 - 1;
	while (lcs_matrix[i][j] > 0)
	{
		if (sequence_1[i - 1] == sequence_2[j - 1])
		{
			lcs = sequence_1[i - 1] + lcs;
			--i;
			--j;
		}
		else
		{
			if (lcs_matrix[i - 1][j] > lcs_matrix[i][j - 1])
			{
				--i;
			}
			else
			{
				--j;
			}
		}
	}

	std::cout << "the longest common subsequence is: \"" << lcs << "\"" << std::endl;

	return 0;
}