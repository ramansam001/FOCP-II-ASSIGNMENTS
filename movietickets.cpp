#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

class MovieTicket {
private:
    struct MovieData {
        int available_tickets = 100;
        set<int> booked_customers;
    };

    unordered_map<int, MovieData> movies;

public:
    bool book(int customerID, int movieID) {
        MovieData& movie = movies[movieID];
        
        // Check if customer already booked or if movie is sold out
        if (movie.booked_customers.find(customerID) != movie.booked_customers.end() || movie.available_tickets <= 0) {
            return false;
        }

        movie.booked_customers.insert(customerID);
        movie.available_tickets--;
        return true;
    }

    bool cancel(int customerID, int movieID) {
        // If movie doesn't exist in map, customer couldn't have booked
        if (movies.find(movieID) == movies.end()) return false;

        MovieData& movie = movies[movieID];
        auto it = movie.booked_customers.find(customerID);

        if (it == movie.booked_customers.end()) {
            return false;
        }

        movie.booked_customers.erase(it);
        movie.available_tickets++;
        return true;
    }

    bool is_booked(int customerID, int movieID) {
        if (movies.find(movieID) == movies.end()) return false;
        
        MovieData& movie = movies[movieID];
        return movie.booked_customers.find(customerID) != movie.booked_customers.end();
    }

    int available_tickets(int movieID) {
        // If movie hasn't been interacted with yet, it has 100 tickets
        if (movies.find(movieID) == movies.end()) return 100;
        return movies[movieID].available_tickets;
    }
};

int main() {
    MovieTicket system;
    int Q;
    if (!(cin >> Q)) return 0;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (system.book(x, y) ? "true" : "false") << endl;
        } 
        else if (query == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (system.cancel(x, y) ? "true" : "false") << endl;
        } 
        else if (query == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (system.is_booked(x, y) ? "true" : "false") << endl;
        } 
        else if (query == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << system.available_tickets(y) << endl;
        }
    }
    return 0;
}