/*
Copyright 2022 aki27

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "quantum.h"

#define LAYOUT( \
      L00,  L01,  L02,  L03,  L04,  L05,  L06,        R00,  R01,  R02,  R03,  R04,  R05,  R06,      \
      L10,  L11,  L12,  L13,  L14,  L15,              R10,  R11,  R12,  R13,  R14,  R15,  R16,  R17,\
      L20,  L21,  L22,  L23,  L24,  L25,              R20,  R21,  R22,  R23,        R25,  R26,  R27,\
      L30,  L31,  L32,  L33,  L34,  L35,  L36,        R30,  R31,  R32,  R33,  R34,  R35,  R36,  R37,\
      L40,  L41,  L42,        L44,  L45,        L46,  R41,  R42,  R43,        R45,  R46,  R47,\
                                          L50,        L51 \
  ) \
  { \
    {  L00,  L01,  L02,  L03,  L04,  L05,  L06,KC_NO}, \
    {  L10,  L11,  L12,  L13,  L14,  L15,KC_NO,KC_NO}, \
    {  L20,  L21,  L22,  L23,  L24,  L25,KC_NO,KC_NO}, \
    {  L30,  L31,  L32,  L33,  L34,  L35,  L36,KC_NO}, \
    {  L40,  L41,  L42,KC_NO,  L44,  L45,  L46,KC_NO}, \
    {  L50,  L51,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO}, \
    {  R00,  R01,  R02,  R03,  R04,  R05,  R06,KC_NO}, \
    {  R10,  R11,  R12,  R13,  R14,  R15,  R16,  R17}, \
    {  R20,  R21,  R22,  R23,KC_NO,  R25,  R26,  R27}, \
    {  R30,  R31,  R32,  R33,  R34,  R35,  R36,  R37}, \
    {KC_NO,  R41,  R42,  R43,KC_NO,  R45,  R46,  R47}, \
    {KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_NO} \
  }


typedef union {
    uint32_t raw;
    struct {
        uint8_t cpi_idx;
        uint8_t scrl_div;
        uint8_t rotation_angle;
        int8_t scrl_inv;
        bool scrl_mode;
        report_mouse_t last_mouse;
    };
} cocot_config_t;



extern cocot_config_t cocot_config;

enum cocot_keycodes {

    COCOT_SAFE_RANGE = SAFE_RANGE,
    CPI_SW,
    SCRL_SW,
    ROT_R15,
    ROT_L15,
    SCRL_MO,
    SCRL_TO,
    SCRL_IN,

};

// #define CPI_SW USER00
// #define SCRL_SW USER01
// #define ROT_R15 USER02
// #define ROT_L15 USER03
// #define SCRL_MO USER04
// #define SCRL_TO USER05
// #define SCRL_IN USER06

bool encoder_update_user(uint8_t index, bool clockwise);
bool encoder_update_kb(uint8_t index, bool clockwise);
bool cocot_get_scroll_mode(void);
void cocot_set_scroll_mode(bool mode);

void render_logo(void);
void oled_write_layer_state(void);
