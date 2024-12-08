/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H

// TEMPLATE
/*[layer] = LAYOUT_split_3x6_3(*/
/*//,-----------------------------------------------------.                    ,-----------------------------------------------------.*/
/*  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
/*//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/
/*  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
/*//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/
/*  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
/*//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|*/
/*                                      KC_LSFT, _______,  KC_SPC,   KC_BSPC,  _______, KC_RALT*/
/*                                  //`--------------------------'  `--------------------------'*/
/*),*/

enum layers {
    _BASE,
    _NUMBER,
    _SYMBOL,
    _NAVIGATION,
    _MOUSE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_LGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       KC_LSFT, MO(_NUMBER), KC_SPC,    KC_BSPC, MO(_SYMBOL), KC_RALT
                                    //`----------------------------'  `------------------------------'
  ),

    [_NUMBER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------.                    ,-----------------------------------------------------.
              KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,   KC_F6,                      XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9,  KC_EQL, KC_PENT,
  //|--------------+--------------+--------------+--------------+--------------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_RALT), XXXXXXX,                      KC_PPLS, KC_KP_4, KC_KP_5, KC_KP_6, KC_PAST, XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------|                    |--------+--------+--------+--------+--------+--------|
             KC_F12,        KC_F11,        KC_F10,         KC_F9,         KC_F8,   KC_F7,                      KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_PSLS, XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                        KC_LSFT, _______,  KC_SPC,   KC_BSPC,  MO(_NAVIGATION), KC_KP_0
                                                                    //`--------------------------'  `----------------------------------'
  ),

    [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------.
      KC_TILD, XXXXXXX, KC_LABK, KC_RABK, KC_QUOT, KC_DQUO,                      KC_AMPR, KC_LBRC, KC_RBRC,  KC_COLN, KC_PERC,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+---------+--------+--------|
       KC_GRV, KC_EXLM, KC_PMNS, KC_PLUS,  KC_EQL, KC_HASH,                      KC_PIPE, KC_LPRN, KC_RPRN,  KC_SCLN, KC_QUES, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+---------+--------+--------|
      XXXXXXX, KC_CIRC, KC_PSLS, KC_ASTR, KC_BSLS, XXXXXXX,                      KC_UNDS, KC_LCBR, KC_RCBR,   KC_DLR,   KC_AT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+---------+--------+--------|
                               MO(_MOUSE), MO(_NAVIGATION),  KC_SPC,   KC_BSPC,  _______, KC_RALT
                            //`------------------------------------'  `--------------------------'
  ),


    [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------------.                    ,-----------------------------------------------------.
            XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), OSM(MOD_LGUI), OSM(MOD_RALT), XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_PSCR, XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------|                    |--------+--------+--------+--------+--------+--------|
            XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX,                       KC_INS,  KC_DEL, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX,
  //|--------------+--------------+--------------+--------------+--------------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                                        KC_LSFT, _______,  KC_SPC,   KC_BSPC,  MO(_NAVIGATION), KC_RALT
                                                                    //`--------------------------'  `----------------------------------'
  ),

    [_MOUSE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, MS_ACL1, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, XXXXXXX,                      MS_LEFT, MS_DOWN,   MS_UP, MS_RGHT, MS_ACL0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, MS_BTN1, MS_BTN2, MS_BTN3, MS_ACL2, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, XXXXXXX, XXXXXXX,   XXXXXXX,  _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

