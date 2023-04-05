    #include "Playlist.h"
    #include <iostream>
    #include <stdexcept>
    #include <string>

        // Playlist constructor which when allocated created an empty list with head and tail set to nullptr
        Playlist::Playlist() {
            head = nullptr;
            tail = nullptr;
        }

        // Playlist destructor which deletes all allocated nodes
        Playlist::~Playlist() {
            // loops until head equals to nullptr which means list is empty
            while (head != nullptr) {
                PlaylistNode *temp = head -> nextNodePtr;
                delete head;
                head = temp;
                if (head == nullptr) {
                    tail = nullptr;
                }
            }
        }

        void Playlist::InsertAfter(std::string uID, std::string sName, std::string aName, int sLength) {
            // Allocates new node from parameter data members
            PlaylistNode* newNode = new PlaylistNode(uID, sName, aName, sLength, nullptr);
            // sets tail and head when list is empty
            if (this->head == nullptr) {
                this->head = newNode;
                this->tail = newNode;
                newNode->nextNodePtr = nullptr;
            }
            // inserts to end of list when list is occupied
            else {
                tail->nextNodePtr = newNode;
                tail = newNode;
                newNode->nextNodePtr = nullptr;
            }
        }

        // sets the next pointer of node
        void PlaylistNode::SetNext(PlaylistNode* next) {
            nextNodePtr = next;
        }

        // inserts implicit parameterized node after explicit parameter node
        void PlaylistNode::InsertAfter(PlaylistNode*& next) {
            next->nextNodePtr = this->GetNext();
            this->SetNext(next);
        }

        std::string PlaylistNode::GetID() const {
            return uniqueID;
        }

        std::string PlaylistNode::GetSongName() const {
            return songName;
        }

        std::string PlaylistNode::GetArtistName() const {
            return artistName;
        }

        int PlaylistNode::GetSongLength() const {
            return songLength;
        }

        PlaylistNode* PlaylistNode::GetNext() const {
            return nextNodePtr;
        }

        // Prints specific Node in playlist
        void PlaylistNode::PrintPlaylistNode() {
            std::cout << "Unique ID: " << this->GetID() << std::endl;
            std::cout << "Song Name: " << this->GetSongName() << std::endl;
            std::cout << "Artist Name: " << this->GetArtistName() << std::endl;
            std::cout << "Song Length (in seconds): " << this->GetSongLength() << std::endl;
        }

        // Prints menu options
        void PrintMenu(std::string title) {
            std::cout << title << " PLAYLIST MENU" << std::endl;
            std::cout << "a - Add song" << std::endl;
            std::cout << "d - Remove song" << std::endl;
            std::cout << "c - Change position of song" << std::endl;
            std::cout << "s - Output songs by specific artist" << std::endl;
            std::cout << "t - Output total time of playlist (in seconds)" << std::endl;
            std::cout << "o - Output full playlist" << std::endl;
            std::cout << "q - Quit" << std::endl;
            std::cout << std::endl;
            std::cout << "Choose an option:" << std::endl;
        }

        void Playlist::RemoveSong(std::string ID) {
            PlaylistNode* remove = nullptr;
            // Removes song when ID matches input
            for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                if (temp->uniqueID == ID) {
                    std::cout << "\"" << temp->songName << "\""<< " removed." << std::endl;
                    remove = temp;
                }
            }
            // sets new head or tail if old head or tail was removed
            for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                if (head == remove) {
                    head = head->nextNodePtr;
                    delete temp;
                    if (head == nullptr) {
                        tail = nullptr;
                    }
                }
                if (temp->nextNodePtr == remove) {
                    if (tail == remove) {
                        tail = temp;
                    }
                    temp->nextNodePtr = remove->nextNodePtr;
                    delete remove;
                }
            }
        }

        void Playlist::ChangePosition(int newpos, int pos) {
            PlaylistNode* change1;
            int count = 0;
            // set temporary pointer on the node that needs to change position
            for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                count++;
                if (count == pos) {
                    change1 = temp;
                    break;
                }
            }
            std::cout << "\"" << change1->songName << "\"" << " moved to position " << newpos << std::endl;
            // takes out node that needs to be moved out of the list
            if (pos == 1) {
                head = head->nextNodePtr;
            }
            else {
                for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                    if (temp->nextNodePtr == change1) {
                        temp->nextNodePtr = change1->nextNodePtr;
                        if (temp->nextNodePtr == nullptr) {
                            tail = temp;
                        }
                        break;
                    }
                }
            }

            // places the removed node back into the list in new position
            count = 0;
            if (newpos == 1) {
                change1->nextNodePtr = head;
                head = change1;
            }
            else {
                for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                count++;
                    if (count + 1 == newpos) {
                        change1->nextNodePtr = temp->nextNodePtr;
                        temp->nextNodePtr = change1;
                    }
                }
            }

            // point tail pointer to the node at the end of list
            for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                if (temp->nextNodePtr == nullptr) {
                    tail = temp;
                }
            }
        }
        
        void Playlist::OutputArtist(std::string artist) {
            // outputs all nodes that have the same artist name as inputted
            int count = 0;
            for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                count++;
                if (temp->artistName == artist) {
                    std::cout << count << "." << std::endl;
                    temp->PrintPlaylistNode();
                    std::cout << std::endl;
                }
            }
        }

        void Playlist::OutputTotalTime() {
            // adds all time of each node in list and outputs total at the end
            int totalSecs = 0;
            for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                totalSecs = totalSecs + temp->songLength;
            }
            std::cout << totalSecs << " seconds" << std::endl;
        }

        void Playlist::OutputFullList() {
            // Outputs "Playlist is empty" if list is empty
            int count = 0;
            if (head == nullptr) {
                std::cout << "Playlist is empty" << std::endl;
                std::cout << std::endl;
            }
            // Outputs each node in list
            else {
                for (PlaylistNode* temp = head; temp != nullptr; temp = temp->nextNodePtr ) {
                    count++;
                    std::cout << count << "." << std::endl;
                    temp->PrintPlaylistNode();
                    std::cout << std::endl;
                }
            }
        }