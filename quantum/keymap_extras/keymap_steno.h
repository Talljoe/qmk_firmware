/* Copyright 2017 Joseph Wasson
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
#ifndef KEYMAP_STENO_H
#define KEYMAP_STENO_H

#include "keymap.h"

#define STENO(kc) (QK_STENO | (kc & 0xff))

// TxBolt Codes
#define TXB_S_L 0b00000001
#define TXB_T_L 0b00000010
#define TXB_K_L 0b00000100
#define TXB_P_L 0b00001000
#define TXB_W_L 0b00010000
#define TXB_H_L 0b00100000
#define TXB_R_L 0b01000001
#define TXB_A_L 0b01000010
#define TXB_O_L 0b01000100
#define TXB_STR 0b01001000
#define TXB_E_R 0b01010000
#define TXB_U_R 0b01100000
#define TXB_F_R 0b10000001
#define TXB_R_R 0b10000010
#define TXB_P_R 0b10000100
#define TXB_B_R 0b10001000
#define TXB_L_R 0b10010000
#define TXB_G_R 0b10100000
#define TXB_T_R 0b11000001
#define TXB_S_R 0b11000010
#define TXB_D_R 0b11000100
#define TXB_Z_R 0b11001000
#define TXB_NUM 0b11010000

#define TXB_GRP0 0b00000000
#define TXB_GRP1 0b01000000
#define TXB_GRP2 0b10000000
#define TXB_GRP3 0b11000000
#define TXB_GRPMASK 0b11000000

#define TXB_GET_GROUP(code) ((code & TXB_GRPMASK) >> 6)

#define STN_SL   STENO(TXB_S_L)
#define STN_TL   STENO(TXB_T_L)
#define STN_KL   STENO(TXB_K_L)
#define STN_PL   STENO(TXB_P_L)
#define STN_WL   STENO(TXB_W_L)
#define STN_HL   STENO(TXB_H_L)
#define STN_RL   STENO(TXB_R_L)

#define STN_STR  STENO(TXB_STR)
#define STN_FR   STENO(TXB_R_R)
#define STN_RR   STENO(TXB_R_R)
#define STN_PR   STENO(TXB_P_R)
#define STN_BR   STENO(TXB_B_R)
#define STN_LR   STENO(TXB_L_R)
#define STN_GR   STENO(TXB_G_R)
#define STN_TR   STENO(TXB_T_R)
#define STN_SR   STENO(TXB_S_R)
#define STN_DR   STENO(TXB_D_R)
#define STN_ZR   STENO(TXB_Z_R)

#define STN_A    STENO(TXB_A_L)
#define STN_O    STENO(TXB_O_L)
#define STN_E    STENO(TXB_E_R)
#define STN_U    STENO(TXB_U_R)
#define STN_NUM  STENO(TXB_NUM)

#endif
