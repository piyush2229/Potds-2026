class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int five = 0, ten = 0;
        
        for (int bill : arr) {
            if (bill == 5) {
                five++;
            } 
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } 
            else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

// Track the number of $5 and $10 bills
// For each $5 bill, increment the count of $5 bills
// For each $10 bill, check if a $5 bill is available for change
// For each $20 bill, prefer giving one $10 and one $5 bill as change
// If not possible, check if three $5 bills are available
// If at any point change cannot be given, return false
// If all customers are served successfully, return true