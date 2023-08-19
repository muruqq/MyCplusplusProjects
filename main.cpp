#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Movie {
public:
    std::string title;
    std::string genre;
    int releaseYear;

    Movie(const std::string& title, const std::string& genre, int releaseYear)
        : title(title), genre(genre), releaseYear(releaseYear) {}
};

class User {
public:
    int userID;
    std::unordered_map<std::string, double> movieRatings;

    User(int userID) : userID(userID) {}
};

class MovieRecommendationSystem {
private:
    std::vector<Movie> movieDatabase;
    std::vector<User> userDatabase;

public:
    // Function to add movies to the database
    void addMovie(const std::string& title, const std::string& genre, int releaseYear) {
        movieDatabase.emplace_back(title, genre, releaseYear);
    }

    // Function to add users to the database
    void addUser(int userID) {
        userDatabase.emplace_back(userID);
    }

    // Function to view all movies in the database
    void viewAllMovies() {
        std::cout << "Movies in the Database:\n";
        for (const auto& movie : movieDatabase) {
            std::cout << "- " << movie.title << " (Genre: " << movie.genre << ", Year: " << movie.releaseYear << ")\n";
        }
    }

    // Function to rate a movie
    void rateMovie(int userID) {
        std::cout << "Enter movie title: ";
        std::string title;
        std::cin.ignore();
        std::getline(std::cin, title);

        auto userIt = std::find_if(userDatabase.begin(), userDatabase.end(), [userID](const User& user) {
            return user.userID == userID;
        });

        if (userIt != userDatabase.end()) {
            std::cout << "Enter your rating (1 to 5 stars): ";
            double rating;
            std::cin >> rating;

            userIt->movieRatings[title] = rating;
            std::cout << "Rating successfully recorded!\n";
        } else {
            std::cout << "User not found!\n";
        }
    }

    // Function to view user ratings
    void viewUserRatings(int userID) {
        auto userIt = std::find_if(userDatabase.begin(), userDatabase.end(), [userID](const User& user) {
            return user.userID == userID;
        });

        if (userIt != userDatabase.end()) {
            std::cout << "Your Ratings:\n";
            for (const auto& [title, rating] : userIt->movieRatings) {
                std::cout << "- " << title << ": " << rating << " stars\n";
            }
        } else {
            std::cout << "User not found!\n";
        }
    }

    // Function to get movie recommendations
    void getMovieRecommendations(int userID) {
        auto userIt = std::find_if(userDatabase.begin(), userDatabase.end(), [userID](const User& user) {
            return user.userID == userID;
        });

        if (userIt != userDatabase.end()) {
            std::cout << "Recommended Movies:\n";
            // Dummy recommendations for demonstration purposes
            std::cout << "1. Movie 2 (Genre: Action, Year: 2010)\n";
            std::cout << "2. Movie 3 (Genre: Drama, Year: 2015)\n";
            std::cout << "3. Movie 4 (Genre: Comedy, Year: 2008)\n";
        } else {
            std::cout << "User not found!\n";
        }
    }

    // Function to view top picks
    void viewTopPicks() {
        std::cout << "Top Picks:\n";
        // Dummy top picks for demonstration purposes
        std::cout << "1. Movie 5 (Genre: Sci-Fi, Year: 2022)\n";
        std::cout << "2. Movie 6 (Genre: Fantasy, Year: 2020)\n";
    }

    // Function to run the recommendation system
    void run() {
        int userID;
        std::cout << "Enter your user ID: ";
        std::cin >> userID;

        int choice;
        do {
            std::cout << "\nWelcome to the Movie Recommendation System!\n"
                      << "1. View All Movies\n"
                      << "2. Rate a Movie\n"
                      << "3. View Your Ratings\n"
                      << "4. Get Movie Recommendations\n"
                      << "5. View Top Picks\n"
                      << "6. Exit\n\n"
                      << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    viewAllMovies();
                    break;
                case 2:
                    rateMovie(userID);
                    break;
                case 3:
                    viewUserRatings(userID);
                    break;
                case 4:
                    getMovieRecommendations(userID);
                    break;
                case 5:
                    viewTopPicks();
                    break;
                case 6:
                    std::cout << "\nGoodbye! Have a great day!\n";
                    break;
                default:
                    std::cout << "Invalid choice! Please try again.\n";
            }

        } while (choice != 6);
    }
};

int main() {
    MovieRecommendationSystem system;

    // Dummy movie database and user database for demonstration purposes
    system.addMovie("Movie 1", "Action", 2000);
    system.addMovie("Movie 2", "Comedy", 2010);
    system.addMovie("Movie 3", "Drama", 2015);
    system.addMovie("Movie 4", "Comedy", 2008);
    system.addMovie("Movie 5", "Sci-Fi", 2022);
    // ... Continued from the previous code ...

    system.addMovie("Movie 6", "Fantasy", 2020);

    // Dummy user database for demonstration purposes
    system.addUser(123);
    system.addUser(456);

       system.addUser(123);
    system.addUser(456);

    system.run();

    return 0;
}

