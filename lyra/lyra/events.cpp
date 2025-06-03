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


void EventRandomizer(std::vector<Event*> EventVector, std::vector<Event*>& Previous, ShipData& Ship) {

	for (int i = 0; i < EventVector.size(); i++) {
		//std::cout << EventVector[i]->EventCondition(Previous, Ship) << std::endl;
		if (!EventVector[i]->EventCondition(Previous, Ship)) {
			EventVector.erase(EventVector.begin() + i);
			i--;
		}
	}

	srand(time(0)); //maybe to replace with that other random thing

	int WeightSum = 0;
	for (int i = 0; i < EventVector.size(); i++) {
		WeightSum += EventVector[i]->Weight;
	}
	//std::cout << WeightSum << std::endl;

	int random = rand() % WeightSum;
	for (int i = 0; i < EventVector.size(); i++) {
		if (random < EventVector[i]->Weight) {
			Previous.push_back(EventVector[i]);
			CallEvent(*EventVector[i], Ship);
			break;
		}
		random -= EventVector[i]->Weight;
	}
};