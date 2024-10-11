#include <iostream> 
#include <string> 

using namespace std;

// Class RewardsCredit (inherits from CreditAccount)
class RewardsCredit : public CreditAccount {
protected:
    //Datamembers. 
    int points;
    double points_rate;
    int points_limit;

public:
    // Default constructor
    RewardsCredit() : CreditAccount(), points(0), points_rate(0.0), points_limit(0) {}

    // Parameterized constructor
    RewardsCredit(double bal, double funds, double limit, double rate, int pts, double pts_rate, int pts_limit)
        : CreditAccount(bal, funds, limit, rate), points(pts), points_rate(pts_rate), points_limit(pts_limit) {}

    //Adding points on the transaction.
    void add_points(double amount) {
        points += static_cast<int>(amount * points_rate);
    }

    // Redeem points.
    void redeem_points(int pts) {
        if (pts <= points) {
            points -= pts;
            cout << "Redeemed " << pts << "points\n";

        }else{

            cout << "Not enough points to reddem\n";

        }
    };

}
