def can_cross_chakravyuha(p, k, a, b):
    original_p = p  # Store the original power for recharging
    curr_a = a  # Current skips available
    curr_b = b  # Current recharges available

    # Function to handle the attack from each enemy
    def handle_enemy_attack(p, enemy_power, curr_level, curr_a, curr_b):
        if p >= enemy_power:  # If current power is sufficient to defeat the enemy
            p -= enemy_power  # Decrease power by enemy power
        else:  # If current power is not sufficient
            if curr_b > 0:  # If recharges are available
                if original_p >= enemy_power:  # If original power is sufficient to defeat the enemy
                    curr_b -= 1  # Use one recharge
                    p = original_p  # Recharge power to original
                    p -= enemy_power  # Decrease power by enemy power

                    # Special case for 3rd and 7th enemy circle
                    if curr_level == 2 or curr_level == 6:
                        k[curr_level + 1] += (k[curr_level] / 2)
                else:  # If original power is not sufficient
                    if curr_a > 0:  # If skips are available
                        curr_a -= 1  # Use one skip

                        # Special case for 3rd and 7th enemy circle
                        if curr_level == 2 or curr_level == 6:
                            k[curr_level + 1] += k[curr_level]
                    else:
                        return p, False  # Neither skips nor recharges are available, return failure
            else:  # If no recharges are available
                if curr_a > 0:  # If skips are available
                    curr_a -= 1  # Use one skip
                    if curr_level == 2 or curr_level == 6:
                        k[curr_level + 1] += k[curr_level]
                else:
                    return p, False  # Neither skips nor recharges are available, return failure
        return p, True  # Successfully handled enemy attack

    # Iterate through all enemies
    for i in range(len(k)):
        p, success = handle_enemy_attack(p, k[i], i, curr_a, curr_b)
        if not success:  # If handling the attack failed
            print(f"Abhimanyu fails at level {i + 1} with remaining power {p}.\n")
            return False  # Abhimanyu cannot cross the Chakravyuha
    return True  # Abhimanyu successfully crosses the Chakravyuha

while True:
    # Take inputs from the user
    p = int(input("Enter Abhimanyu's initial power: "))
    k = list(map(int, input("Enter the power levels of the 11 enemies (space-separated): ").split()))
    a = int(input("Enter the number of skips available: "))
    b = int(input("Enter the number of recharges available: "))

    # Ensure the user entered exactly 11 power levels
    if len(k) != 11:
        print("\nError: Please enter exactly 11 enemy power levels.\n")
    else:
        # Call the function with the provided inputs and print the result
        result = can_cross_chakravyuha(p, k, a, b)
        print("\nCan Abhimanyu cross the Chakravyuha?", "Yes\n" if result else "No\n")

    # Ask if the user wants to continue
    continue_input = input("Do you want to input another scenario? (y(Yes)/n(No)):").strip().lower()
    print()
    if continue_input != 'y':
        print("Thank you for playing!")
        break
