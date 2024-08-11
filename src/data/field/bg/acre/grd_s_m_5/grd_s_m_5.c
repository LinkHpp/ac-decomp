#include "libforest/gbi_extensions.h"

extern u8 wave3_tex_dummy[];
extern u8 wave2_tex_dummy[];
extern u8 wave1_tex_dummy[];
extern u8 sand_tex_dummy[];
extern u8 beach_pal_dummy2[];
extern u8 beach2_tex_dummy2[];
extern u8 beach1_tex_dummy2[];
extern u8 bush_pal_dummy[];
extern u8 cliff_pal_dummy[];
extern u8 earth_pal_dummy[];
extern u8 river_tex_dummy[];
extern u8 grass_tex_dummy[];
extern u8 bush_b_tex_dummy[];
extern u8 bush_a_tex_dummy[];
extern u8 earth_tex_dummy[];

static Vtx grd_s_m_5_v[] = {
#include "assets/field/bg/grd_s_m_5_v.inc"
};

extern Gfx grd_s_m_5_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 255, 32, 48, 144, 255),
    gsSPDisplayList(0x0C000000),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(beach2_tex_dummy2, G_IM_FMT_I, 32, 16, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_m_5_v[178], 26, 0),
    gsSPNTrianglesInit_5b(
        26, // tri count
        0, 1, 2, // tri0
        0, 3, 1, // tri1
        1, 4, 2 // tri2
    ),
    gsSPNTriangles_5b(
        4, 5, 2, // tri0
        4, 6, 5, // tri1
        6, 7, 5, // tri2
        7, 8, 5 // tri3
    ),
    gsSPNTriangles_5b(
        8, 9, 5, // tri0
        8, 10, 9, // tri1
        10, 11, 9, // tri2
        11, 12, 9 // tri3
    ),
    gsSPNTriangles_5b(
        12, 13, 9, // tri0
        14, 10, 8, // tri1
        15, 16, 14, // tri2
        15, 14, 8 // tri3
    ),
    gsSPNTriangles_5b(
        17, 15, 8, // tri0
        17, 8, 7, // tri1
        18, 17, 7, // tri2
        19, 18, 7 // tri3
    ),
    gsSPNTriangles_5b(
        6, 19, 7, // tri0
        3, 20, 21, // tri1
        3, 21, 22, // tri2
        3, 22, 1 // tri3
    ),
    gsSPNTriangles_5b(
        12, 11, 23, // tri0
        12, 23, 24, // tri1
        25, 12, 24, // tri2
        0, 0, 0 // tri3
    ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_a_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_m_5_v[165], 13, 0),
    gsSPNTrianglesInit_5b(
        6, // tri count
        0, 1, 2, // tri0
        3, 0, 4, // tri1
        5, 3, 6 // tri2
    ),
    gsSPNTriangles_5b(
        7, 5, 8, // tri0
        9, 7, 10, // tri1
        11, 9, 12, // tri2
        0, 0, 0 // tri3
    ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTLUT_Dolphin(15, 16, 1, cliff_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(river_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_m_5_v[0], 32, 0),
    gsSPNTrianglesInit_5b(
        28, // tri count
        0, 1, 2, // tri0
        1, 3, 2, // tri1
        3, 4, 2 // tri2
    ),
    gsSPNTriangles_5b(
        4, 5, 2, // tri0
        6, 7, 8, // tri1
        7, 9, 8, // tri2
        9, 10, 8 // tri3
    ),
    gsSPNTriangles_5b(
        11, 12, 13, // tri0
        11, 14, 12, // tri1
        14, 15, 12, // tri2
        15, 16, 12 // tri3
    ),
    gsSPNTriangles_5b(
        17, 18, 19, // tri0
        18, 20, 19, // tri1
        20, 21, 19, // tri2
        22, 23, 0 // tri3
    ),
    gsSPNTriangles_5b(
        23, 1, 0, // tri0
        13, 24, 11, // tri1
        24, 25, 11, // tri2
        26, 27, 9 // tri3
    ),
    gsSPNTriangles_5b(
        27, 10, 9, // tri0
        6, 15, 7, // tri1
        6, 16, 15, // tri2
        28, 29, 30 // tri3
    ),
    gsSPNTriangles_5b(
        28, 5, 29, // tri0
        5, 4, 29, // tri1
        22, 31, 23, // tri2
        22, 21, 31 // tri3
    ),
    gsSPNTriangles_5b(
        21, 20, 31, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_m_5_v[32], 4, 0),
    gsSPNTrianglesInit_5b(
        2, // tri count
        0, 1, 2, // tri0
        1, 3, 2, // tri1
        0, 0, 0 // tri2
    ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, beach_pal_dummy2),
    gsDPLoadTextureBlock_4b_Dolphin(sand_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_m_5_v[36], 16, 0),
    gsSPNTrianglesInit_5b(
        10, // tri count
        0, 1, 2, // tri0
        1, 3, 2, // tri1
        4, 5, 6 // tri2
    ),
    gsSPNTriangles_5b(
        5, 7, 6, // tri0
        8, 9, 10, // tri1
        9, 11, 10, // tri2
        12, 13, 14 // tri3
    ),
    gsSPNTriangles_5b(
        12, 15, 13, // tri0
        13, 0, 14, // tri1
        13, 1, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_m_5_v[52], 32, 0),
    gsSPNTrianglesInit_5b(
        17, // tri count
        0, 1, 2, // tri0
        3, 4, 5, // tri1
        6, 7, 8 // tri2
    ),
    gsSPNTriangles_5b(
        0, 6, 1, // tri0
        9, 10, 11, // tri1
        10, 0, 2, // tri2
        12, 3, 5 // tri3
    ),
    gsSPNTriangles_5b(
        7, 12, 13, // tri0
        3, 14, 4, // tri1
        14, 15, 16, // tri2
        17, 9, 18 // tri3
    ),
    gsSPNTriangles_5b(
        19, 20, 21, // tri0
        22, 19, 23, // tri1
        20, 24, 25, // tri2
        24, 26, 27 // tri3
    ),
    gsSPNTriangles_5b(
        28, 29, 30, // tri0
        29, 22, 31, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_m_5_v[84], 32, 0),
    gsSPNTrianglesInit_5b(
        30, // tri count
        0, 1, 2, // tri0
        1, 3, 2, // tri1
        4, 5, 6 // tri2
    ),
    gsSPNTriangles_5b(
        5, 7, 6, // tri0
        0, 7, 1, // tri1
        7, 5, 1, // tri2
        4, 8, 5 // tri3
    ),
    gsSPNTriangles_5b(
        8, 9, 5, // tri0
        8, 10, 9, // tri1
        11, 9, 10, // tri2
        1, 12, 3 // tri3
    ),
    gsSPNTriangles_5b(
        13, 14, 15, // tri0
        14, 16, 15, // tri1
        14, 17, 16, // tri2
        18, 12, 17 // tri3
    ),
    gsSPNTriangles_5b(
        12, 16, 17, // tri0
        18, 3, 12, // tri1
        13, 15, 19, // tri2
        15, 20, 19 // tri3
    ),
    gsSPNTriangles_5b(
        21, 22, 20, // tri0
        21, 23, 22, // tri1
        21, 24, 23, // tri2
        22, 19, 20 // tri3
    ),
    gsSPNTriangles_5b(
        16, 25, 15, // tri0
        25, 26, 15, // tri1
        25, 27, 26, // tri2
        27, 28, 26 // tri3
    ),
    gsSPNTriangles_5b(
        27, 29, 28, // tri0
        29, 30, 28, // tri1
        24, 31, 23, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_m_5_v[116], 20, 0),
    gsSPNTrianglesInit_5b(
        17, // tri count
        0, 1, 2, // tri0
        0, 3, 1, // tri1
        1, 4, 2 // tri2
    ),
    gsSPNTriangles_5b(
        4, 5, 2, // tri0
        5, 6, 2, // tri1
        1, 7, 4, // tri2
        7, 8, 4 // tri3
    ),
    gsSPNTriangles_5b(
        8, 9, 4, // tri0
        9, 10, 4, // tri1
        10, 11, 4, // tri2
        11, 5, 4 // tri3
    ),
    gsSPNTriangles_5b(
        5, 12, 6, // tri0
        13, 14, 15, // tri1
        16, 17, 14, // tri2
        16, 18, 17 // tri3
    ),
    gsSPNTriangles_5b(
        17, 15, 14, // tri0
        18, 19, 17, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bush_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bush_b_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_m_5_v[136], 13, 0),
    gsSPNTrianglesInit_5b(
        6, // tri count
        0, 1, 2, // tri0
        3, 0, 4, // tri1
        5, 6, 7 // tri2
    ),
    gsSPNTriangles_5b(
        1, 5, 8, // tri0
        9, 10, 11, // tri1
        10, 3, 12, // tri2
        0, 0, 0 // tri3
    ),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 255, 206, 189, 148, 255),
    gsSPDisplayList(0x0C000000),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(beach1_tex_dummy2, G_IM_FMT_I, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_m_5_v[149], 16, 0),
    gsSPNTrianglesInit_5b(
        10, // tri count
        0, 1, 2, // tri0
        0, 2, 3, // tri1
        4, 5, 6 // tri2
    ),
    gsSPNTriangles_5b(
        7, 4, 6, // tri0
        7, 6, 8, // tri1
        9, 7, 8, // tri2
        10, 9, 8 // tri3
    ),
    gsSPNTriangles_5b(
        10, 11, 9, // tri0
        12, 13, 14, // tri1
        12, 15, 13, // tri2
        0, 0, 0 // tri3
    ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_m_5_modelT[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(TEXEL1, 0, TEXEL0, TEXEL0, TEXEL1, 0, TEXEL0, 0, PRIMITIVE, 0, SHADE, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 255, 60, 120, 255, 255),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, wave1_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 0, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 64, wave2_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 1, 0, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPDisplayList(0x0B000000),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_m_5_v[204], 24, 0),
    gsSPNTrianglesInit_5b(
        20, // tri count
        0, 1, 2, // tri0
        0, 2, 3, // tri1
        4, 5, 6 // tri2
    ),
    gsSPNTriangles_5b(
        4, 6, 7, // tri0
        4, 7, 8, // tri1
        9, 4, 8, // tri2
        10, 9, 8 // tri3
    ),
    gsSPNTriangles_5b(
        11, 10, 8, // tri0
        12, 13, 14, // tri1
        15, 12, 14, // tri2
        16, 14, 17 // tri3
    ),
    gsSPNTriangles_5b(
        16, 15, 14, // tri0
        18, 8, 19, // tri1
        8, 7, 19, // tri2
        7, 20, 19 // tri3
    ),
    gsSPNTriangles_5b(
        7, 6, 20, // tri0
        6, 21, 20, // tri1
        18, 11, 8, // tri2
        22, 3, 23 // tri3
    ),
    gsSPNTriangles_5b(
        22, 0, 3, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, wave1_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 0, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, wave3_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 1, 0, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPDisplayList(0x0D000000),
    gsSPVertex(&grd_s_m_5_v[228], 28, 0),
    gsSPNTrianglesInit_5b(
        25, // tri count
        0, 1, 2, // tri0
        1, 3, 2, // tri1
        1, 4, 3 // tri2
    ),
    gsSPNTriangles_5b(
        5, 2, 3, // tri0
        6, 7, 8, // tri1
        7, 9, 8, // tri2
        10, 8, 9 // tri3
    ),
    gsSPNTriangles_5b(
        11, 12, 13, // tri0
        12, 8, 13, // tri1
        6, 14, 7, // tri2
        14, 15, 7 // tri3
    ),
    gsSPNTriangles_5b(
        16, 17, 11, // tri0
        17, 12, 11, // tri1
        18, 17, 16, // tri2
        19, 17, 18 // tri3
    ),
    gsSPNTriangles_5b(
        19, 20, 17, // tri0
        20, 21, 17, // tri1
        14, 5, 15, // tri2
        14, 2, 5 // tri3
    ),
    gsSPNTriangles_5b(
        1, 22, 4, // tri0
        1, 23, 22, // tri1
        23, 24, 22, // tri2
        23, 25, 24 // tri3
    ),
    gsSPNTriangles_5b(
        25, 26, 24, // tri0
        23, 27, 25, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsSPEndDisplayList(),
};
