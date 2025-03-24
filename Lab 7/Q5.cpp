#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string mediaTitle;
    string releaseYear;
    string mediaID;
    string mediaPublisher;
    bool isAvailable;

public:
    Media(string t, string date, string id, string pub)
        : mediaTitle(t), releaseYear(date), mediaID(id), mediaPublisher(pub), isAvailable(true) {}

    virtual void displayInfo() {
        cout << "Title : " << mediaTitle << endl;
        cout << "Release Year : " << releaseYear << endl;
        cout << "Reference Code : " << mediaID << endl;
        cout << "Publisher : " << mediaPublisher << endl;
        cout << "Availability : " << (isAvailable ? "Available" : "Checked Out") << endl;
    }

    void borrowItem() {
        if (isAvailable) {
            isAvailable = false;
            cout << mediaTitle << " successfully borrowed." << endl;
        } else {
            cout << mediaTitle << " unavailable." << endl;
        }
    }

    void returnItem() {
        if (!isAvailable) {
            isAvailable = true;
            cout << mediaTitle << " returned successfully." << endl;
        } else {
            cout << mediaTitle << " wasn't borrowed yet." << endl;
        }
    }

    string getMediaTitle() { return mediaTitle; }
    string getReleaseYear() { return releaseYear; }
    string getMediaID() { return mediaID; }
    string getPublisher() { return mediaPublisher; }

    virtual ~Media() {}
};

class Book : public Media {
private:
    string authorName;
    string bookISBN;
    int pageCount;

public:
    Book(string t, string date, string id, string pub, string author, string isbn, int pages)
        : Media(t, date, id, pub), authorName(author), bookISBN(isbn), pageCount(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author : " << authorName << endl;
        cout << "ISBN : " << bookISBN << endl;
        cout << "Page Count : " << pageCount << endl;
    }

    string getAuthor() { return authorName; }
};

class DVD : public Media {
private:
    string directorName;
    int movieDuration;
    string rating;

public:
    DVD(string t, string date, string id, string pub, string director, int duration, string rating)
        : Media(t, date, id, pub), directorName(director), movieDuration(duration), rating(rating) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director : " << directorName << endl;
        cout << "Duration (min) : " << movieDuration << endl;
        cout << "Rating : " << rating << endl;
    }
};

class CD : public Media {
private:
    string artistName;
    int trackCount;
    string musicGenre;

public:
    CD(string t, string date, string id, string pub, string artist, int tracks, string genre)
        : Media(t, date, id, pub), artistName(artist), trackCount(tracks), musicGenre(genre) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist : " << artistName << endl;
        cout << "Track Count : " << trackCount << endl;
        cout << "Genre : " << musicGenre << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;

public:
    Magazine(string t, string date, string id, string pub, int issue)
        : Media(t, date, id, pub), issueNumber(issue) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number : " << issueNumber << endl;
    }
};

class Library {
private:
    Media* collection[10];
    int currentMediaCount;

public:
    Library() : currentMediaCount(0) {}

    void addMedia(Media* item) {
        if (currentMediaCount < 10) {
            collection[currentMediaCount] = item;
            currentMediaCount++;
        } else {
            cout << "Can't be done, Library storage is full." << endl;
        }
    }

    void showAllMedia() {
        for (int i = 0; i < currentMediaCount; i++) {
            collection[i]->displayInfo();
            cout << endl;
        }
    }

    void searchByTitle(string title) {
        for (int i = 0; i < currentMediaCount; i++) {
            if (collection[i]->getMediaTitle() == title) {
                cout << "Item Found (Title Match):" << endl;
                collection[i]->displayInfo();
                return;
            }
        }
        cout << "No media found with the title: " << title << endl;
    }

    void searchByPublisher(string publisher) {
        for (int i = 0; i < currentMediaCount; i++) {
            if (collection[i]->getPublisher() == publisher) {
                cout << "Item Found:" << endl;
                collection[i]->displayInfo();
                return;
            }
        }
        cout << "No media found from " << publisher << endl;
    }

    void searchByYear(string year) {
        for (int i = 0; i < currentMediaCount; i++) {
            if (collection[i]->getReleaseYear() == year) {
                cout << "Item Found:" << endl;
                collection[i]->displayInfo();
                return;
            }
        }
        cout << "No media found for " << year << endl;
    }
};