#include "Container.hpp"

int main()
{
	int N = 0;
	std::cin >> N;

	int* array = new int[N];
	for (auto i = 0U; i < N; ++i)
	{
		std::cin >> array[i];
	}
	Container <int> A(0);
	Container <int> B(array, N);
	swap(A, B);
	std::cout << A[0] << " " << A[1] << " "<< B[0] << std::endl;
	B[0] = 4;
	std::cout << B[0];
	return 0;
}
