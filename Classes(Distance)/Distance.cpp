
#include "Distance.h"

Distance::Distance() {
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    feet = ft;
    inches = in;
    init();
}

Distance::Distance(double in) {
    feet = 0;
    inches = in;
    init();

}

unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const {
    return inches;
}

double Distance::distanceInInches() const {
    double in;
    in = inches + (feet * 12.0);
    return in;
}

double Distance::distanceInFeet() const {
    double ft;
    ft = inches / 12.0;
    ft = (double)feet + ft;
    return ft;
}

double Distance::distanceInMeters() const {
    double in;
    double meters;
    in = inches + (feet * 12.0);
    meters = in * 0.0254;
    return meters;
}

Distance Distance::operator+(const Distance &rhs) const {
    return Distance(distanceInInches() + rhs.distanceInInches());
}

Distance Distance::operator-(const Distance &rhs) const {
    return Distance(distanceInInches() - rhs.distanceInInches());
}

ostream & operator<<(ostream &out, const Distance &rhs) {
    out << rhs.getFeet() << "\'" << " " << rhs.getInches() << "\"";
    return out;
}

void Distance::init() {
    int inToFt;
    if (inches < 0) {
        inches = inches * -1;
    }
    if (inches >= 12) {
        inToFt = (inches / 12);
        feet = feet + inToFt;
        inches = inches - (12 * inToFt);
    }
}
