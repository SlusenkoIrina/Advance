#include <iostream>
#include <algorithm>
#include <fstream>


int PassVolume[301];

int task[301][301][101];

bool TrueOrFalse[301][301][101] = { 0 };


long long bus;

long long volume;

long long people;







int Function(int allVolume, int numberBus, int numberPeople) {

	// Situation 2
	if (numberBus == bus || numberPeople == people) {
		return 0;
	}

	// Situation 1. 
	if (TrueOrFalse[numberPeople][allVolume][numberBus] == true) {
		return task[numberPeople][allVolume][numberBus];
	}



	// Situation 3
	int Value = Function(allVolume, numberBus, numberPeople + 1);
	if (volume < allVolume + PassVolume[numberPeople]) {
		Value = std::max(Function(0, numberBus + 1, numberPeople), Value);
	}
	else
		Value = std::max(1 + Function(allVolume + PassVolume[numberPeople],
			numberBus, numberPeople + 1), Value);


	task[numberPeople][allVolume][numberBus] = Value;
	TrueOrFalse[numberPeople][allVolume][numberBus] = true;
	return Value;
}


int main() {

	std::ifstream cin("c.in");
	std::ofstream cout("c.out");
	cin >> bus >> volume >> people;
	for (int i = 0; i < people; ++i) {
		cin >> PassVolume[i];
	}

	int Answer = Function(0, 0, 0);
	cout << Answer;

	return 0;
}


