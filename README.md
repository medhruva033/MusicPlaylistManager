
# Music Playlist Manager (C++)

A console-based music playlist manager built using a manually
implemented doubly linked list in C++17.

## Features

- Add and remove songs
- Navigate to the next and previous songs
- Display the playlist
- Search songs by title
- Track the currently selected song
- Handle empty playlists and invalid menu input

## Concepts Demonstrated

- Object-oriented programming
- Doubly linked lists
- Dynamic memory allocation and deallocation
- Pointers and node connections
- Searching and traversal
- Constructors and destructors
- Input validation

## Project Structure

```text
MusicPlaylistManager/
├── include/
│   └── Node.h
├── src/
│   ├── main.cpp
│   └── Playlist.cpp
├── README.md
└── .gitignore
```

## Requirements

- GCC/G++ compiler
- C++17 or later
- Visual Studio Code (recommended)

## Build

From the project root, run:

```cmd
g++ -std=c++17 -Wall -Wextra -Wpedantic -Iinclude src\main.cpp src\Playlist.cpp -o playlist.exe
```

## Run

```cmd
.\playlist.exe
```

## Data Structure

Each song node contains:
- Song title
- Artist name
- Pointer to the previous song
- Pointer to the next song

The playlist maintains head, tail, and current-song pointers.

## Limitations

- Playlist data is stored in memory and is lost when the program exits.
- Removing a song requires an exact, case-sensitive title.
- This application simulates playback; it does not play audio files.

## Future Improvements

- Save and load playlists from a file
- Prevent duplicate songs
- Shuffle the playlist
- Sort songs by title or artist
- Add automated tests

## Author

Dhruva M. K.

GitHub: [@medhruva033](https://github.com/medhruva033)
