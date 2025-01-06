#ifndef AUDIO_DEFS_H
#define AUDIO_DEFS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VOICE_MODE_ANIMALESE 0
#define VOICE_MODE_CLICK 1
#define VOICE_MODE_SILENT 2

/* audio is monophonic */
#define MONO(id) ((id) | 0x1000)
#define HANABI(id) ((id) | 0x2000) /* TODO: better name, this probably is some echo effect modifier */
#define SE_FLAG_15(id) ((id) | 0x8000)

// TODO: Make the rest of Sound Effects with parameters
#define SE_REGISTER MONO(NA_SE_REGISTER)

typedef enum audio_sound_effects {
    NA_SE_START,
    NA_SE_CURSOL,
    NA_SE_MENU_EXIT,

    NA_SE_3 = 3,

    NA_SE_ZOOMUP = 4,
    NA_SE_ZOOMDOWN_SHORT,

    NA_SE_6 = 0x6,
    NA_SE_7 = 0x7,
    NA_SE_8 = 0x8,
    NA_SE_9 = 0x9,

    NA_SE_A = 0xA,
    NA_SE_PAGE_OKURI = 0xB,

    NA_SE_SENTAKU_OPEN,
    NA_SE_SENTAKU_KETTEI,

    NA_SE_TUMBLE_GRASS,
    NA_SE_TUMBLE_SOIL,
    NA_SE_TUMBLE_STONE,
    NA_SE_TUMBLE_WOOD,
    NA_SE_TUMBLE_BUSH,
    NA_SE_TUMBLE_SNOW,

    NA_SE_ZOOMDOWN_LONG = 0x15,
    NA_SE_LIGHT_ON,
    NA_SE_LIGHT_OFF,

    NA_SE_25 = 0x25,
    NA_SE_26 = 0x26,
    NA_SE_27 = 0x27,

    NA_SE_2A = 0x2A,

    NA_SE_MENU_PAUSE = 0x30,
    NA_SE_31 = 0x31,
    NA_SE_32 = 0x32,
    NA_SE_33 = 0x33,

    NA_SE_DRAWER_SHUT = 0x3A,

    NA_SE_ITEM_GET = 0x40,
    NA_SE_NOTE_G_LOW = MONO(0x42),
    NA_SE_NOTE_A_LOW = MONO(0x43),
    NA_SE_NOTE_B_LOW = MONO(0x44),
    NA_SE_NOTE_C_LOW = MONO(0x45),
    NA_SE_NOTE_D_LOW = MONO(0x46),
    NA_SE_NOTE_E_LOW = MONO(0x47),
    NA_SE_NOTE_F_LOW = MONO(0x48),
    NA_SE_NOTE_G = MONO(0x49),
    NA_SE_NOTE_A = MONO(0x4A),
    NA_SE_NOTE_B = MONO(0x4B),
    NA_SE_NOTE_C = MONO(0x4C),
    NA_SE_NOTE_D = MONO(0x4D),
    NA_SE_NOTE_E = MONO(0x4E),
    NA_SE_NOTE_RANDOM = MONO(0x4F),
    NA_SE_47 = 0x47,
    NA_SE_COIN = 0x4C,
    NA_SE_TEMOCHI_KAZAGURUMA,

    NA_SE_REGISTER = 0x50,
    NA_SE_51 = 0x51,
    NA_SE_52 = 0x52,

    NA_SE_54 = 0x54,

    NA_SE_ITEM_HORIDASHI = 0x57,
    NA_SE_CLEAN_UP_FTR = 0x58,

    NA_SE_TOOL_FURI = 0x5A, // swing?
    NA_SE_AMI_HIT = 0x5C,
    NA_SE_TOOL_GET,
    NA_SE_5E = 0x5E,
    NA_SE_5F = 0x5F,
    NA_SE_60 = 0x60,
    NA_SE_61 = 0x61,

    NA_SE_63 = 0x63,
    NA_SE_64 = 0x64,
    NA_SE_65 = 0x65,
    NA_SE_66 = 0x66,
    NA_SE_67 = 0x67,
    NA_SE_68 = 0x68,

    NA_SE_GASAGOSO = 0x69,
    NA_SE_6A = 0x6A,

    NA_SE_TOILE_CHAIR_STANDUP = 0x72,

    NA_SE_TOOL_BROKEN1 = 0x74,
    NA_SE_TOOL_BROKEN2,
    NA_SE_TOOL_BROKEN3,

    NA_SE_STONECOIN_ROLL = 0x7D,
    NA_SE_STONECOIN_DRAG = 0x7E,

    NA_SE_7F = 0x7F,

    NA_SE_TRAIN_RIDE = 0x8D,

    NA_SE_GOKI_MOVE = 0xA8,

    NA_SE_B0 = 0xB0,

    NA_SE_KA_BUZZ = 0xCF,

    NA_SE_108 = 0x108,
    NA_SE_ROD_STROKE = 0x109,
    NA_SE_ROD_BACK,
    NA_SE_10B,
    NA_SE_10C,

    NA_SE_HANABI0 = HANABI(0x10F),
    NA_SE_HANABI1 = HANABI(0x110),
    NA_SE_HANABI2 = HANABI(0x111),
    NA_SE_HANABI3 = HANABI(0x112),
    NA_SE_EAT = 0x113,
    NA_SE_114 = 0x114,

    NA_SE_11B = 0x11B,
    NA_SE_WEAR = 0x11C,

    NA_SE_SCOOP1 = 0x11E,

    NA_SE_SCOOP_UMERU = 0x120,
    NA_SE_SCOOP_HIT,

    NA_SE_12D = 0x12D,

    NA_SE_TREE_TOUCH = 0x134,
    NA_SE_TREE_YURASU,

    NA_SE_PUN_YUGE = 0x13B,

    NA_SE_DOYON = 0x13F,

    NA_SE_KIRIBASU_SCOOP = 0x148,
    NA_SE_KIRIBASU_OUT,

    NA_SE_SOUND_KNOCK,

    NA_SE_TUMBLE_SAND = 0x156,
    NA_SE_TUMBLE_WAVE,

    NA_SE_ARAIIKI_BOY = 0x158,
    NA_SE_ARAIIKI_GIRL = 0x15A,

    NA_SE_ZASSOU_NUKU = 0x15F,
    NA_SE_HACHI_SASARERU,

    NA_SE_166 = 0x166,
    NA_SE_UCHIWA = 0x167,
    NA_SE_LAWNMOWER = 0x177,

    NA_SE_207 = 0x207,

    NA_SE_SCOOP_SHIGEMI = 0x401,

    NA_SE_40B = 0x40B,

    NA_SE_CAMERA_MOVE1 = 0x40D,
    NA_SE_CAMERA_MOVE2,

    NA_SE_TOILE_CHAIR_SIT = 0x410,

    NA_SE_TRAINDOOR0 = 0x412,
    NA_SE_TRAINDOOR1,

    NA_SE_BED_IN = 0x415,
    NA_SE_BED_NEGAERI,
    NA_SE_BED_OUT,

    NA_SE_ROTATE = 0x41A,

    NA_SE_41C = 0x41C,
    NA_SE_AXE_HIT,
    NA_SE_AXE_CUT,
    NA_SE_SOFT_CHAIR_SIT,
    NA_SE_HARD_CHAIR_SIT,
    NA_SE_BUBU_CHAIR_SIT,
    NA_SE_SOFT_CHAIR_STANDUP,
    NA_SE_HARD_CHAIR_STANDUP,

    NA_SE_426 = 0x426,

    NA_SE_BUBU_CHAIR_STANDUP = 0x429,
    NA_SE_JUMP,
    NA_SE_LANDING,
    NA_SE_FTR_DOOR_OPEN = 0x42C,
    NA_SE_FTR_DOOR_CLOSE = 0x42D,
    NA_SE_DRAWER_OPEN = 0x42E,
    NA_SE_DRAWER_CLOSE = 0x42F,
    NA_SE_DAI_UE_KAKUNOU = 0x430,

    NA_SE_UMBRELLA_ROTATE = 0x432,

    NA_SE_435 = 0x435,
    NA_SE_436 = 0x436,
    NA_SE_437 = 0x437,

    NA_SE_KARABURI = 0x43A,

    NA_SE_43D = 0x43D,

    NA_SE_ROD_STROKE_SMALL = 0x445,
    NA_SE_446 = 0x446,

    NA_SE_SCOOP_TREE_HIT = 0x448,
    NA_SE_SCOOP_ITEM_HIT,
    NA_SE_AXE_BALL_HIT,

    NA_SE_44B = 0x44B,
    NA_SE_44C = 0x44C,

    NA_SE_45E = 0x45E,
    NA_SE_45F = 0x45F,

    NA_SE_461 = 0x461,

    NA_SE_COIN_GASAGOSO = 0x465,

    // Footsteps
    NA_SE_FOOTSTEP_BEGIN = 0x4200,
    NA_SE_FOOTSTEP_GRASS,
    NA_SE_FOOTSTEP_SOIL,
    NA_SE_FOOTSTEP_STONE,
    NA_SE_FOOTSTEP_WOOD,
    NA_SE_FOOTSTEP_BUSH,
    NA_SE_FOOTSTEP_SNOW,
    NA_SE_FOOTSTEP_7,
    NA_SE_FOOTSTEP_SAND,
    NA_SE_FOOTSTEP_WAVE,
    NA_SE_FOOTSTEP_PLUSSBRIDGE,

} AudioSE;

