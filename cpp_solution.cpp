#include <iostream>
#include <vector>
using namespace std;

// Function to determine if Abhimanyu can cross the Chakravyuha
bool can_cross_chakravyuha(int p, vector<int>& k, int a, int b) {
    int original_p = p;  // Store the original power for recharging
    int curr_a = a;      // Current skips available
    int curr_b = b;      // Current recharges available
    
    // Lambda function to handle the attack from each enemy
    auto handle_enemy_attack = [&](int& p, int enemy_power, int curr_level, int& curr_a, int& curr_b) -> pair<int, bool> {
        if (p >= enemy_power) { // If current power is sufficient to defeat the enemy
            p -= enemy_power;  // Decrease power by enemy power
        } else { // If current power is not sufficient
            if (curr_b > 0) { // If recharges are available
                if (original_p >= enemy_power) { // If original power is sufficient to defeat the enemy
                    curr_b -= 1;  // Use one recharge
                    p = original_p;  // Recharge power to original
                    p -= enemy_power;  // Decrease power by enemy power

                    // Special case for 3rd and 7th enemy circle
                    if (curr_level == 2 || curr_level == 6) {
                        k[curr_level + 1] += (k[curr_level] / 2);
                    }
                } else { // If original power is not sufficient
                    if (curr_a > 0) { // If skips are available
                        curr_a -= 1;  // Use one skip

                        // Special case for 3rd and 7th enemy circle
                        if (curr_level == 2 || curr_level == 6) {
                            k[curr_level + 1] += k[curr_level];
                        }
                    } else {
                        return make_pair(p, false); // Neither skips nor recharges are available, return failure
                    }
                }
            } else { // If no recharges are available
                if (curr_a > 0) { // If skips are available
                    curr_a -= 1;  // Use one skip

                    // Special case for 3rd and 7th enemy circle
                    if (curr_level == 2 || curr_level == 6) {
                        k[curr_level + 1] += k[curr_level];
                    }
                } else {
                    return make_pair(p, false); // Neither skips nor recharges are available, return failure
                }
            }
        }
        return make_pair(p, true); // Successfully handled enemy attack
    };

    // Iterate through all enemies
    for (int i = 0; i < k.size(); ++i) {
        // Handle the attack from the current enemy
        pair<int, bool> result = handle_enemy_attack(p, k[i], i, curr_a, curr_b);
        p = result.first; // Update power
        if (!result.second) { // If handling the attack failed
            return false; // Abhimanyu cannot cross the Chakravyuha
        }
    }
    return true; // Abhimanyu successfully crosses the Chakravyuha
}

int main() {
    while (true) {
        // Take inputs from the user
        int p;
        cout << "Enter Abhimanyu's initial power: ";
        cin >> p;

        vector<int> k(11); // Vector to store the power levels of the 11 enemies
        cout << "Enter the power levels of the 11 enemies (space-separated): ";
        for (int& power : k) {
            cin >> power;
        }

        int a, b;
        cout << "Enter the number of skips available: ";
        cin >> a;
        cout << "Enter the number of recharges available: ";
        cin >> b;

        // Ensure the user entered exactly 11 power levels
        if (k.size() != 11) {
            cout << "\nError: Please enter exactly 11 enemy power levels.\n" << endl;
        } else {
            // Call the function with the provided inputs and print the result
            bool result = can_cross_chakravyuha(p, k, a, b);
            cout << "\nCan Abhimanyu cross the Chakravyuha? " << (result ? "Yes\n" : "No\n") << endl;
        }

        // Ask if the user wants to continue
        char continue_input;
        cout << "Do you want to input another scenario? (y(Yes)/n(No)): ";
        cin >> continue_input;
        cout << endl;
        if (continue_input != 'y') {
            cout << "Thank you for playing !" << endl;
            break;
        }
    }

    return 0;
}
