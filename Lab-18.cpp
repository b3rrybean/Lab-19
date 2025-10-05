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
    return ((rand() % 41) + 10) / 10.0; // Generates 1.0-5.0 in 0.1 increments
}

// Read comments from external file
vector<string> loadComments(string filename) {
    ifstream file(filename);
    vector<string> comments;
    string line;

    if (!file) {
        cout << "Error opening " << filename << endl;
        return comments;
    }

    while (getline(file, line)) {
        if (!line.empty())
        comments.push_back(line);
    }
    file.close();
    return comments;
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
    vector<Movie> movies;
    movies.push_back(Movie("Interstellar"));
    movies.push_back(Movie("Fantastic Mr.Fox"));
    movies.push_back(Movie("Titanic"));
    movies.push_back(Movie("La La Land"));

    // Assign 2 reviews per movie
    int index = 0;
    for (auto& movie : movies) {
        for (int i = 0; i < 2; i++) {
            double rating = randomRating();
            string comment = comments[index++];
            movie.addReview(rating, comment);
        }
    }

    // Display all movies and their reviews
    cout << "\n==== MOVIE REVIEWS ====\n";
    for (const auto& movie : movies) {
        movie.display();
    }
    
    return 0;
}