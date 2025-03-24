#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class NovelInfo {
    private:
        string title, author;
        vector<int> reviews;
        double averageRating;

    public:
        NovelInfo(string title, string author) {
            this->title = title;
            this->author = author;
            averageRating = 0;
        }

        void addReview(int rating) {
            reviews.push_back(rating);
            averageRating = 0;
            for (int i = 0; i < reviews.size(); i++) {
                averageRating += reviews[i];
            }
            averageRating /= reviews.size();
        }

        string getTitle() {
            return title;
        }

        string getAuthor() {
            return author;
        }

        double getAverageRating() {
            return averageRating;
        }

        bool operator<(NovelInfo& novel) {
            return averageRating < novel.getAverageRating();
        }

        friend ostream& operator<<(ostream& os, NovelInfo& novel) {
            os << "Title: " << novel.title << endl;
            os << "Author: " << novel.author << endl;
            os << "Average Rating: " << fixed << setprecision(2) << novel.averageRating << endl;
            
            for (int i = 0; i < novel.reviews.size(); i++) {
                os << "Review " << i + 1 << ": " << novel.reviews[i] << endl;
            }
            return os;
        }
};

int main() {
    NovelInfo novel1("The Great Gatsby", "F. Scott Fitzgerald");
    novel1.addReview(5);
    novel1.addReview(4);
    novel1.addReview(3);

    NovelInfo novel2("To Kill a Mockingbird", "Harper Lee");
    novel2.addReview(5);
    novel2.addReview(5);
    novel2.addReview(4);

    cout << novel1 << endl;
    cout << novel2 << endl;

    if (novel1 < novel2) {
        cout << novel1.getTitle() << " has a lower average rating than " << novel2.getTitle() << endl;
    } else {
        cout << novel1.getTitle() << " has a higher average rating than " << novel2.getTitle() << endl;
    }
}
