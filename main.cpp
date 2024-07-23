#include "CardDrawer.h"
#include <vector>

int main() {
    using namespace CardDrawer;

    // Example usage for a single card
    std::cout << "Single card example:" << std::endl;
    Card ace_of_spades("Ace", 'A', 'S', 3, false);  // Rounded design
    draw_card(ace_of_spades);
    
    std::cout << "\nTurned card example:" << std::endl;
    Card turned_card_minimalist("Turned", ' ', ' ', 1, true);  // Turned card with Minimalist design
    Card turned_card_ornate("Turned", ' ', ' ', 2, true);      // Turned card with Ornate design
    Card turned_card_rounded("Turned", ' ', ' ', 3, true);     // Turned card with Rounded design
    Card turned_card_dotted("Turned", ' ', ' ', 4, true);      // Turned card with Dotted design
    Card turned_card_slashed("Turned", ' ', ' ', 6, true);     // Turned card with Slashed design
    
    draw_card(turned_card_minimalist);
    draw_card(turned_card_ornate);
    draw_card(turned_card_rounded);
    draw_card(turned_card_dotted);
    draw_card(turned_card_slashed);
    
    std::cout << "\nMultiple cards example:" << std::endl;
    // Example usage for multiple cards
    std::vector<Card> multiple_cards;
    multiple_cards.emplace_back("Ace", 'A', 'H', 1, false);
    multiple_cards.emplace_back("King", 'K', 'S', 2, false);
    multiple_cards.emplace_back("Queen", 'Q', 'D', 3, false);
    multiple_cards.emplace_back("Jack", 'J', 'C', 4, false);
    multiple_cards.emplace_back("Ten", 'T', 'H', 6, false);
    
    draw_multiple_cards(multiple_cards);

    return 0;
}
