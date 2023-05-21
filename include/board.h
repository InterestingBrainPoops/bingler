#pragma once
#include <stdint.h>
typedef enum
{
    Black,
    White,
} Side;
typedef struct
{
    uint64_t blockers;
    uint64_t boards[2];
    enum Side side_to_move;
    uint8_t half_move_counter;
    uint32_t full_move_counter;
} Board;

Board *board_from_fen(char *fenstring);