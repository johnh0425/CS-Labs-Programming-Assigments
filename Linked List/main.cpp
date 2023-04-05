#include "Playlist.h"
using namespace std;

int main() {
    Playlist* p1 = new Playlist();
    std::string title;
    char option;
    // Asks for title
    std::cout << "Enter playlist's title:" << std::endl;
    getline(std::cin, title);
    std::cout << std::endl;
    // Asks for menu option
    PrintMenu(title);
    std::cin >> option;
    std::cin.ignore();
    // Repeats menu options if a inputted option is not an option
    while (option != 'a' && option != 'd' && option != 'c' && option != 's' && option != 't' && option != 'o' && option != 'q') {
        PrintMenu(title);
        std::cin >> option;
    }
    // When 'q' is picked, program ends
    while (option != 'q') {
        // ADDs song when option 'a' is chosen
        if (option == 'a') {
            std::string sID;
            std::string n;
            std::string a;
            int l;
            std::cout << "ADD SONG" << std::endl;
            std::cout << "Enter song's unique ID:" << std::endl;
            getline(std::cin, sID);
            std::cout << "Enter song's name:" << std::endl;
            getline(std::cin, n);
            std::cout << "Enter artist's name:" << std::endl;
            getline(std::cin, a);
            std::cout << "Enter song's length (in seconds):" << std::endl;
            std::cin >> l;
            std::cin.ignore();
            p1->InsertAfter(sID, n, a, l);
            std::cout << std::endl;
        }
        // Removes song when option 'd' is chosen
        else if (option == 'd') {
            std::string ID;
            std::cout << "REMOVE SONG" << std::endl;
            std::cout << "Enter song's unique ID:" << std::endl;
            getline(std::cin, ID);
            p1->RemoveSong(ID);
            std::cout << std::endl;
        }
        // CHanges position of song when option 'c' is chosen
        else if (option == 'c') {
            int pos;
            int newpos;
            std::cout << "CHANGE POSITION OF SONG" << std::endl;
            std::cout << "Enter song's current position:" << std::endl;
            std::cin >> pos;
            std::cin.ignore();
            std::cout << "Enter new position for song:" << std::endl;
            std::cin >> newpos;
            std::cin.ignore();
            p1->ChangePosition(newpos, pos);
            std::cout << std::endl;
        }
        // Outputs a speific artist when option 's' is chosen
        else if (option == 's') {
            std::string artist;
            std::cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << std::endl;
            std::cout << "Enter artist's name:" << std::endl;
            getline(std::cin, artist);
            std::cout << std::endl;
            p1->OutputArtist(artist);
        }
        // Outputs total time of playlist when 't' is chosen
        else if (option == 't') {
            std::cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << std::endl;
            std::cout << "Total time: ";
            p1->OutputTotalTime();
            std::cout << std::endl;
        }
        // Outputs all songs in playlist when 'o' is chosen
        else if (option == 'o') {
            std::cout << title << " - OUTPUT FULL PLAYLIST" << std::endl;
            p1->OutputFullList();
        }
        // Prints menu option again
        PrintMenu(title);
        std::cin >> option;
        std::cin.ignore();
        // Repeats menu options if a inputted option is not an option
        while (option != 'a' && option != 'd' && option != 'c' && option != 's' && option != 't' && option != 'o' && option != 'q') {
            PrintMenu(title);
            std::cin >> option;
        }
    }
    
}