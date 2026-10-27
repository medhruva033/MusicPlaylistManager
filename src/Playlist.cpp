
#include "Node.h"

#include <iostream>
#include <algorithm>
#include <cctype>

Playlist::Playlist()
    : head(nullptr), tail(nullptr), current(nullptr), size(0) {}

Playlist::~Playlist() {
    SongNode* temp = head;

    while (temp != nullptr) {
        SongNode* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

bool Playlist::isEmpty() const {
    return head == nullptr;
}

void Playlist::addSong(const std::string& title,
                       const std::string& artist) {
    if (title.empty() || artist.empty()) {
        std::cout << "Title and artist cannot be empty.\n";
        return;
    }

    SongNode* newSong = new SongNode(title, artist);

    if (head == nullptr) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }

    ++size;
    std::cout << "Song added: " << title << " - " << artist << '\n';
}

void Playlist::removeSong(const std::string& title) {
    SongNode* temp = head;

    while (temp != nullptr && temp->title != title) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        std::cout << "Song not found.\n";
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    } else {
        tail = temp->prev;
    }

    if (current == temp) {
        current = (temp->next != nullptr) ? temp->next : temp->prev;
    }

    std::cout << "Removed: " << temp->title << '\n';
    delete temp;
    --size;

    if (size == 0) {
        current = nullptr;
    }
}

void Playlist::displayPlaylist() const {
    if (isEmpty()) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    SongNode* temp = head;
    int position = 1;

    std::cout << "\n--- Music Playlist ---\n";

    while (temp != nullptr) {
        std::cout << position++ << ". "
                  << temp->title << " - " << temp->artist;

        if (temp == current) {
            std::cout << "  [CURRENT]";
        }

        std::cout << '\n';
        temp = temp->next;
    }

    std::cout << "Total songs: " << size << "\n";
}

void Playlist::playCurrent() const {
    if (current == nullptr) {
        std::cout << "No song to play. Add a song first.\n";
        return;
    }

    std::cout << "Now playing: " << current->title
              << " by " << current->artist << '\n';
}

void Playlist::playNext() {
    if (current == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    if (current->next == nullptr) {
        std::cout << "You are at the last song.\n";
        return;
    }

    current = current->next;
    playCurrent();
}

void Playlist::playPrevious() {
    if (current == nullptr) {
        std::cout << "Playlist is empty.\n";
        return;
    }

    if (current->prev == nullptr) {
        std::cout << "You are at the first song.\n";
        return;
    }

    current = current->prev;
    playCurrent();
}

void Playlist::searchSong(const std::string& title) const {
    SongNode* temp = head;
    bool found = false;

    auto toLower = [](std::string text) {
        std::transform(text.begin(), text.end(), text.begin(),
            [](unsigned char ch) {
                return static_cast<char>(std::tolower(ch));
            });
        return text;
    };

    const std::string target = toLower(title);

    while (temp != nullptr) {
        if (toLower(temp->title).find(target) != std::string::npos) {
            std::cout << "Found: " << temp->title
                      << " - " << temp->artist << '\n';
            found = true;
        }

        temp = temp->next;
    }

    if (!found) {
        std::cout << "No matching songs found.\n";
    }
}

void Playlist::showCurrentPosition() const {
    if (current == nullptr) {
        std::cout << "No current song.\n";
        return;
    }

    int position = 1;
    SongNode* temp = head;

    while (temp != nullptr && temp != current) {
        ++position;
        temp = temp->next;
    }

    std::cout << "Current position: " << position
              << " of " << size << '\n';
}
