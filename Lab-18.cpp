#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Node structure to store each review
struct Review {
    double rating;
    string comment;
    Review* next;
};

// Movie class
class Movie {
private:
    string title;
    Review* head;

public:
    // Constructor
    Movie(string t) {
        title = t;
        head = nullptr;
    }

    // Destructor
    ~Movie() {
        Review* current = head;
        while (current != nullptr) {
            Review* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Function to add a new review to the head of the list
    void addReview(double rating, string comment) {
        Review* newNode = new Review;
        newNode->rating = rating;
        newNode->comment = comment;
        newNode->next = head;
        head = newNode;
    }


    // Function to output all reviews and compute the average rating
    void display() const {
        cout << "--------------------\n";
        cout << "Movie: " << title << endl;
        cout << "Reviews:\n";
        Review* current = head;
        int count = 1;
        while (current != nullptr) {
            cout << fixed << setprecision(2);
            cout << "  " << count++ << ". Rating: " << current->rating
                 << " | Comment: " << current->comment << endl;
            current = current->next;
        }
        cout << endl;
    }
};

// Helper function
double randomRating() {
    
}

int main() {
    srand(time(0));

    // Load comments from file
    vector<string> comments = loadComments("reviews.txt");
    if (comments.size() < 8) {
        cout << "Please include at least 12 comments in reviews.txt"
             << "(2 per movie x 4 movies)." << endl;
        return 1;
    }

    // Create multiple movies


}