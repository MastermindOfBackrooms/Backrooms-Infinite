#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include "sub_level_resources.hpp"

using namespace std;
using namespace SubLevelResources;

class SubLevel {
private:
    int sanity;
    int hunger;
    string currentRoom;
    vector<ItemData> inventory;
    map<string, bool> visitedRooms;
    random_device rd;
    mt19937 gen;
    int steps;
    bool hasFlashlight;

    void typeWriter(const string& text, int speed = 30) {
        for (char c : text) {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(speed));
        }
        cout << endl;
    }

    void decreaseSanity(int amount) {
        sanity = max(0, sanity - amount);
        if (sanity <= 25) {
            auto effects = SANITY_EFFECTS.at(25);
            typeWriter("\n" + effects[rd() % effects.size()]);
        } else if (sanity <= 50) {
            auto effects = SANITY_EFFECTS.at(50);
            typeWriter("\n" + effects[rd() % effects.size()]);
        } else if (sanity <= 75) {
            auto effects = SANITY_EFFECTS.at(75);
            typeWriter("\n" + effects[rd() % effects.size()]);
        }
        
        if (sanity <= 0) {
            typeWriter("\nLa tua mente si è frantumata...");
            typeWriter("Sei diventato parte del Sub-Level.");
            typeWriter("\n=== GAME OVER ===");
            exit(0);
        }
    }

    void decreaseHunger(int amount) {
        hunger = max(0, hunger - amount);
        if (hunger <= 20) {
            typeWriter("\nLa fame ti consuma...");
            decreaseSanity(5);
        }
        if (hunger <= 0) {
            typeWriter("\nSei collassato per la fame.");
            typeWriter("Il Sub-Level reclama un'altra vittima.");
            typeWriter("\n=== GAME OVER ===");
            exit(0);
        }
    }

    void randomEvent() {
        uniform_int_distribution<> dis(1, 100);
        if (dis(gen) <= 20) {
            typeWriter("\n" + RANDOM_EVENTS[rd() % RANDOM_EVENTS.size()]);
            decreaseSanity(5);
        }
    }

    void weatherEffect() {
        uniform_int_distribution<> dis(1, 100);
        if (dis(gen) <= 15) {
            vector<string> weatherTypes = {"nebbia", "elettricità", "radiazioni"};
            string type = weatherTypes[rd() % weatherTypes.size()];
            typeWriter("\n" + WEATHER_EFFECTS.at(type)[rd() % WEATHER_EFFECTS.at(type).size()]);
            decreaseSanity(3);
        }
    }

    void entityEncounter() {
        uniform_int_distribution<> dis(1, 100);
        if (dis(gen) <= 10) {
            vector<string> entityTypes = {"ombra", "scienziato"};
            string type = entityTypes[rd() % entityTypes.size()];
            typeWriter("\n" + ENTITY_DIALOGUES.at(type)[rd() % ENTITY_DIALOGUES.at(type).size()]);
            decreaseSanity(8);
        }
    }

    void findHiddenDocument() {
        uniform_int_distribution<> dis(1, 100);
        if (dis(gen) <= 5) {
            typeWriter("\nTrovi un documento nascosto:");
            typeWriter(hiddenDocuments[rd() % hiddenDocuments.size()]);
            decreaseSanity(5);
        }
    }

    void look() {
        const auto& room = ROOMS.at(currentRoom);
        if (!visitedRooms[currentRoom]) {
            for (const auto& desc : room.firstTimeDescriptions) {
                typeWriter(desc);
            }
            visitedRooms[currentRoom] = true;
        } else {
            typeWriter(room.descriptions[rd() % room.descriptions.size()]);
        }

        // Show available exits
        typeWriter("\nUscite visibili:");
        for (const auto& exit : room.connections) {
            typeWriter("- " + exit.first);
        }

        // Show items in room
        if (!room.isDark || hasFlashlight) {
            // Implementation for showing items
        }
    }

    void move(const string& direction) {
        const auto& room = ROOMS.at(currentRoom);
        auto it = room.connections.find(direction);
        if (it != room.connections.end()) {
            currentRoom = it->second;
            steps++;
            look();
            randomEvent();
            weatherEffect();
            entityEncounter();
            findHiddenDocument();
        } else {
            typeWriter("Non puoi andare in quella direzione.");
        }
    }

    void showStatus() {
        typeWriter("\n=== STATUS ===");
        typeWriter("Sanità mentale: " + to_string(sanity) + "%");
        typeWriter("Fame: " + to_string(hunger) + "%");
        typeWriter("Posizione: " + ROOMS.at(currentRoom).name);
        
        typeWriter("\nInventario:");
        if (inventory.empty()) {
            typeWriter("- Vuoto");
        } else {
            for (const auto& item : inventory) {
                typeWriter("- " + item.name + ": " + item.description);
            }
        }
    }

    void showHelp() {
        typeWriter("\n=== COMANDI DISPONIBILI ===");
        typeWriter("- nord, sud, est, ovest: muoviti in una direzione");
        typeWriter("- guarda: osserva l'ambiente circostante");
        typeWriter("- status: mostra stato del personaggio e inventario");
        typeWriter("- prendi [oggetto]: raccogli un oggetto");
        typeWriter("- usa [oggetto]: utilizza un oggetto dall'inventario");
        typeWriter("- aiuto: mostra questa lista di comandi");
    }

public:
    SubLevel() : gen(rd()), steps(0), hasFlashlight(false) {
        sanity = MAX_SANITY;
        hunger = MAX_HUNGER;
        currentRoom = "entrance";
        
        // Show introduction
        vector<string> intro = {
            "\n╔══════════════════════════════════════╗",
            "║             SUB-LEVEL                ║",
            "║         Livello 15 - 1989           ║",
            "╚══════════════════════════════════════╝",
            "\nDedicato alla piccola Luna",
            "\"Che i tuoi sogni ti portino sempre in luoghi meravigliosi\"",
            "\nCreated by Jashin L.",
            "\nLe luci fluorescenti sfarfallano...",
            "Un momento prima eri nel tuo mondo, quello reale.",
            "Ora ti ritrovi qui, nel Sub-Level.",
            "L'aria è densa di particelle di ruggine e l'odore di metallo ti riempie i polmoni.",
            "Benvenuto nel complesso industriale dimenticato,",
            "dove la realtà si piega alle leggi della follia sovietica...",
            "\nRicorda: non sei solo qui dentro."
        };

        for (const auto& line : intro) {
            typeWriter(line);
        }
    }

    void processCommand(string command) {
        if (command == "nord" || command == "sud" || command == "est" || command == "ovest") {
            move(command);
        } else if (command == "guarda" || command == "osserva") {
            look();
        } else if (command == "status" || command == "inventario") {
            showStatus();
        } else if (command == "aiuto") {
            showHelp();
        } else if (command.substr(0, 6) == "prendi") {
            // Implementation for taking items
        } else if (command.substr(0, 3) == "usa") {
            // Implementation for using items
        } else {
            typeWriter("Non comprendo questo comando. Digita 'aiuto' per la lista dei comandi.");
        }
    }

    void run() {
        string command;
        while (true) {
            cout << "\n> ";
            getline(cin, command);
            processCommand(command);
            decreaseHunger(1);
            if (steps % 5 == 0) {
                randomEvent();
            }
        }
    }
};

int main() {
    SubLevel game;
    game.run();
    return 0;
}
