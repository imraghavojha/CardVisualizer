#include "CardDrawer.h"
#include <algorithm>

namespace CardDrawer {

std::vector<std::string> get_card_lines(const Card& card) {
    std::vector<std::string> card_lines(7);
    std::string symbol_str(1, card.symbol);
    std::string design_str(1, card.design);
    
    std::string display_name = card.name;
    if (display_name.length() > 5) {
        display_name = display_name.substr(0, 5);
    }
    
    if (card.turned) {
        if (card.variation == 1) { // Minimalist
            card_lines = {
                "+-------+",
                "|       |",
                "|       |",
                "|       |",
                "|       |",
                "|       |",
                "+-------+"
            };
        } else if (card.variation == 2) { // Ornate
            card_lines = {
                ".~~~~~~~.",
                "{       }",
                "{       }",
                "{       }",
                "{       }",
                "{       }",
                "'~~~~~~~'"
            };
        } else if (card.variation == 3) { // Rounded
            card_lines = {
                ".-------.",
                "(       )",
                "(       )",
                "(       )",
                "(       )",
                "(       )",
                "'-------'"
            };
        } else if (card.variation == 4) { // Dotted
            card_lines = {
                "* * * * *",
                "*       *",
                "*       *",
                "*       *",
                "*       *",
                "*       *",
                "* * * * *"
            };
        } else if (card.variation == 6) { // Slashed
            card_lines = {
                "/-------\\",
                "\\       /",
                "/       \\",
                "\\       /",
                "/       \\",
                "\\       /",
                "/-------\\"
            };
        }
    } else {
        if (card.variation == 1) { // Minimalist
            card_lines = {
                "+-------+",
                "|" + symbol_str + "      |",
                "|       |",
                "|   " + design_str + "   |",
                "|       |",
                "|      " + symbol_str + "|",
                "+-------+"
            };
        } else if (card.variation == 2) { // Ornate
            card_lines = {
                ".~~~~~~~.",
                "{" + symbol_str + "     " + symbol_str + "}",
                "{  " + design_str + " " + design_str + "  }",
                "{  " + design_str + " " + design_str + "  }",
                "{  " + design_str + " " + design_str + "  }",
                "{" + symbol_str + "     " + symbol_str + "}",
                "'~~~~~~~'"
            };
        } else if (card.variation == 3) { // Rounded
            card_lines = {
                ".-------.",
                "(" + symbol_str + "      )",
                "(       )",
                "(   " + design_str + "   )",
                "(       )",
                "(      " + symbol_str + ")",
                "'-------'"
            };
        } else if (card.variation == 4) { // Dotted
            card_lines = {
                "* * * * *",
                "* " + symbol_str + "     *",
                "*       *",
                "*   " + design_str + "   *",
                "*       *",
                "*     " + symbol_str + " *",
                "* * * * *"
            };
        } else if (card.variation == 6) { // Slashed
            card_lines = {
                "/-------\\",
                "\\" + symbol_str + "     /",
                "/       \\",
                "\\   " + design_str + "   /",
                "/       \\",
                "\\     " + symbol_str + "/",
                "/-------\\"
            };
        }

        // Center the name
        int available_space = 7;
        int name_start = std::max(0, (available_space - (int)display_name.length()) / 2);
        std::string centered_name = std::string(name_start, ' ') + display_name;
        centered_name = centered_name + std::string(available_space - centered_name.length(), ' ');
        
        card_lines[3] = card_lines[3].substr(0, 1) + centered_name + card_lines[3].substr(8);
    }
    
    return card_lines;
}

void draw_card(const Card& card) {
    std::vector<std::string> card_lines = get_card_lines(card);
    for (const auto& line : card_lines) {
        std::cout << line << std::endl;
    }
}

void draw_multiple_cards(const std::vector<Card>& cards) {
    if (cards.empty()) return;

    std::vector<std::vector<std::string>> all_card_lines;
    for (const auto& card : cards) {
        all_card_lines.push_back(get_card_lines(card));
    }

    for (size_t i = 0; i < all_card_lines[0].size(); ++i) {
        for (const auto& card_lines : all_card_lines) {
            std::cout << card_lines[i] << "  ";  // Note the extra space here
        }
        std::cout << std::endl;
    }
}

} // namespace CardDrawer
