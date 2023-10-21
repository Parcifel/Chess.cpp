#ifndef READ_H
#define READ_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

#include "constants.h"

using namespace std;
namespace fs = filesystem;

inline bool fileExists(const string& file_name) {
    ifstream file(file_name);
    return file.good();
}

inline bool directoryExists(const string& directory_name) {
    fs::path directory(directory_name);
    return fs::exists(directory);
}

inline vector<string> readFile(const string& file_name) {
    if (!fileExists(file_name)) {
        string error = "File " + file_name + " does not exist!";
        throw runtime_error(error);
    }

    ifstream file(file_name);
    vector<string> lines;

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

vector<string> listDirectory(const string& directory_name) {
    if (!directoryExists(directory_name)) {
        string error = "Directory " + directory_name + " does not exist!";
        throw runtime_error(error);
    }

    vector<string> files;
    for (const auto& entry : fs::directory_iterator(directory_name)) {
        files.push_back(entry.path());
    }
    return files;
}

string getGame() {
    vector<string> games = listDirectory(GAMES_FOLDER);
    string game_name;

    // Print saved games in GAMES_FOLDER
    cout << LINE << endl;
    cout << "Saved Games: " << endl;
    for (int i = 0; i < games.size(); i++) {
        string game = games[i];
        game = game.substr(GAMES_FOLDER.size()+1);
        cout << i+1 << ". " << game << endl;
    }

    // Get user input
    cout << "\n" << "Enter a game name or number: ";
    string user_response;
    cin >> user_response;

    // QUIT
    if (user_response == "q") {
        return "";
    }

    // If user input is a number, get the game name from the list of games
    int game_number;
    try {
        game_number = stoi(user_response);
    } catch (invalid_argument& e) {
        game_number = -1;
    }

    // Validate that number if not out of range
    if (game_number > 0 && game_number <= games.size()) {
        game_name = games[game_number-1].substr(GAMES_FOLDER.size()+1);
    } else if (game_number > 0 && game_number > games.size()) {
        string error = "Game number " + to_string(game_number) + " does not exist!";
        throw runtime_error(error);
    } else {
        game_name = user_response;
    }

    // Validate that game exists
    cout << "Fetching game " << game_name << "..." << endl;

    game_name = GAMES_FOLDER + "/" + game_name;
    if (!directoryExists(game_name)) {
        string error = "Game " + game_name + " does not exist!";
        throw runtime_error(error);
    }

    return game_name;
}

vector<string> readBoard(const string& game_name) {
    string board_file = game_name + "/" + BOARD_FILE;
    return readFile(board_file);
}

vector<string> readMoves(const string& game_name) {
    string moves_file = game_name + "/" + MOVES_FILE;
    return readFile(moves_file);
}

#endif