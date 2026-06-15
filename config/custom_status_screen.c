#include <zmk/display/status_screen.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <lvgl.h>

// ======================
// LOGO (untuk kanan)
// ======================
static const uint8_t my_logo_map[] = {
    // ukuran 128x32 → butuh bitmap
    // sementara kita pakai dummy (kotak)
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
};

static lv_obj_t *logo_img;

// ======================
// INIT SCREEN
// ======================
lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);

    // cek role (kiri = central)
    if (zmk_split_bt_is_central()) {

        // ===== KIRI (default info) =====
        lv_obj_t *layer = zmk_widget_layer_status_create(screen);
        lv_obj_align(layer, LV_ALIGN_TOP_LEFT, 0, 0);

        lv_obj_t *battery = zmk_widget_battery_status_create(screen);
        lv_obj_align(battery, LV_ALIGN_BOTTOM_LEFT, 0, 0);

    } else {

        // ===== KANAN (logo) =====
        logo_img = lv_img_create(screen);
        lv_img_set_src(logo_img, my_logo_map);
        lv_obj_center(logo_img);
    }

    return screen;
}