typedef enum bgm_e {
    BGM_SILENCE,
    BGM_FIELD_00,
    BGM_FIELD_01,
    BGM_FIELD_02,
    BGM_FIELD_03,
    BGM_FIELD_04,
    BGM_FIELD_05,
    BGM_FIELD_06,
    BGM_FIELD_07,
    BGM_FIELD_08,
    BGM_FIELD_09,
    BGM_FIELD_10,
    BGM_FIELD_11,
    BGM_FIELD_12,
    BGM_FIELD_13,
    BGM_FIELD_14,
    BGM_FIELD_15,
    BGM_FIELD_16,
    BGM_FIELD_17,
    BGM_FIELD_18,
    BGM_FIELD_19,
    BGM_FIELD_20,
    BGM_FIELD_21,
    BGM_FIELD_22,
    BGM_FIELD_23,
    BGM_BROKERS_SHOP,
    BGM_FORTUNE_TELLER,
    BGM_SPORTSFAIR_AEROBICS,
    BGM_SPORTSFAIR_FOOTRACE,
    BGM_SPORTSFAIR_BALLTOSS,
    BGM_HARVEST_MOON,
    BGM_NEW_YEARS_1HR,
    BGM_NEW_YEARS_30MIN,
    BGM_NEW_YEARS_10MIN,
    BGM_NEW_YEARS_5MIN,
    BGM_NEW_YEARS_NOW,
    BGM_NEW_YEARS_DAY,
    BGM_SHOP1,
    BGM_SHOP2,
    BGM_SHOP3,
    BGM_DIG_ITEM,
    BGM_POST_OFFICE0,
    BGM_INTRO_TRAIN,
    BGM_INTRO_KK,
    BGM_SHOP0,
    BGM_POLICE_BOX,
    BGM_SAVE,
    BGM_INTRO_ARRIVE,
    BGM_INTRO_RCN_GUIDE,
    BGM_INTRO_SELECT_HOUSE,
    BGM_INTRO_SELECT_HOUSE2,
    BGM_INTRO_FIND_SHOP,
    BGM_INTRO_CHORES,
    BGM_HALLOWEEN,
    BGM_XMAS_EVE,
    BGM_FIREWORKS_FESTIVAL,
    BGM_CHERRY_BLOSSOM_FESTIVAL,
    BGM_NEW_YEARS_PARTY,
    BGM_KK_HAZURE0,
    BGM_NEW_YEARS_WISH,
    BGM_SPORTSFAIR_TUGOFWAR,
    BGM_NEW_YEARS_MORNING,
    BGM_POST_OFFICE1,
    BGM_TRAIN_PULL_INTO_TOWN,
    BGM_TRAIN_BOARD,
    BGM_ENTER_HOUSE,
    BGM_RESET,
    BGM_BEE_CHASE,
    BGM_BEE_STUNG,
    BGM_RAIN,
    BGM_TITLE,
    BGM_TRAIN_ARRIVAL_WAIT,
    BGM_INTRO_NEW_TOWN,
    BGM_INTRO_CHORES_COMPLETE,
    BGM_DEBT_PAID,
    BGM_ALL_INSECTS,
    BGM_ALL_FISH,
    BGM_KAMAKURA,
    BGM_RESET2,
    BGM_SHOP0_LATE,
    BGM_SHOP1_LATE,
    BGM_SHOP2_LATE,
    BGM_SHOP3_LATE,
    BGM_NINTENDO0,
    BGM_NINTENDO1,
    BGM_NINTENDO2,
    BGM_NINTENDO3,
    BGM_NINTENDO4,
    BGM_MUSEUM,
    BGM_TAILORS,
    BGM_90,
    BGM_ISLAND,
    BGM_KAPPA_SONG0,
    BGM_KAPPA_SONG1,
    BGM_KAPPA_SONG2,
    BGM_KAPPA_SONG3,
    BGM_KAPPA_SONG4,
    BGM_KAPPA_SONG5,
    BGM_KAPPA_SONG6,
    BGM_KAPPA_SONG7,
    BGM_KAPPA_SONG8,
    BGM_KAPPA_SONG9,
    BGM_KAPPA_SONG10,
    BGM_KAPPA_SONG11,
    BGM_KAPPA_SONG12,
    BGM_KAPPA_SONG13,
    BGM_KAPPA_SONG14,
    BGM_KAPPA_SONG15,
    // TODO: others
    BGM_MD0 = 128,
} BGM_e;

#ifdef __cplusplus
}
#endif

#endif
