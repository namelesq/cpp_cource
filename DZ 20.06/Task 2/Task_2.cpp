#include <iostream>
#include <vector>
union Characteristic
{
	float speed_fly;
	bool artiodactyl;
	int iq;
};
struct Living_entity
{
	int speed_movement;
	std::string type;
	Characteristic characteristic;
};
void InputInfoLivintEntity(Living_entity& liv_ty)
{
	std::cout << "Enter speed movement: ";
	std::cin >> liv_ty.speed_movement;
	std::cout << "Enter type: ";
	std::cin >> liv_ty.type;
	if (liv_ty.type == "Bird" || liv_ty.type == "bird")
	{
		std::cout << "Enter speed fly: ";
		std::cin >> liv_ty.characteristic.speed_fly;
	}
	else if (liv_ty.type == "Cattle" || liv_ty.type == "cattle")
	{
		std::cout << "Enter artiodactyl: ";
		std::cin >> liv_ty.characteristic.artiodactyl;
	}
	else if (liv_ty.type == "Human" || liv_ty.type == "human")
	{
		std::cout << "Enter level iq: ";
		std::cin >> liv_ty.characteristic.iq;
	}
	else
	{
		std::cerr << "Error. Input uncorrect data";
	}
}
void printInfoLivintEntity(Living_entity& liv_ty)
{
	std::cout << "Speed movement: " << liv_ty.speed_movement << "\n";
	std::cout << "type: " << liv_ty.type << "\n";
	if (liv_ty.type == "Bird" || liv_ty.type == "bird")
	{
		std::cout << "speed fly: "<<liv_ty.characteristic.speed_fly;
	}
	else if (liv_ty.type == "Cattle" || liv_ty.type == "cattle")
	{
		std::cout << "Enter artiodactyl: "<<liv_ty.characteristic.artiodactyl;
	}
	else if (liv_ty.type == "Human" || liv_ty.type == "human")
	{
		std::cout << "level iq: " << liv_ty.characteristic.iq;
	}
}
void editDataLivintEntity(std::vector<Living_entity>& liv_ty, std::string type)
{
	for (const Living_entity& Liv_ty : liv_ty)
	{
		if (Liv_ty.type == type)
		{
			int move_speed;
			if (Liv_ty.type == "Bird" || Liv_ty.type == "bird")
			{
				float fly_speed;
				std::cout << "Enter new movement speed: ";
				std::cin >> move_speed;
				Liv_ty.speed_movement == move_speed;
				std::cout << "Enter new fly speed: ";
				std::cin >> fly_speed;
				Liv_ty.characteristic.speed_fly == fly_speed;
			}
			else if (Liv_ty.type == "Cattle" || Liv_ty.type == "cattle")
			{
				bool artiodactyl;
				std::cout << "Enter new movement speed: ";
				std::cin >> move_speed;
				Liv_ty.speed_movement == move_speed;
				std::cout << "Enter new artiodactyl: ";
				std::cin >> artiodactyl;
				Liv_ty.characteristic.artiodactyl == artiodactyl;
			}
			else if (Liv_ty.type == "Human" || Liv_ty.type == "human")
			{
				int IQ;
				std::cout << "Enter new movement speed: ";
				std::cin >> move_speed;
				Liv_ty.speed_movement == move_speed;
				std::cout << "Enter new IQ: ";
				std::cin >> IQ;
				Liv_ty.characteristic.iq == IQ;
			}
		}
	}
}

void printAllLivingEntity(std::vector<Living_entity>& liv_ty)
{
	for (const Living_entity& Liv_ty : liv_ty)
	{
		std::cout << "Movement speed: " << Liv_ty.speed_movement << "\n";
		std::cout << "Type: " << Liv_ty.type << "\n";
		if (Liv_ty.type == "Bird" || Liv_ty.type == "bird")
		{
			std::cout << "speed fly: " << Liv_ty.characteristic.speed_fly<<"\n";
		}
		else if (Liv_ty.type == "Cattle" || Liv_ty.type == "cattle")
		{
			std::cout << "Enter artiodactyl: " << Liv_ty.characteristic.artiodactyl<<"\n";
		}
		else if (Liv_ty.type == "Human" || Liv_ty.type == "human")
		{
			std::cout << "level iq: " << Liv_ty.characteristic.iq<<"\n";
		}
	}
}
void SearchNySpeedFly(std::vector<Living_entity>& liv_ty, float speed)
{
	for (const Living_entity& Liv_ty : liv_ty)
	{
		if (Liv_ty.characteristic.speed_fly == speed)
		{
			std::cout << "Movement speed: " << Liv_ty.speed_movement << "\n";
			std::cout << "Type: " << Liv_ty.type;
			break;
		}
	}
}
void SearchByArtiodactyl(std::vector<Living_entity>& liv_ty, bool ar_ly)
{
	for (const Living_entity& Liv_ty : liv_ty)
	{
		if (Liv_ty.characteristic.artiodactyl == ar_ly)
		{
			std::cout << "Movement speed: " << Liv_ty.speed_movement << "\n";
			std::cout << "Type: " << Liv_ty.type<<"\n";
		}
	}
}
void SearchByIQ(std::vector<Living_entity>& liv_ty, int IQ)
{
	for (const Living_entity& Liv_ty : liv_ty)
	{
		if (Liv_ty.characteristic.iq == IQ)
		{
			std::cout << "Movement speed: " << Liv_ty.speed_movement << "\n";
			std::cout << "Type: " << Liv_ty.type << "\n";
			break;
		}
	}
}
int main()
{
	std::vector<Living_entity> Liv_ty = 
	{
		{50,"Bird",25.2},
		{40,"Bird",23.6},
		{45,"Bird",27.4},
		{30,"Bird",20.4},
		{20,"Cattle",true},
		{15,"Cattle",false},
		{22,"Cattle",true},
		{23,"Human",100},
		{30,"Human",120},
		{35,"Human",115},
	};
	Living_entity liv_ty;
	InputInfoLivintEntity(liv_ty);
	printInfoLivintEntity(liv_ty);
	std::string type;
	std::cout << "\n\nEnter type for edit data: ";
	std::cin >> type;
	int Iq;
	std::cout << "\n\nEnter Iq for search: ";
	std::cin >> Iq;
	SearchByIQ(Liv_ty, Iq);
	bool art_ly;
	std::cout << "Enter artiodactyl for search: ";
	std::cin >> art_ly;
	SearchByArtiodactyl(Liv_ty, art_ly);
	float fly_speed;
	std::cout << "Enter fly speed for search: ";
	std::cin >> fly_speed;
	SearchNySpeedFly(Liv_ty, fly_speed);
	editDataLivintEntity(Liv_ty, type);
	printAllLivingEntity(Liv_ty);
	return 0;
}