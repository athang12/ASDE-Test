<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Best-README-Template</h3>

  <p align="center">
    An awesome README template to jumpstart your projects!
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#introduction-to-problem">Introduction to Problem</a>
    </li>
    <li><a href="#problem-analysis-and-simplification">Problem Analysis and Simplification</a></li>
    <li><a href="#designing-algorithm">Designing Algorithm</a></li>
    <li><a href="#implementation">Implementation</a></li>
    <li><a href="#algorithm-analysis">Algorithm Analysis</a></li>
    <li>
      <a href="#documentation">Documentation</a>
      <ul>
        <li><a href="#assumptions">Assumptions</a></li>
      </ul>
    </li>
    <li><a href ="#contact-and-acknowledgement">Contact and Acknowledgement</a></li>
  </ol>
</details>



<!-- Introduction to Problem -->
## Introduction to Problem
Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back

Images will go here

<ul>
  <li>Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11 powers Abhmanyu start from the innermost circle with p power Abhimanyu has a boon to skip fighting enemy a times </li>
  <li>Abhmanyu can recharge himself with power b times </li>
  <li>Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. </li>
  <li>If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle</li>
  <li>k3 and k7 enemies are endured with power to regenerate themselves once with half of their initial power and can attack Abhimanyu from behind if he is battling in iteratively next circle </li>
</ul>  
<p align="right">(<a href="#readme-top">back to top</a>)</p>



## Problem Analysis and Simplification

### Simplifying Problem Statement
<ul>
  <li>Abhimanyu needs to cross 11 circles, each guarded by an enemy.</li>
  <li>Each enemy has a power value k1, k2, ..., k11.</li>
  <li>Abhimanyu starts with a certain power p.</li>
  <li>Abhimanyu can skip fighting a times.</li>
  <li>Abhimanyu can recharge his power to the original value b times.</li>
  <li>Battling an enemy reduces Abhimanyu's power by the enemy's power.</li>
  <li>If Abhimanyu's power is less than the enemy's power and he can't skip or recharge, he loses.</li>
</ul>

### Assumptions
<ol>
  <li>Meaning of word <strong>Recharge</strong> <br/> During the design of this algorithm, the term "Recharge" is defined as restoring Abhimanyu's power to its original level, regardless of his current power state.<br/>Recharging Abhimanyu when his power is already at its initial level is unnecessary.</li>
  <li>The enemies in circles k3 and k7 deploy their optimal power strategically. If Abhimanyu defeats the enemies in these circles, they will regenerate with half of their initial power and can attack Abhimanyu from behind. Conversely, if Abhimanyu skips the k3 and k7 circles using his boon, these enemies will attack him from behind with their full initial power.</li>
</ol>

### Final Problem Statement
<ul>
  <li>Abhimanyu needs to cross 11 circles, each guarded by an enemy.</li>
  <li>Each enemy has a power value k1, k2, ..., k11. enemy circles k4 and k8 get additional power of k3 or k3/2 and k7 or k7/2 respectively based on the situation</li>
  <li>Abhimanyu starts with a certain power p.</li>
  <li>Abhimanyu can skip fighting a times.</li>
  <li>Abhimanyu can recharge his power to the original value b times.</li>
  <li>Battling an enemy reduces Abhimanyu's power by the enemy's power.</li>
  <li>If Abhimanyu's power is less than the enemy's power and he can't skip or recharge, he loses.</li>
</ul>
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- Designing Algorithm -->
## Designing Algorithm

Add workflow image here

1. Initialization:
- Variables Initialization: Store Abhimanyu's initial power, the current number of skips (`curr_a`), and recharges (`curr_b`).
- Function Definitions: Define an inner function `handle_enemy_attack` to handle the logic of attacking or skipping an enemy.

2. Handle Enemy Attack:
- Check Abhimanyu's Power: If Abhimanyu's current power (`p`) is greater than or equal to the enemy's power, deduct the enemy's power from Abhimanyu's power.
- Insufficient Power Handling:
  - Recharge Available: If Abhimanyu has recharges (`curr_b > 0`) and if recharging would provide enough power to defeat the enemy, perform the recharge.
    - Special rule: If the enemy is at level 2 or 6, increase the power of the next enemy by half of the current enemy's power.
  - No Recharge Available, Skip Available: If there are no recharges left but skips are available (`curr_a > 0`), skip the current enemy.
    - Special rule: If the enemy is at level 2 or 6, increase the power of the next enemy by the current enemy's power.
  - No Recharge or Skip Available: If neither recharges nor skips are available, return `False`.

3. Loop Through Enemies:
- Iterate Through Enemies: For each enemy in the list of enemies' power levels, apply the logic defined in the `handle_enemy_attack` function.
- Check Success: If at any point Abhimanyu cannot defeat or skip an enemy, return `False`.
- Return Result: If all enemies are defeated or skipped successfully, return `True`.

4. User Interaction:
- Continuous Input: Continuously prompt the user for input (initial power, enemies' power levels, number of skips, and recharges).
- Input Validation: Validate the input to ensure exactly 11 enemies' power levels are provided.
- Display Results: Display the result for each input scenario.
- Continue or Exit: Ask if the user wants to continue or exit the program.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- Implementation -->
## Implementation

Write code here 

<details>
<summary>Python Code</summary>

```python
def function_name():
    # Python code here
    pass
```
</details>
<details>
<summary>JavaScript Code</summary>
```javascript
Copy code
function functionName() {
    // JavaScript code here
}
```
</details>
<details>
<summary>C++ Code</summary>
```cpp
Copy code
void functionName() {
    // C++ code here
}
  ```
</details>


_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!--Algorithm Analysis -->
## Algorithm Analysis

- [x] Add Changelog
- [x] Add back to top links
- [ ] Add Additional Templates w/ Examples
- [ ] Add "components" document to easily copy & paste sections of the readme
- [ ] Multi-language Support
    - [ ] Chinese
    - [ ] Spanish

See the [open issues](https://github.com/othneildrew/Best-README-Template/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- Documentation -->
## Documentation

Docu

### Assumptions
<ol>
  <li>Meaning of word <strong>Recharge</strong> <br/> During the design of this algorithm, the term "Recharge" is defined as restoring Abhimanyu's power to its original level, regardless of his current power state.<br/>Recharging Abhimanyu when his power is already at its initial level is unnecessary.</li>
  <li>The enemies in circles k3 and k7 deploy their optimal power strategically. If Abhimanyu defeats the enemies in these circles, they will regenerate with half of their initial power and can attack Abhimanyu from behind. Conversely, if Abhimanyu skips the k3 and k7 circles using his boon, these enemies will attack him from behind with their full initial power.</li>
</ol>

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- Contact and Acknowledgement -->
## Contact and Acknowledgement

Your Name - [@your_twitter](https://twitter.com/your_username) - email@example.com

Project Link: [https://github.com/your_username/repo_name](https://github.com/your_username/repo_name)

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com 
