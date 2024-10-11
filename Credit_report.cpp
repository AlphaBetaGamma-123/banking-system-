#include <iostream> 
#include <string> 

using namespace std;

// Class CreditReport
class CreditReport {
protected:
    int score;
    int report_id;
    int num_repayments_missed;
    int date;
    double income_past_year;
    double expenses_past_year;

public:
    // Default constructor
    CreditReport() : score(0), report_id(0), num_repayments_missed(0), date(0), income_past_year(0.0), expenses_past_year(0.0) {}

    // Parameterized constructor
    CreditReport(int s, int rep_id, int missed, int d, double income, double expenses)
        : score(s), report_id(rep_id), num_repayments_missed(missed), date(d), income_past_year(income), expenses_past_year(expenses) {}

   //Placeholder methods. 
   //vector<int>get_pervious_scores() { return {}; }  // Placeholder
    // vector<int> get_previous_reports() { return {}; } 
    // vector<int> get_user_accounts() { return {}; }

       void display_credit_report() const {
        cout << "Credit Report ID: " << report_id << "\n";
        cout << "Credit Score: " << score << "\n";
        cout << "Repayments Missed: " << num_repayments_missed << "\n";
        cout << "Income (Past Year): " << income_past_year << "\n";
        cout << "Expenses (Past Year): " << expenses_past_year << "\n";
        cout << "Report Date: " << std::ctime(&date);
    }
    
};