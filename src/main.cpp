
#include "Node.h"

#include <iostream>
#include <limits>
#include <string>

int main() {
    Playlist playlist;
    int choice;

    do {
        std::cout << "\n========== MUSIC PLAYLIST MANAGER ==========\n";
        std::cout << "1. Add Song\n";
        std::cout << "2. Remove Song\n";
        std::cout << "3. Display Playlist\n";
        std::cout << "4. Play Current Song\n";
        std::cout << "5. Play Next Song\n";
        std::cout << "6. Play Previous Song\n";
        std::cout << "7. Search Song\n";
        std::cout << "8. Show Current Position\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Enter a number.\n";
            std::cin.clear();
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(), '\n');

        std::string title;
        std::string artist;

        switch (choice) {
            case 1:
                std::cout << "Enter song title: ";
                std::getline(std::cin, title);

                std::cout << "Enter artist name: ";
                std::getline(std::cin, artist);

                playlist.addSong(title, artist);
                break;

            case 2:
                std::cout << "Enter exact song title to remove: ";
                std::getline(std::cin, title);
                playlist.removeSong(title);
                break;

            case 3:
                playlist.displayPlaylist();
                break;

            case 4:
                playlist.playCurrent();
                break;

            case 5:
                playlist.playNext();
                break;

            case 6:
                playlist.playPrevious();
                break;

            case 7:
                std::cout << "Enter song title or keyword: ";
                std::getline(std::cin, title);
                playlist.searchSong(title);
                break;

            case 8:
                playlist.showCurrentPosition();
                break;

            case 0:
                std::cout << "Exiting Music Playlist Manager.\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
