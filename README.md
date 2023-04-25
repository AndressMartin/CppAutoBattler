## Auto Battler RPG Test
This application is an auto-battler RPG with a grid with cells/tiles/boxes organized as a matrix. It is meant as a simple C++ test for practice. 

### Grid
The grid has no min or max values. Please don’t insert negative or absurd numbers.

With that said, it is dynamic. The user generates the size of grid that they want. Some character classes are stronger in big arenas, others in smaller arenas.

### Turn-based Actions
#### Movement
Happens automatically when attacking is not possible.

#### Attacking
When in range, will choose to attack OR use an ability. Each character has a different chance.

### Special Abilities
Each character class has two special abilities, with the exception of the Paladin, who has three.

Character abilities have a chance to proc instead of a regular Attack. That chance changes from class to class. The Cleric, for example, has the highest chance to use abilities compared to other classes.

### Status Effects
Each character has one status effect that can be applied. 

A character can not apply a status effect to an opponent that is already undergoing another status effect. The exception is the Mage class, who applies burning and frozen at the same time. Don’t ask why.

Most status effects last a couple of rounds or have a chance of leaving. The Cleric’s Cursed status doesn’t. The only way to get rid of it is with the Paladin’s exclusive Clear Ailments action.

Here’s a rundown of the status effects and what they do:

### Further Development
The game can be expanded with new character classes, abilities, and status effects. Additional features can include an AI-controlled enemy team, more manipulation of action points and grid positioning.

I would also work on some of the initial parts of the code, where some copy and pasting can be improved by smart pointers, and some classes can be simplified with smart refactoring. Especially the Character class could be simplified and be made more secure.

### Challenges During Development
I have a good background in Competitive Programming with C++ but it’s been a while since I’ve built a program application with the language. I ended up re-learning a bunch of things, and therefore the first two days were spent mostly reading, learning and researching.

My resources for development were:

- A Tour of C++, Third Edition book by Bjarne Stroustrup.
- cppreference.com, https://cplusplus.com/reference/. Both websites are recommended by Bjarne Stroustrup and were extremely valuable.
