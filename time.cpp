#include <iostream>
#include <cmath>
#include <compare>

class Time {
    double jdInt_;
    double jdFrac_;

public :
    double jdInt () const noexcept { return jdInt_;}
    double jdPart () const noexcept { return jdFrac_;}
    double jd () const noexcept {return jdInt_ + jdFrac_;}
    double mjd () const noexcept { return jd() - 2400000.5;}


    Time(double jd1 = 0, double jd2 = 0) noexcept {

        if (std::floor(jd1)==jd1 && jd2>=0 && jd2<1){
            jdInt_ = jd1;
            jdFrac_ = jd2;
        }
        else{
            jdInt_ = std::floor(jd1+jd2);
            jdFrac_ = jd1+jd2 - jdInt_;
        }
    };


    Time static fromJD(double jd) noexcept{
        double int_part= std::floor(jd);
        return Time(int_part, (jd - int_part));
    };
    Time static fromMJD(double mjd) noexcept{
        return Time::fromJD(mjd + 2400000.5);
    };
    Time static fromCalendar(int year, ...) ;

    auto operator<=>(const Time& other) const noexcept = default;

};

double operator-(const Time& first, const Time& second) noexcept{
    return (first.jdInt() - second.jdInt()) + (first.jdPart() - second.jdPart()); 
};
Time operator-(const Time& time, double secs) noexcept{
    return Time::fromJD(time.jd() - secs/86400);
};
Time operator+(const Time& time, double secs) noexcept{
    return Time::fromJD(time.jd() + secs/86400);
};

int main()
{
    return 0;
}