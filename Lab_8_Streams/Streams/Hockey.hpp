#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Hockey {
private:
	std::string m_team;
	std::string m_surname;
	int m_goals;
	int m_assists;
	int m_penaltyMinutes;

public:
	Hockey(std::string t, std::string s, int g, int a, int p)
		: m_team(t), m_surname(s), m_goals(g), m_assists(a), m_penaltyMinutes(p) {}

	std::string getTeam() const { return m_team; }
	std::string getSurname() const { return m_surname; }
	int getGoals() const { return m_goals; }
	int getAssists() const { return m_assists; }
	int getPenaltyMinutes() const { return m_penaltyMinutes; }

	void setPenaltyMinutes(int newPenalty) { m_penaltyMinutes = newPenalty; }

	void display() const {
		std::cout << "\tКоманда: " << m_team << ", Фамилия: " << m_surname
			<< ", Шайбы: " << m_goals << ", Передачи: " << m_assists
			<< ", Штрафное время: " << m_penaltyMinutes << std::endl;
	}

	void writeToFile(std::ofstream& out) const {
		out << m_team << " " << m_surname << " " << m_goals << " " << m_assists
			<< " " << m_penaltyMinutes << std::endl;
	}
};

std::vector<Hockey> readFromFile(const std::string& filename) {
	std::vector<Hockey> players;
	std::ifstream in(filename);
	std::string team, surname;
	int goals, assists, penalty;

	while (in >> team >> surname >> goals >> assists >> penalty) {
		players.emplace_back(team, surname, goals, assists, penalty);
	}

	in.close();
	return players;
}

void writeObjectsToFile(const std::string& filename, const std::vector<Hockey>& players) {
	std::ofstream out(filename);
	for (const auto& player : players) {
		player.writeToFile(out);
	}
	out.close();
}

void totalGoalsByTeam(const std::vector<Hockey>& players) {
	int spartakGoals = 0, dinamoGoals = 0;

	for (const auto& player : players) {
		if (player.getTeam() == "Spartak")
			spartakGoals += player.getGoals();
		else if (player.getTeam() == "Dinamo")
			dinamoGoals += player.getGoals();
	}

	std::cout << "\n\tСуммарное количество шайб Спартак: " << spartakGoals << std::endl;
	std::cout << "\tСуммарное количество шайб Динамо: " << dinamoGoals << std::endl;
}

void totalPenaltyTime(const std::vector<Hockey>& players) {
	int totalPenalty = 0;
	for (const auto& player : players) {
		totalPenalty += player.getPenaltyMinutes();
	}
	std::cout << "\tОбщее штрафное время: " << totalPenalty << std::endl;
}

void updatePenaltyTime(std::vector<Hockey>& players, const std::string& surname, int newPenalty) {
	for (auto& player : players) {
		if (player.getSurname() == surname) {
			player.setPenaltyMinutes(newPenalty);
			std::cout << "\n\tШтрафное время для " << surname << " обновлено до " << newPenalty << std::endl;
			return;
		}
	}
	std::cout << "\tИгрок с фамилией " << surname << " не найден!" << std::endl;
}
