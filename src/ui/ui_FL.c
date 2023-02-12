// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: FLScreen

#include "ui_FL.h"
#include "ui.h"

#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void ui_event_ScreenFL(lv_event_t * e);
lv_obj_t * ui_ScreenFL;
lv_obj_t * ui_Screen1_Panel1;
lv_obj_t * ui_Screen1_Panel2;
lv_obj_t * ui_SFLPStateLTitle;
lv_obj_t * ui_SFLPStateCB1;
lv_obj_t * ui_SFLPStateCB2;
lv_obj_t * ui_SFLPStateCB3;
lv_obj_t * ui_SFLPStateCB4;
lv_obj_t * ui_SFLPStateCB5;
lv_obj_t * ui_SFLPStateCB6;
lv_obj_t * ui_SFLPStateCB7;
lv_obj_t * ui_SFLPStateCB8;
lv_obj_t * ui_Screen1_Panel3;
lv_obj_t * ui_Screen1_Label2;
lv_obj_t * ui_ScreenFLCBError0;
lv_obj_t * ui_ScreenFLCBError1;
lv_obj_t * ui_ScreenFLCBError2;
lv_obj_t * ui_ScreenFLCBError3;
lv_obj_t * ui_ScreenFLCBError4;
lv_obj_t * ui_ScreenFLCBError5;
lv_obj_t * ui_ScreenFLCBError6;
lv_obj_t * ui_ScreenFLCBError7;
lv_obj_t * ui_Screen1_Label3;
lv_obj_t * ui_Screen1_Bar1;
lv_obj_t * ui_Screen1_Label4;
lv_obj_t * ui_Screen1_Label5;
lv_obj_t * ui_ScreenFL_Bar2;
lv_obj_t * ui_ScreenFL_Bar1;
lv_obj_t * ui_ScreenFL_Bar3;
lv_obj_t * ui_ScreenFL_Label5;
lv_obj_t * ui_ScreenFL_Label1;
lv_obj_t * ui_ScreenFL_Label2;
lv_obj_t * ui_ScreenFL_Label6;
lv_obj_t * ui_ScreenFL_Label4;
lv_obj_t * ui_ScreenFL_Label3;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_ScreenFL(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        _ui_screen_change(ui_S1Main, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}

///////////////////// SCREENS ////////////////////
void ui_ScreenFL_screen_init(void)
{
    ui_ScreenFL = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenFL, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Panel1 = lv_obj_create(ui_ScreenFL);
    lv_obj_set_width(ui_Screen1_Panel1, lv_pct(100));
    lv_obj_set_height(ui_Screen1_Panel1, lv_pct(100));
    lv_obj_set_align(ui_Screen1_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel1,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_style_radius(ui_Screen1_Panel1, 240, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen1_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Panel2 = lv_obj_create(ui_ScreenFL);
    lv_obj_set_width(ui_Screen1_Panel2, 130);
    lv_obj_set_height(ui_Screen1_Panel2, 254);
    lv_obj_set_y(ui_Screen1_Panel2, 0);
    lv_obj_set_x(ui_Screen1_Panel2, lv_pct(-33));
    lv_obj_set_align(ui_Screen1_Panel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SFLPStateLTitle = lv_label_create(ui_Screen1_Panel2);
    lv_obj_set_width(ui_SFLPStateLTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateLTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateLTitle, 0);
    lv_obj_set_y(ui_SFLPStateLTitle, lv_pct(-50));
    lv_obj_set_align(ui_SFLPStateLTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SFLPStateLTitle, "State");
    lv_obj_set_style_text_font(ui_SFLPStateLTitle, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SFLPStateCB1 = lv_checkbox_create(ui_Screen1_Panel2);
    lv_checkbox_set_text(ui_SFLPStateCB1, "Ovl Pwr Red");
    lv_obj_set_width(ui_SFLPStateCB1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateCB1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateCB1, lv_pct(-18));
    lv_obj_set_y(ui_SFLPStateCB1, lv_pct(-37));
    lv_obj_set_align(ui_SFLPStateCB1, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SFLPStateCB1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SFLPStateCB1, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SFLPStateCB2 = lv_checkbox_create(ui_Screen1_Panel2);
    lv_checkbox_set_text(ui_SFLPStateCB2, "Overload");
    lv_obj_set_width(ui_SFLPStateCB2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateCB2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateCB2, lv_pct(-18));
    lv_obj_set_y(ui_SFLPStateCB2, lv_pct(-25));
    lv_obj_set_align(ui_SFLPStateCB2, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SFLPStateCB2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags

    ui_SFLPStateCB3 = lv_checkbox_create(ui_Screen1_Panel2);
    lv_checkbox_set_text(ui_SFLPStateCB3, "in DUVR");
    lv_obj_set_width(ui_SFLPStateCB3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateCB3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateCB3, lv_pct(-18));
    lv_obj_set_y(ui_SFLPStateCB3, lv_pct(-12));
    lv_obj_set_align(ui_SFLPStateCB3, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SFLPStateCB3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SFLPStateCB3, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SFLPStateCB4 = lv_checkbox_create(ui_Screen1_Panel2);
    lv_checkbox_set_text(ui_SFLPStateCB4, "ChargeProh.");
    lv_obj_set_width(ui_SFLPStateCB4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateCB4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateCB4, lv_pct(-18));
    lv_obj_set_y(ui_SFLPStateCB4, lv_pct(0));
    lv_obj_set_align(ui_SFLPStateCB4, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SFLPStateCB4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SFLPStateCB4, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SFLPStateCB5 = lv_checkbox_create(ui_Screen1_Panel2);
    lv_checkbox_set_text(ui_SFLPStateCB5, "dischrgProh.");
    lv_obj_set_width(ui_SFLPStateCB5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateCB5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateCB5, lv_pct(-18));
    lv_obj_set_y(ui_SFLPStateCB5, lv_pct(12));
    lv_obj_set_align(ui_SFLPStateCB5, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SFLPStateCB5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SFLPStateCB5, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SFLPStateCB6 = lv_checkbox_create(ui_Screen1_Panel2);
    lv_checkbox_set_text(ui_SFLPStateCB6, "full Dischrg");
    lv_obj_set_width(ui_SFLPStateCB6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateCB6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateCB6, lv_pct(-18));
    lv_obj_set_y(ui_SFLPStateCB6, lv_pct(25));
    lv_obj_set_align(ui_SFLPStateCB6, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SFLPStateCB6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SFLPStateCB6, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SFLPStateCB7 = lv_checkbox_create(ui_Screen1_Panel2);
    lv_checkbox_set_text(ui_SFLPStateCB7, "CapAccurate");
    lv_obj_set_width(ui_SFLPStateCB7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateCB7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateCB7, lv_pct(-18));
    lv_obj_set_y(ui_SFLPStateCB7, lv_pct(37));
    lv_obj_set_align(ui_SFLPStateCB7, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SFLPStateCB7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SFLPStateCB7, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SFLPStateCB8 = lv_checkbox_create(ui_Screen1_Panel2);
    lv_checkbox_set_text(ui_SFLPStateCB8, "Discharge");
    lv_obj_set_width(ui_SFLPStateCB8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SFLPStateCB8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SFLPStateCB8, lv_pct(-18));
    lv_obj_set_y(ui_SFLPStateCB8, lv_pct(50));
    lv_obj_set_align(ui_SFLPStateCB8, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_SFLPStateCB8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SFLPStateCB8, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_Screen1_Panel3 = lv_obj_create(ui_ScreenFL);
    lv_obj_set_width(ui_Screen1_Panel3, 130);
    lv_obj_set_height(ui_Screen1_Panel3, 254);
    lv_obj_set_y(ui_Screen1_Panel3, 0);
    lv_obj_set_x(ui_Screen1_Panel3, lv_pct(33));
    lv_obj_set_align(ui_Screen1_Panel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Screen1_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Screen1_Label2 = lv_label_create(ui_Screen1_Panel3);
    lv_obj_set_width(ui_Screen1_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label2, 0);
    lv_obj_set_y(ui_Screen1_Label2, lv_pct(-50));
    lv_obj_set_align(ui_Screen1_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label2, "Error");
    lv_obj_set_style_text_font(ui_Screen1_Label2, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenFLCBError0 = lv_checkbox_create(ui_Screen1_Panel3);
    lv_checkbox_set_text(ui_ScreenFLCBError0, "Critical");
    lv_obj_set_width(ui_ScreenFLCBError0, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFLCBError0, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFLCBError0, lv_pct(-18));
    lv_obj_set_y(ui_ScreenFLCBError0, lv_pct(-37));
    lv_obj_set_align(ui_ScreenFLCBError0, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_ScreenFLCBError0, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenFLCBError0, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenFLCBError0, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError0, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenFLCBError0, lv_color_hex(0xB50000), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError0, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ScreenFLCBError1 = lv_checkbox_create(ui_Screen1_Panel3);
    lv_checkbox_set_text(ui_ScreenFLCBError1, "Low Temp");
    lv_obj_set_width(ui_ScreenFLCBError1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFLCBError1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFLCBError1, lv_pct(-18));
    lv_obj_set_y(ui_ScreenFLCBError1, lv_pct(-25));
    lv_obj_set_align(ui_ScreenFLCBError1, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_ScreenFLCBError1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenFLCBError1, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenFLCBError1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenFLCBError1, lv_color_hex(0x00E8FF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError1, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ScreenFLCBError2 = lv_checkbox_create(ui_Screen1_Panel3);
    lv_checkbox_set_text(ui_ScreenFLCBError2, "High Temp");
    lv_obj_set_width(ui_ScreenFLCBError2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFLCBError2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFLCBError2, lv_pct(-18));
    lv_obj_set_y(ui_ScreenFLCBError2, lv_pct(-12));
    lv_obj_set_align(ui_ScreenFLCBError2, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_ScreenFLCBError2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenFLCBError2, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenFLCBError2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenFLCBError2, lv_color_hex(0xFF5E00), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError2, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ScreenFLCBError3 = lv_checkbox_create(ui_Screen1_Panel3);
    lv_checkbox_set_text(ui_ScreenFLCBError3, "High Volt");
    lv_obj_set_width(ui_ScreenFLCBError3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFLCBError3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFLCBError3, lv_pct(-18));
    lv_obj_set_y(ui_ScreenFLCBError3, lv_pct(0));
    lv_obj_set_align(ui_ScreenFLCBError3, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_ScreenFLCBError3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenFLCBError3, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenFLCBError3, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenFLCBError3, lv_color_hex(0xA92700), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError3, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ScreenFLCBError4 = lv_checkbox_create(ui_Screen1_Panel3);
    lv_checkbox_set_text(ui_ScreenFLCBError4, "Low Volt");
    lv_obj_set_width(ui_ScreenFLCBError4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFLCBError4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFLCBError4, lv_pct(-18));
    lv_obj_set_y(ui_ScreenFLCBError4, lv_pct(12));
    lv_obj_set_align(ui_ScreenFLCBError4, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_ScreenFLCBError4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenFLCBError4, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenFLCBError4, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenFLCBError4, lv_color_hex(0x76471E), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError4, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ScreenFLCBError5 = lv_checkbox_create(ui_Screen1_Panel3);
    lv_checkbox_set_text(ui_ScreenFLCBError5, "ChargeProt");
    lv_obj_set_width(ui_ScreenFLCBError5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFLCBError5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFLCBError5, lv_pct(-18));
    lv_obj_set_y(ui_ScreenFLCBError5, lv_pct(25));
    lv_obj_set_align(ui_ScreenFLCBError5, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_ScreenFLCBError5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenFLCBError5, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenFLCBError5, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenFLCBError5, lv_color_hex(0xB83F7F), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError5, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ScreenFLCBError6 = lv_checkbox_create(ui_Screen1_Panel3);
    lv_checkbox_set_text(ui_ScreenFLCBError6, "Checksum");
    lv_obj_set_width(ui_ScreenFLCBError6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFLCBError6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFLCBError6, lv_pct(-18));
    lv_obj_set_y(ui_ScreenFLCBError6, lv_pct(37));
    lv_obj_set_align(ui_ScreenFLCBError6, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_ScreenFLCBError6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenFLCBError6, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenFLCBError6, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenFLCBError6, lv_color_hex(0xFF8C00), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError6, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_ScreenFLCBError7 = lv_checkbox_create(ui_Screen1_Panel3);
    lv_checkbox_set_text(ui_ScreenFLCBError7, "Interrupt");
    lv_obj_set_width(ui_ScreenFLCBError7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFLCBError7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFLCBError7, lv_pct(-18));
    lv_obj_set_y(ui_ScreenFLCBError7, lv_pct(50));
    lv_obj_set_align(ui_ScreenFLCBError7, LV_ALIGN_LEFT_MID);
    lv_obj_add_flag(ui_ScreenFLCBError7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenFLCBError7, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_text_color(ui_ScreenFLCBError7, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ScreenFLCBError7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui_ScreenFLCBError7, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    ui_Screen1_Label3 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_Screen1_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label3, lv_pct(0));
    lv_obj_set_y(ui_Screen1_Label3, lv_pct(-34));
    lv_obj_set_align(ui_Screen1_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label3, "Forumslader");
    lv_obj_set_style_text_font(ui_Screen1_Label3, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Bar1 = lv_bar_create(ui_ScreenFL);
    lv_bar_set_value(ui_Screen1_Bar1, 66, LV_ANIM_OFF);
    lv_obj_set_width(ui_Screen1_Bar1, 340);
    lv_obj_set_height(ui_Screen1_Bar1, 20);
    lv_obj_set_x(ui_Screen1_Bar1, 0);
    lv_obj_set_y(ui_Screen1_Bar1, 160);
    lv_obj_set_align(ui_Screen1_Bar1, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_Screen1_Bar1, lv_color_hex(0x331111), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Bar1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1_Bar1, lv_color_hex(0x113311), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Screen1_Bar1, LV_GRAD_DIR_HOR, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Screen1_Bar1, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1_Bar1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1_Bar1, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_Screen1_Bar1, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_Screen1_Bar1, 220, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Screen1_Bar1, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_Screen1_Label4 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_Screen1_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label4, lv_pct(0));
    lv_obj_set_y(ui_Screen1_Label4, lv_pct(42));
    lv_obj_set_align(ui_Screen1_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label4, "55.5");
    lv_obj_set_style_text_font(ui_Screen1_Label4, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen1_Label5 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_Screen1_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Screen1_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Screen1_Label5, lv_pct(0));
    lv_obj_set_y(ui_Screen1_Label5, lv_pct(-43));
    lv_obj_set_align(ui_Screen1_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Screen1_Label5, "22:55:55\n2022-12-31");
    lv_obj_set_style_text_align(ui_Screen1_Label5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen1_Label5, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenFL_Bar2 = lv_bar_create(ui_ScreenFL);
    lv_bar_set_value(ui_ScreenFL_Bar2, 10, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScreenFL_Bar2, 20);
    lv_obj_set_height(ui_ScreenFL_Bar2, lv_pct(50));
    lv_obj_set_align(ui_ScreenFL_Bar2, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_ScreenFL_Bar2, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenFL_Bar2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ScreenFL_Bar2, lv_color_hex(0xA5FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_ScreenFL_Bar2, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ScreenFL_Bar1 = lv_bar_create(ui_ScreenFL);
    lv_bar_set_value(ui_ScreenFL_Bar1, 100, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScreenFL_Bar1, 20);
    lv_obj_set_height(ui_ScreenFL_Bar1, lv_pct(50));
    lv_obj_set_y(ui_ScreenFL_Bar1, 0);
    lv_obj_set_x(ui_ScreenFL_Bar1, lv_pct(-10));
    lv_obj_set_align(ui_ScreenFL_Bar1, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_ScreenFL_Bar1, lv_color_hex(0x2BFF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenFL_Bar1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ScreenFL_Bar1, lv_color_hex(0x0059FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_ScreenFL_Bar1, 100, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_ScreenFL_Bar1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_ScreenFL_Bar1, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ScreenFL_Bar3 = lv_bar_create(ui_ScreenFL);
    lv_bar_set_range(ui_ScreenFL_Bar3, -1500, 1500);
    lv_bar_set_value(ui_ScreenFL_Bar3, 500, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScreenFL_Bar3, 20);
    lv_obj_set_height(ui_ScreenFL_Bar3, lv_pct(50));
    lv_obj_set_y(ui_ScreenFL_Bar3, 0);
    lv_obj_set_x(ui_ScreenFL_Bar3, lv_pct(10));
    lv_obj_set_align(ui_ScreenFL_Bar3, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(ui_ScreenFL_Bar3, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenFL_Bar3, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_ScreenFL_Bar3, lv_color_hex(0xFF0000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_ScreenFL_Bar3, LV_GRAD_DIR_VER, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_ScreenFL_Label5 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_ScreenFL_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFL_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFL_Label5, -50);
    lv_obj_set_y(ui_ScreenFL_Label5, 135);
    lv_obj_set_align(ui_ScreenFL_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenFL_Label5, "8,5W");
    lv_obj_set_style_text_align(ui_ScreenFL_Label5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenFL_Label5, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenFL_Label1 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_ScreenFL_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFL_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFL_Label1, 59);
    lv_obj_set_y(ui_ScreenFL_Label1, 135);
    lv_obj_set_align(ui_ScreenFL_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenFL_Label1, "-0,8A");
    lv_obj_set_style_text_align(ui_ScreenFL_Label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenFL_Label1, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenFL_Label2 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_ScreenFL_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFL_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ScreenFL_Label2, 7);
    lv_obj_set_y(ui_ScreenFL_Label2, -135);
    lv_obj_set_align(ui_ScreenFL_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenFL_Label2, "8,5W");
    lv_obj_set_style_text_align(ui_ScreenFL_Label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenFL_Label2, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenFL_Label6 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_ScreenFL_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFL_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_y(ui_ScreenFL_Label6, 0);
    lv_obj_set_x(ui_ScreenFL_Label6, lv_pct(-12));
    lv_obj_set_align(ui_ScreenFL_Label6, LV_ALIGN_CENTER);
    //lv_obj_set_style_transform_angle(ui_ScreenFL_Label6, 900, 0);
    lv_label_set_text(ui_ScreenFL_Label6, "Dynamoleistung");


    ui_ScreenFL_Label4 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_ScreenFL_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFL_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_y(ui_ScreenFL_Label4, 0);
    lv_obj_set_x(ui_ScreenFL_Label4, lv_pct(-2));
    lv_obj_set_align(ui_ScreenFL_Label4, LV_ALIGN_CENTER);
    lv_obj_set_style_transform_angle(ui_ScreenFL_Label4, 900, 0);
    lv_label_set_text(ui_ScreenFL_Label4, "Verbraucherleistung");


    ui_ScreenFL_Label3 = lv_label_create(ui_ScreenFL);
    lv_obj_set_width(ui_ScreenFL_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ScreenFL_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_y(ui_ScreenFL_Label3, 0);
    lv_obj_set_x(ui_ScreenFL_Label3, lv_pct(8));
    lv_obj_set_align(ui_ScreenFL_Label3, LV_ALIGN_CENTER);
    lv_obj_set_style_transform_angle(ui_ScreenFL_Label3, 900, 0);
    lv_label_set_text(ui_ScreenFL_Label3, "Batteriestrom");

    lv_obj_add_event_cb(ui_ScreenFL, ui_event_ScreenFL, LV_EVENT_ALL, NULL);

}

void ui_init_ScrFL(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenFL_screen_init();
    //lv_disp_load_scr(ui_ScreenFL);
}
