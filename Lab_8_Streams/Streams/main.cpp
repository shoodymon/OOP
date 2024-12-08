#include "Hockey.hpp"

int main() {
	setlocale(LC_ALL, "Russian");
	
	std::string filename = "players.txt";
	std::vector<Hockey> players = readFromFile(filename);

	for (const auto& player : players) {
		player.display();
	}

	totalGoalsByTeam(players);
	totalPenaltyTime(players);
	updatePenaltyTime(players, "Gorin", 10);
	updatePenaltyTime(players, "Pavlov", 12);
	writeObjectsToFile(filename, players);

	return 0;
}