function canCrossChakravyuha(p, k, a, b) {
    const originalP = p;  // Store the original power for recharging
    let currA = a;
    let currB = b;

    function handleEnemyAttack(p, enemyPower, currLevel, currA, currB) {
        if (p >= enemyPower) {
            p -= enemyPower;
        } else {
            if (currB > 0) {
                if (originalP >= enemyPower) {
                    currB -= 1;
                    p = originalP;
                    p -= enemyPower;

                    if (currLevel === 2 || currLevel === 6) {
                        k[currLevel + 1] += k[currLevel] / 2;
                    }
                } else {
                    if (currA > 0) {
                        currA -= 1;

                        if (currLevel === 2 || currLevel === 6) {
                            k[currLevel + 1] += k[currLevel];
                        }
                    } else {
                        return [p, false];
                    }
                }
            } else {
                if (currA > 0) {
                    currA -= 1;
                    if (currLevel === 2 || currLevel === 6) {
                        k[currLevel + 1] += k[currLevel];
                    }
                } else {
                    return [p, false];
                }
            }
        }
        return [p, true];
    }

    for (let i = 0; i < k.length; i++) {
        const result = handleEnemyAttack(p, k[i], i, currA, currB);
        p = result[0];
        if (!result[1]) {
            return false;
        }
    }
    return true;
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
