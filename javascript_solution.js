function canCrossChakravyuha(p, k, a, b) {
    const originalP = p;  // Store the original power for recharging
    let currA = a;        // Current skips available.
    let currB = b;        // Current recharges available

    // Function to handle the attack from each enemy
    function handleEnemyAttack(p, enemyPower, currLevel, currA, currB) {
        if (p >= enemyPower) { // If current power is sufficient to defeat the enemy
            p -= enemyPower;  // Decrease power by enemy power
        } else { // If current power is not sufficient
            if (currB > 0) { // If recharges are available
                if (originalP >= enemyPower) { // If original power is sufficient to defeat the enemy
                    currB -= 1;  // Use one recharge
                    p = originalP;  // Recharge power to original
                    p -= enemyPower;  // Decrease power by enemy power

                    // Special case for 3rd and 7th enemy circle
                    if (currLevel === 2 || currLevel === 6) {
                        k[currLevel + 1] += k[currLevel] / 2;
                    }
                } else { // If original power is not sufficient
                    if (currA > 0) { // If skips are available
                        currA -= 1;  // Use one skip

                        // Special case for 3rd and 7th enemy circle
                        if (currLevel === 2 || currLevel === 6) {
                            k[currLevel + 1] += k[currLevel];
                        }
                    } else {
                        return [p, false]; // Neither skips nor recharges are available, return failure
                    }
                }
            } else { // If no recharges are available
                if (currA > 0) { // If skips are available
                    currA -= 1;  // Use one skip

                    // Special case for 3rd and 7th enemy circle
                    if (currLevel === 2 || currLevel === 6) {
                        k[currLevel + 1] += k[currLevel];
                    }
                } else {
                    return [p, false]; // Neither skips nor recharges are available, return failure
                }
            }
        }
        return [p, true]; // Successfully handled enemy attack
    }

    // Iterate through all enemies
    for (let i = 0; i < k.length; i++) {
        // Handle the attack from the current enemy
        const result = handleEnemyAttack(p, k[i], i, currA, currB);
        p = result[0]; // Update power
        if (!result[1]) { // If handling the attack failed
            return false; // Abhimanyu cannot cross the Chakravyuha
        }
    }
    return true; // Abhimanyu successfully crosses the Chakravyuha
}

function main() {
    const prompt = require('prompt-sync')({ sigint: true });
    while (true) {
        // Take inputs from the user
        const p = parseInt(prompt("Enter Abhimanyu's initial power: "), 10);
        const k = prompt("Enter the power levels of the 11 enemies (space-separated): ").split(' ').map(Number);
        const a = parseInt(prompt("Enter the number of skips available: "), 10);
        const b = parseInt(prompt("Enter the number of recharges available: "), 10);

        // Ensure the user entered exactly 11 power levels
        if (k.length !== 11) {
            console.log("\nError: Please enter exactly 11 enemy power levels.\n");
        } else {
            // Call the function with the provided inputs and print the result
            const result = canCrossChakravyuha(p, k, a, b);
            console.log("\nCan Abhimanyu cross the Chakravyuha?", result ? "Yes\n" : "No\n");
        }

        // Ask if the user wants to continue
        const continueInput = prompt("Do you want to input another scenario? (y(Yes)/n(No)):").trim().toLowerCase();
        console.log();
        if (continueInput !== 'y') {
            console.log("Thank you for playing !");
            break;
        }
    }
}

main();
