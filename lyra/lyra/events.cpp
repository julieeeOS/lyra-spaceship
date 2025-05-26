#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "events.h"
#include "ShipData.h"

void CallEvent(Event& CalledEvent, ShipData& Ship) {
	bool YesNo = true;
	char YN;
	std::cout << CalledEvent.EventName << "\n";
	std::cout << CalledEvent.EventText << "\n";
	std::cout << "y/n: ";
	std::cin >> YN;
	if (YN == 'y') {
		YesNo = true;
	}
	else if (YN == 'n') {
		YesNo = false;
	}
	CalledEvent.EventEffect(Ship, YesNo);
};


void EventRandomizer(std::vector<Event*>& EventVector, ShipData& Ship) {
	srand(time(0)); //maybe to replace with that other random thing

	int WeightSum = 0;
	for (int i = 0; i < EventVector.size(); i++) {
		WeightSum += EventVector[i]->Weight;
	}

	int random = rand() % WeightSum;
	for (int i = 0; i < EventVector.size(); i++) {
		if (random < EventVector[i]->Weight) {
			CallEvent(*EventVector[i], Ship);
			break;
		}
		random -= EventVector[i]->Weight;
	}
};