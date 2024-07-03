#ifdef RGB_MATRIX_ENABLE

RGB_MATRIX_EFFECT(multicolor_map)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define KC_NO 0

enum MAP_COLORS {
    N,
    LB,
    B,
    G,
    R,
    O,
    W,
};

#ifdef KEYBOARD_framework_ansi

/*
Framework 16 ANSI RGB Light physical to LED indices
┌─────────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬───────┬──────┬─────────┐
| 25   23 |  21  |  19  |  18  |  20  |  22  |  24  |  26  |  67  |  74  |  68  | 66 71 |  70  | 72   73 |
|         |      |      |      |      |      |      |      |      |      |      |       |      |         |
├──────┬──┴───┬──┴───┬──┴───┬──┴───┬──┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬───┴──┬────┴─┬────┴─────────┤
|  16  |  15  |  13  |  12  |  11  |  9  |  14  |  10  |  17  |  69  |  61  |  63  |  62  |  64      65  |
|      |      |      |      |      |     |      |      |      |      |      |      |      |              |
├──────┴──┬───┴──┬───┴──┬───┴──┬───┴──┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──────────┤
| 1     0 |  5   |  3   |  2   |  4   |  7   |  8   |  6   |  58  |  59  |  60  |  57  |  54  |    55    |
|         |      |      |      |      |      |      |      |      |      |      |      |      |          |
├─────────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────────┤
| 44 38 42 |  36  |  41  |  37  |  43  |  39  |  40  |  49  |  50  |  51  |  48  |  52  |   53      56   |
|          |      |      |      |      |      |      |      |      |      |      |      |                |
├──────────┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴───┬──┴────────────────┤
|  32  30  28  |  27  |  29  |  31  |  33  |  35  |  76  |  77  |  78  |  75  |  79  |   80  82  83  92  |
|              |      |      |      |      |      |      |      |      |      |      |                   |
├───────┬──────┼──────┼──────┼──────┴──────┴──────┴──────┴──────┼──────┼──────┼──────┴─┬─────────┬───────┤
|       |      |      |      |                                  |      |      |        |   81    |       |
| 34 45 |  93  |  46  |  47  |   94   95   96    85   86   87   |  84  |  88  |  89    ├─────────┤  91   |
|       |      |      |      |                                  |      |      |        |   90    |       |
└───────┴──────┴──────┴──────┴──────────────────────────────────┴──────┴──────┴────────┴─────────┴───────┘

*/

#define KEY_TO_LED( \
    ESC, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, DEL, \
    TIL, N1, N2, N3, N4, N5, N6, N7, N8, N9, N0, NM, NP, BACK, \
    TAB, KQ, KW, KE, KR, KT, KY, KU, KI, KO, KP, BL, BR, BS, \
    CPS, KA, KS, KD, KF, KG, KH, KJ, KK, KL, SC, QU, ENTER, \
    LSH, KZ, KX, KC, KV, KB, KN, KM, CO, PE, SL, RSH, \
    LCT, FN, WIN, LALT, SPACE, RALT, RCT, LEFT, UP, DOWN, RIGHT \
) \
{ \
    TAB, TAB, KE, KW, KR, KQ, KU, KT, KY, N5, \
    N7, N4, N3, N2, N6, N1, TIL, N8, F3, F2, \
    F4, F1, F5, ESC, F6, ESC, F7, KZ, LSH, KX, \
    LSH, KC, LSH, KV, LCT, KB, KA, KD, CPS, KG, \
    KH, KS, CPS, KF, CPS, LCT, WIN, LALT, SC, KJ, \
    KK, KL, QU, ENTER, BR, BS, ENTER, BL, KI, KO, \
    KP, N0, NP, NM, BACK, BACK, F11, F8, F10, N9, \
    F12, F11, DEL, DEL, F9, PE, KN, KM, CO, SL, \
    RSH, UP, RSH, RSH, RALT, SPACE, SPACE, SPACE, RCT, LEFT, \
    DOWN, RIGHT, RSH, FN, SPACE, SPACE, SPACE \
}


const uint8_t color_map[97] = KEY_TO_LED(
    R,  O, O, O, O,  O, O, O, O,  O, O, O, O,  R,
    B,  LB, LB, LB, LB, LB, LB, LB, LB, LB, LB,  O, O,  R,
    B,  W, LB, W, W, W, W, W, W, W, W,  B, B, B,
    G,  LB, LB, LB, W, W, W, W, W, W,  B, B, LB,
    G,  W, W, W, W, W, W, W,  B, B, B,  G,
    O, O, LB, O, LB, O, O, R, R, R, R
);

#endif

#ifdef KEYBOARD_framework_macropad
/*
Framework 16 Macropad RGB Light physical to LED indices
┌────┬────┬────┬────┐
│ 5  │ 2  │ 22 │ 17 │
├────┼────┼────┼────┤
│ 4  │ 0  │ 20 │ 18 │
|    |    |    |    |
├────┼────┼────┼────┤
│ 7  │ 1  │ 21 │ 16 │
|    |    |    |    |
├────┼────┼────┼────┤
│ 6  │ 3  │ 23 │ 19 │
|    |    |    |    |
├────┼────┼────┼────┤
│ 9  │ 11 │ 15 │ 13 │
|    |    |    |    |
├────┼────┼────┼────┤
│ 8  │ 10 │ 14 │ 12 │
|    |    |    |    |
└────┴────┴────┴────┘
*/
#define KEY_TO_LED( \
    K1,  K2,  K3,  K4, \
    K5,  K6,  K7,  K8, \
    K9,  K10, K11, K12, \
    K13, K14, K15, K16, \
    K17, K18, K19, K20, \
    K21, K22, K23, K24 \
) \
{ \
    K6, K10, K2, K14, K5, K1, K13, K9, \
    K21, K17, K22, K18, K24, K20, K23, K19, \
    K12, K4, K8, K16, K7, K11, K3, K15 \
}

const uint8_t color_map[24] = KEY_TO_LED(
    LB, LB, LB, LB,
    W,  W,  W,  W,
    W,  W,  W,  W,
    W,  W,  W,  W,
    W,  W,  W,  W,
    W,  W,  W,  W
);

#endif


static bool multicolor_map(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        uint8_t color = color_map[i];

        uint8_t r = 0, g = 0, b = 0;

        switch (color) {
            case LB:
                r = 150;
                g = 200;
                b = 255;
                break;
            case B:
                r = 20;
                g = 50;
                b = 200;
                break;
            case G:
                r = 50;
                g = 200;
                b = 50;
                break;
            case R:
                r = 150;
                break;
            case O:
                r = 255;
                g = 100;
                break;
            case W:
                r = 255;
                g = 220;
                b = 120;
                break;
            default:
                break;
        }

        #ifdef KEYBOARD_framework_macropad
        r = scale8(r, 50);
        g = scale8(g, 50);
        b = scale8(b, 50);
        #endif

        uint8_t brightness = rgb_matrix_config.hsv.v;

        rgb_matrix_set_color(
            i,
            scale8(r, brightness),
            scale8(g, brightness),
            scale8(b, brightness)
        );
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // IMPLS

#endif // ENABLE
