#include <iostream>
#include <string>
#include <vector>
#include "events.h"
#include "ShipData.h"

int main() {
	/*ship status declaration*/
	ShipData Ship;
	Ship.health = 100;
	Ship.energy = 30;
	Ship.materials = 50;
	Ship.data = 0;
	Ship.exotic_matter = 30;

	/*Declaration of event vector and events*/
	std::vector<Event*> AllEvents;
	std::vector<Event*> PreviousEvents;
	class Event1 : public Event {
	public:
		Event1() {
			Weight = 3;
			EventName = "one";
			EventText = "Gather materials or data";
		}
		void EventEffect(ShipData& Ship, bool YesNo) override {
			Weight = 3;
			if (YesNo) {
				Ship.materials += 10;
				std::cout << "materials: +10\n";
			}
			else {
				Ship.data += 10;
				std::cout << "data: +10\n";
			}
		}
	} one;
	AllEvents.push_back(&one);
	
	class Event2 : public Event {
	public:
		Event2() {
			Weight = 2;
			EventName = "two";
			EventText = "Extract energy or exotic matter";
		}
		void EventEffect(ShipData& Ship, bool YesNo) override {
			Weight = 2;
			if (YesNo) {
				Ship.energy += 10;
				std::cout << "energy: +10\n";
			}
			else {
				Ship.exotic_matter += 10;
				std::cout << "exotic matter: +10\n";
			}
		}
	} two;
	AllEvents.push_back(&two);

	class Event3 : public Event {
	public:
		Event3() {
			Weight = 2;
			EventName = "three";
			EventText = "Fix ship?";
		}
		void EventEffect(ShipData& Ship, bool YesNo) override {
			Weight = 2;
			if (YesNo) {
				Ship.materials -= 15;
				Ship.energy += 5;
				Ship.health += 5;
				std::cout << "materials: -15\nenergy: +5\nhealth: +5\n";
			}
			else {
				Ship.health -= 10;
				Ship.energy -= 10;
				std::cout << "health: -10\nenergy: -10\n";
			}
		}
	} three;
	
	AllEvents.push_back(&three);

	class Event4 : public Event {
	public:
		Event4() {
			Weight = 1;
			EventName = "four";
			EventText = "Perform a jump?";
		}
		void EventEffect(ShipData& Ship, bool YesNo) override {
			Weight = 1;
			if (YesNo) {
				Ship.exotic_matter -= 5;
				Ship.data += 10;
				std::cout << "exotic matter: +5\n data: +10\n";
			}
			else {
				Ship.data -= 5;
				std::cout << "Data: -5\n";
			}
		}
	} four;
	AllEvents.push_back(&four);

	class Event5 : public Event {
	public:
		Event5() {
			Weight = 3;
			EventName = "kills u";
			EventText = "Die?";
		}
		void EventEffect(ShipData& Ship, bool YesNo) override {
			Weight = 3;
			if (YesNo) {
				Ship.health -= 100;
			}
			else {
				Ship.health += 1;
			}
		}
	} kill;
	AllEvents.push_back(&kill);
	
	class Unlockable1 : public Event {
	public:
		Unlockable1() {
			Weight = 5;
			EventName = "unlocking test";
			EventText = "Gather data?";
		}
		void EventEffect(ShipData& Ship, bool YesNo) override {
			Weight = 5;
			if (YesNo) {
				Ship.data += 30;
				std::cout << "Data: +30\n";
			}
			else {
				Ship.exotic_matter -= 10;
				std::cout << "exotic matter: -10\n";
			}
		}
		bool EventCondition(std::vector<Event*> EventVector, ShipData Ship) override {
			return Ship.materials >= 60;
		}
	} Unlock1;
	AllEvents.push_back(&Unlock1);

	class Unlockable2 : public Event {
	public:
		Unlockable2() {
			Weight = 5;
			EventName = "unlocking test 2";
			EventText = "Recharge?";
		}
		void EventEffect(ShipData& Ship, bool YesNo) override {
			Weight = 5;
			if (YesNo) {
				Ship.energy += 30;
				std::cout << "energy: +30\n";
			}
			else {
				Ship.health -= 10;
				std::cout << "health: -10\n";
			}
		}
		bool EventCondition(std::vector<Event*> EventVector, ShipData Ship) override {
			for (int i = 0; i < EventVector.size(); i++) {
				if (EventVector[i]->EventName == "one") {
					return true;
				}
			}
			return false;
		}
	} Unlock2;
	AllEvents.push_back(&Unlock2);

	while (Ship.health > 0 && Ship.energy > 0) {
		if (Ship.health > 100) { // replace with the <algorithm> thing
			Ship.health = 100;
		}
		if (Ship.energy > 200) {
			Ship.energy = 200;
		}
		std::cout << "Health: " << Ship.health << "\n";
		std::cout << "Energy: " << Ship.energy << "\n";
		std::cout << "Materials: " << Ship.materials << "\n";
		std::cout << "Data: " << Ship.data << "\n";
		std::cout << "Exotic Matter: " << Ship.exotic_matter << "\n";
		EventRandomizer(AllEvents, PreviousEvents, Ship);
		WeightIncrement(AllEvents);
		std::cout << "\n";
	}
	std::cout << "You lose! End status: " << "\n";
	std::cout << "Health: " << Ship.health << "\n";
	std::cout << "Energy: " << Ship.energy << "\n";
	std::cout << "Materials: " << Ship.materials << "\n";
	std::cout << "Data: " << Ship.data << "\n";
	std::cout << "Exotic Matter: " << Ship.exotic_matter << "\n";
	
	return 0;
}