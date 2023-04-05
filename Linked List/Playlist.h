#ifndef __PLAYLIST_H
#define __PLAYLIST_H
#include <iostream>
#include <stdexcept>
#include <string>

struct PlaylistNode {
        // Default Constructor For Node
        PlaylistNode(): uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}
        // Paramaterized Constructors For Node
        PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, int songLength): 
            uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength) {}
        PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, int songLength, PlaylistNode* nextNodePtr): 
            uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nextNodePtr) {}
        // Private Data Members
        std::string uniqueID;
        std::string songName;
        std::string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
        // Sets the next pointer for the node
        void SetNext(PlaylistNode* next);
        // Inserts implicit paramaterized node after explicit node
        void InsertAfter(PlaylistNode*& next);
        // Gets ID of node
        std::string GetID() const;
        // Gets Song Name of node
        std::string GetSongName() const;
        // Gets Artist Name of node
        std::string GetArtistName() const;
        // Gets Song Length of node
        int GetSongLength() const;
        // Gets Node's next pointer
        PlaylistNode* GetNext() const;
        // Prints the Node
        void PrintPlaylistNode();

};

class Playlist {
    private:
        // Private Data Members
        PlaylistNode* head;
        PlaylistNode* tail;
    public:
        // default constructor for list
        Playlist();
        // destructor
        ~Playlist();
        // Creates new node and inserts after another node in list
        void InsertAfter(std::string uniqueID, std::string songName, std::string artistName, int songLength);
        // Removes song in list
        void RemoveSong(std::string ID);
        // changes position of song in list
        void ChangePosition(int newpos, int pos);
        // outputs songs made by artist in list
        void OutputArtist(std::string name);
        // Outputs total time of playlist
        void OutputTotalTime();
        // Outputs all songs in list
        void OutputFullList();

};

// Prints the menu options
void PrintMenu(std::string title);

#endif