#include <iostream>
#include <string>
using namespace std;

class Hospital {

    string name;
    string location;
    int availableBeds;
    double rating;

public:

    Hospital() {
        name = "Tropinka";
        location = "Kherson";
        availableBeds = 10;
        rating = 4.3;
    }

    Hospital(string name, string location, int availableBeds, double rating) {
        this->name = name;
        this->location = location;
        this->availableBeds = availableBeds;
        this->rating = rating;
    }

    ~Hospital() {
        cout << "Hospital is closed\n";
    }

    void Print() const {
        cout << "Hospital's name: " << name << "\n";
        cout << "Location: " << location << "\n";
        cout << "Total beds: " << availableBeds << "\n";
        cout << "Rating: " << rating << "\n";
    }

    void SetName(const string& name) {
        this->name = name;
    }
    string GetName() const {
        return name;
    }

    void SetLocation(const string& location) {
        this->location = location;
    }
    string GetLocation() const {
        return location;
    }

    void SetAvailableBeds(int availableBeds) {
        if (availableBeds < 0 || availableBeds > 20) throw "ERROR!";
        this->availableBeds = availableBeds;
    }
    int GetAvailableBeds() const {
        return availableBeds;
    }

    void SetRating(double rating) {
        if (rating < 0 || rating > 5) throw "ERROR!";
        this->rating = rating;
    }
    double GetRating() const {
        return rating;
    }

    int operator[](int index) const {
        return availableBeds;
    }

    bool operator<(const Hospital& other) const {
        return availableBeds < other.availableBeds;
    }

    bool operator>(const Hospital& other) const {
        return rating > other.rating;
    }

    istream& operator>>(istream& in) {
        cout << "Enter hospital's name: ";
        in >> name;
        cout << "Enter hospital's location: ";
        in >> location;
        cout << "Enter total beds available: ";
        in >> availableBeds;
        cout << "Enter hospital's rating: ";
        in >> rating;
        return in;
    }

    ostream& operator<<(ostream& out) const {
        out << "Hospital's name: " << name << "\n";
        out << "Location: " << location << "\n";
        out << "Total beds: " << availableBeds << "\n";
        out << "Rating: " << rating << "\n";
        out << "\n================================\n\n";
        return out;
    }
};

void CompareHospital(const Hospital& h1, const Hospital& h2) {
    if (h1.GetAvailableBeds() < h2.GetAvailableBeds()) {
        cout << h2.GetName() << " has more beds than " << h1.GetName() << "\n";
    }
    else if (h1.GetAvailableBeds() > h2.GetAvailableBeds()) {
        cout << h1.GetName() << " has more beds than " << h2.GetName() << "\n";
    }
    else {
        cout << "Both hospitals have the same number of beds" << "\n";
    }

    if (h1.GetRating() < h2.GetRating()) {
        cout << h2.GetName() << " has a higher rating than " << h1.GetName() << "\n";
    }
    else if (h1.GetRating() > h2.GetRating()) {
        cout << h1.GetName() << " has a higher rating than " << h2.GetName() << "\n";
    }
    else {
        cout << "Both hospitals have the same rating" << "\n";
    }
}

int main() {

    Hospital a;
    Hospital b;

    cout << "Enter details for hospital #1:\n";
    a.operator>>(cin);

    cout << "\nEnter details for hospital #2:\n";
    b.operator>>(cin);

    cout << "\nHospital a:\n";
    cout << "________________________________\n\n";
    a.operator<<(cout);

    cout << "Hospital b:\n";
    cout << "________________________________\n\n";
    b.operator<<(cout);

    CompareHospital(a, b);

    cout << "Available beds in hospital a: " << a[0] << "\n";
    cout << "Available beds in hospital b: " << b[0] << "\n";

    return 0;
}
