#ifndef CARDDRAWER_H
#define CARDDRAWER_H

#include <iostream>
#include <string>
#include <vector>

namespace CardDrawer {

struct Card {
    std::string name;
    char symbol;
    char design;
    int variation;
    bool turned;

    Card(const std::string& name_, char symbol_, char design_, int variation_, bool turned_)
        : name(name_), symbol(symbol_), design(design_), variation(variation_), turned(turned_) {}
};

std::vector<std::string> get_card_lines(const Card& card);
void draw_card(const Card& card);
void draw_multiple_cards(const std::vector<Card>& cards);

} // namespace CardDrawer

#endif // CARDDRAWER_H
