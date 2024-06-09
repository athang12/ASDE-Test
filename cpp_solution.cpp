#include <iostream>
#include <vector>
using namespace std;

// Function to determine if Abhimanyu can cross the Chakravyuha
bool can_cross_chakravyuha(int p, vector<int>& k, int a, int b) {
    int original_p = p;  // Store the original power for recharging
    int curr_a = a;      // Current number of skips available
    int curr_b = b;      // Current number of recharges available
    
    // Lambda function to handle the attack of each enemy
    auto handle_enemy_attack = [&](int& p, int enemy_power, int curr_level, int& curr_a, int& curr_b) -> pair<int, bool> {
        if (p >= enemy_power) {
            // If current power is sufficient to defeat the enemy
            p -= enemy_power;
        } else {
            // If current power is not sufficient to defeat the enemy
            if (curr_b > 0) {
                // If recharges are available
                if (original_p >= enemy_power) {
                    // If original power is sufficient to defeat the enemy after recharging
                    curr_b -= 1;   // Use one recharge
                    p = original_p; // Recharge power
                    p -= enemy_power; // Defeat the enemy

                    // Check for special cases of the 3rd and 7th enemy circle
                    if (curr_level == 2 || curr_level == 6) {
                        k[curr_level + 1] += (k[curr_level] / 2); // Increase next enemy's power
                    }
                } else {
                    // If original power is not sufficient, check for skips
                    if (curr_a > 0) {
                        curr_a -= 1; // Use one skip
                        
                        // Special cases for 3rd and 7th enemy circle
                        if (curr_level == 2 || curr_level == 6) {
                            k[curr_level + 1] += k[curr_level]; // Increase next enemy's power
                        }
                    } else {
                        // If no skips left, Abhimanyu fails
                        return make_pair(p, false);
                    }
                }
            } else {
                // If no recharges are available, check for skips
                if (curr_a > 0) {
                    curr_a -= 1; // Use one skip
                    
                    // Special cases for 3rd and 7th enemy circle
                    if (curr_level == 2 || curr_level == 6) {
                        k[curr_level + 1] += k[curr_level]; // Increase next enemy's power
                    }
                } else {
                    // If no skips left, Abhimanyu fails
                    return make_pair(p, false);
                }
            }
        }
        return make_pair(p, true);
    };

    // Loop through all enemies
    for (int i = 0; i < k.size(); ++i) {
        pair<int, bool> result = handle_enemy_attack(p, k[i], i, curr_a, curr_b);
        p = result.first;
        if (!result.second) {
            // If Abhimanyu fails, print the level and power shortage
            cout << "\nAbhimanyu fails at level " << i + 1 << " with " << k[i] - p << " power short." << endl;
            return false;
        }
    }
    return true;
}

int main() {
    while (true) {
        // Take inputs from the user
        int p;
        cout << "Enter Abhimanyu's initial power: ";
        cin >> p;

        vector<int> k(11);
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
