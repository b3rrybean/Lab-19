#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Node structure to store each review
struct Review {
    float rating;
    string comment;
    Review* next;
};

// Function to add a new review to the head of the list
Review* addToHead(Review* head, float rating, string comment) {
    Review* newNode = new Review;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;
    return newNode;
}

// Function to add a new review to the tail of the list
Review* addToTail(Review* head, float rating, string comment) {
    Review* newNode = new Review;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    } else {
        Review* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        return head;
    }
}

// Function to output all reviews and compute the average rating
void outputReviews(Review* head) {
    if (head == nullptr) {
        cout << "No reviews to display.\n";
        return;
    }

    Review* temp = head;
    int count = 0;
    float total = 0;
    
    cout << "Outputting all reviews:\n";
    while (temp != nullptr) {
        count++;
        cout << "    > Review #" << count << ": "
             << temp->rating << ": " << temp->comment << endl;
        total += temp->rating;
        temp = temp->next;
    }

    cout << fixed << setprecision(2);
    cout << "    > Average: " << (count > 0 ? total / count : 0) << endl;
}

// Function to delete the linked list (cleanup)
void deleteList(Review* head) {
    while (head != nullptr) {
        Review* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Review* head = nullptr;
    int choice;
    cout << "Which linked list method should we use?\n";
    cout << "    [1] New nodes are added at the head of the linked list\n";
    cout << "    [2] New nodes are added at the tail of the linked list\n";
    cout << "    Choice: ";
    cin >> choice;
    cin.ignore();

    char again = 'Y';
    while (toupper(again) == 'Y') {
        float rating;
        string comment;

        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore();

        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice == 1)
            head = addToHead(head, rating, comment);
        else
            head = addToTail(head, rating, comment);

        cout << "Enter another review? Y/N: ";
        cin >> again;
        cin.ignore();
    }

    outputReviews(head);
    deleteList(head);
    return 0;
}