def can_cross_chakravyuha(p, k, a, b):
    original_p = p  # Store the original power for recharging
    curr_a = a
    curr_b = b
    
    def handle_enemy_attack(p, enemy_power, curr_level, curr_a, curr_b):
        if p >= enemy_power:
            p -= enemy_power
        else:
            if curr_b > 0:
                if original_p >= enemy_power:
                    curr_b -= 1
                    p = original_p
                    p -= enemy_power

                    if curr_level == 2 or curr_level == 6:
                        k[curr_level+1] += (k[curr_level]/2)
                else:
                    if curr_a > 0:
                        curr_a -= 1

                        if curr_level == 2 or curr_level == 6:
                            k[curr_level+1] += k[curr_level]
                    else:
                        return p, False
            else:
                if curr_a > 0:
                    curr_a -= 1
                    if curr_level == 2 or curr_level == 6:
                        k[curr_level+1] += k[curr_level]
                else:
                    return p, False
        return p, True
    
    for i in range(len(k)):
        p, success = handle_enemy_attack(p, k[i], i, curr_a, curr_b)
        if not success:
            return False
    return True

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
        print("Thank you for playing !")
        break