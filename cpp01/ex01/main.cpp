#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombie");

    if (horde) {
		int i = 0;
		while (i < N)
		{
			horde[i].announce();
			i++;
		}
        delete[] horde;
    }
    return 0;
}