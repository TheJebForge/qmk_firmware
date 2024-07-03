#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
RGB_MATRIX_EFFECT(WIDE_REACTIVE_BACKLIGHT)

#   ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef HSV (*reactive_backlight_f)(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick);

#ifndef RCVMIN
#define RCVMIN 130
#endif

bool effect_runner_reactive_backlight(uint8_t start, effect_params_t* params, reactive_backlight_f effect_func) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;

        hsv.v = 0;
        hsv.s = 0;

        for (uint8_t j = start; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            hsv           = effect_func(hsv, dx, dy, dist, tick);
        }

        uint8_t scaled_effect = scale8(qadd8(scale8(hsv.v, 255 - RCVMIN), RCVMIN), rgb_matrix_config.hsv.v);

        hsv.s = qsub8(rgb_matrix_config.hsv.s, scale8(scale8(hsv.s, rgb_matrix_config.hsv.s), 35));
        hsv.v   = scaled_effect;

        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static HSV WIDE_REACTIVE_BACKLIGHT_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;
    hsv.s = qadd8(hsv.s, scale8(255 - effect, 150));
    hsv.v = qadd8(hsv.v, scale8(255 - effect, 150));
    return hsv;
}

bool WIDE_REACTIVE_BACKLIGHT(effect_params_t* params) {
    return effect_runner_reactive_backlight(0, params, &WIDE_REACTIVE_BACKLIGHT_math);
}

#   endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // RGB_MATRIX_KEYREACTIVE_ENABLED
