#include <iostream>
#include <string>
#include <random>
#include <vector>
#include "events.h"
#include "ShipData.h"

void CallEvent(Event& CalledEvent, ShipData& Ship) {
	bool YesNo = true;
	char YN;
	std::cout << CalledEvent.EventName << "\n";
	std::cout << CalledEvent.EventText << "\n";
	std::cout << "Select y = yes, n = no: ";
	std::cin >> YN;
	while (YN != 'y' && YN != 'n') {
		std::cout << "Incorrect input. Select y/n: ";
		std::cin >> YN;
	}
	if (YN == 'y') {
		YesNo = true;
	}
	else if (YN == 'n') {
		YesNo = false;
	}
	std::cout << std::endl;
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

	int WeightSum = 0;
	for (int i = 0; i < EventVector.size(); i++) {
		WeightSum += EventVector[i]->Weight;
	}
	// std::cout << "Suma wag: " << WeightSum << std::endl;

	std::random_device rd; // seed dla generacji liczby pseudolosowej
	std::mt19937 gen(rd()); // obiekt pozwalajacy na generowanie liczby pseudolosowej 
	std::uniform_int_distribution<> distrib(0, WeightSum-1); // obiekt ograniczający od 0 do sumy wag-1
	int random = distrib(gen); // wylosowanie liczby w dystrubucji

	for (int i = 0; i < EventVector.size(); i++) {
		if (random < EventVector[i]->Weight) {
			Previous.push_back(EventVector[i]);
			CallEvent(*EventVector[i], Ship);
			break;
		}
		random -= EventVector[i]->Weight;
	}
};

void WeightIncrement(std::vector<Event*>& EventVector) {
	for (int i = 0; i < EventVector.size(); i++) {
		EventVector[i]->Weight++;
	}
};
