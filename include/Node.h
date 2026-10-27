
#pragma once

#include <string>

struct SongNode {
    std::string title;
    std::string artist;
    SongNode* prev;
    SongNode* next;

    SongNode(const std::string& songTitle,
             const std::string& songArtist)
        : title(songTitle),
          artist(songArtist),
          prev(nullptr),
          next(nullptr) {}
};

class Playlist {
private:
    SongNode* head;
    SongNode* tail;
    SongNode* current;
    int size;

public:
    Playlist();
    ~Playlist();

    Playlist(const Playlist&) = delete;
    Playlist& operator=(const Playlist&) = delete;

    void addSong(const std::string& title,
                 const std::string& artist);
    void removeSong(const std::string& title);
    void displayPlaylist() const;
    void playCurrent() const;
    void playNext();
    void playPrevious();
    void searchSong(const std::string& title) const;
    void showCurrentPosition() const;
    bool isEmpty() const;
};
