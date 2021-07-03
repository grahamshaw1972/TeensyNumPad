/* Copyright 2021 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "kb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_LPRN, KC_RPRN, KC_PSLS, KC_PAST,
        KC_P7,   KC_P8,   KC_P9,   KC_PMNS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,            KC_PDOT
    ),

};

unsigned char amiga_keycode_table[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
		AKC_PLP,  AKC_PRP,   AKC_PDV,  AKC_PML,
		AKC_P7,   AKC_P8,    AKC_P9,   AKC_PMN,
		AKC_P4,   AKC_P5,    AKC_P6,   AKC_PPL,
		AKC_P1,   AKC_P2,    AKC_P3,   AKC_PEN,
		AKC_P0,              AKC_PDT
    );
