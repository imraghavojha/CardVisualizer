# CardVisualizer 🎴

CardVisualizer is a C++ library for drawing playing cards in various designs directly in the terminal. Easily display individual or multiple cards with different design variations, including options for showing turned (hidden) cards.

## Features ✨

- Draw individual cards with different variations.
- Draw multiple cards side by side.
- Display a turned card with different design variations.

## Installation 🚀

1. **Clone the repository:**

    ```sh
    git clone https://github.com/yourusername/CardVisualizer.git
    cd CardVisualizer
    ```

2. **Compile the library:**

    ```sh
    g++ -std=c++11 -o card_visualizer main.cpp CardDrawer.cpp
    ```

3. **Run the example:**

    ```sh
    ./card_visualizer
    ```

## Usage 🛠️

### Creating a Card

A `Card` object can be created using the constructor:

```cpp
Card card_name("CardName", 'Symbol', 'Design', Variation, Turned);






CardName: The name of the card (e.g., "Ace", "King").
Symbol: The symbol of the card (e.g., 'A' for Ace, 'K' for King).
Design: The design character of the card (e.g., 'S' for Spades).
Variation: The design variation of the card. Possible values are 1 (Minimalist), 2 (Ornate), 3 (Rounded), 4 (Dotted), 6 (Slashed).
Turned: A boolean value indicating whether the card is turned (hidden) or not.
Drawing a Single Card
To draw a single card, use the draw_card function:



#include "CardDrawer.h"

int main() {
    CardDrawer::Card ace_of_spades("Ace", 'A', 'S', 3, false);  // Rounded design
    CardDrawer::draw_card(ace_of_spades);
    return 0;
}


Drawing Multiple Cards
To draw multiple cards side by side, use the draw_multiple_cards function:

cpp
Copy code
#include "CardDrawer.h"
#include <vector>

int main() {
    std::vector<CardDrawer::Card> cards;
    cards.emplace_back("Ace", 'A', 'H', 1, false);
    cards.emplace_back("King", 'K', 'S', 2, false);
    cards.emplace_back("Queen", 'Q', 'D', 3, false);
    cards.emplace_back("Jack", 'J', 'C', 4, false);
    cards.emplace_back("Ten", 'T', 'H', 6, false);

    CardDrawer::draw_multiple_cards(cards);
    return 0;
}
Drawing a Turned Card
To draw a turned card, set the Turned parameter to true:

cpp
Copy code
#include "CardDrawer.h"

int main() {
    CardDrawer::Card turned_card("Turned", ' ', ' ', 1, true);  // Turned card with Minimalist design
    CardDrawer::draw_card(turned_card);
    return 0;
}
License 📜
This project is licensed under the MIT License - see the LICENSE file for details.

sql
Copy code

Feel free to adjust or add any emojis according to your preference!
