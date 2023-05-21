#include "board.h"

Board *board_from_fen(char *fenstring)
{
    Board *out = (Board *)malloc(sizeof(Board));
    out->blockers = 0;
    out->boards[0] = 0;
    out->boards[1] = 0;
    out->side_to_move = Black;
    out->half_move_counter = 0;
    out->full_move_counter = 0;
    uint8_t current_board_index = 48;
    uint8_t current_fen_index = 0;
    char current_char = fenstring[current_fen_index];
    while (current_char != ' ')
    {
        switch (current_char)
        {
        case 'x':
            out->boards[0] = out->boards[0] | (1 << current_board_index);
            break;
        case 'o':
            out->boards[1] = out->boards[1] | (1 << current_board_index);
            break;
        case '-':
            out->blockers = out->blockers | (1 << current_board_index);
            break;
        case '/':
            current_board_index -= 15;
            break;
        default:
            uint8_t value = current_char - '0';
            current_fen_index += value;
            break;
        }
        current_fen_index += 1;
        current_char = fenstring[current_fen_index];
    }
    current_fen_index += 1;
    current_char = fenstring[current_fen_index];
    switch (current_char)
    {
    case 'x':
        out->side_to_move = Black;
        break;
    case 'o':
        out->side_to_move = White;
        break;
    default:
        break;
    }
    return out;
}