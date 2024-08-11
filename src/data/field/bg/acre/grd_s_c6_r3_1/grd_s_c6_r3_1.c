#include "libforest/gbi_extensions.h"

extern u8 cliff_pal_dummy[];
extern u8 earth_pal_dummy[];
extern u8 water_2_tex_dummy[];
extern u8 water_1_tex_dummy[];
extern u8 river_tex_dummy[];
extern u8 grass_tex_dummy[];
extern u8 cliff_tex_dummy[];
extern u8 earth_tex_dummy[];

static Vtx grd_s_c6_r3_1_v[] = {
#include "assets/field/bg/grd_s_c6_r3_1_v.inc"
};

extern Gfx grd_s_c6_r3_1_modelT[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 1, 0, TEXEL0, TEXEL1, COMBINED, 0, SHADE, TEXEL0,
                       COMBINED, 0, PRIM_LOD_FRAC, PRIMITIVE),
    gsDPSetPrimColor(0, 50, 255, 255, 255, 50),
    gsDPSetEnvColor(0x00, 0x64, 0xFF, 0xFF),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_ZB_XLU_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(water_1_tex_dummy, G_IM_FMT_I, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPLoadMultiBlock_4b_Dolphin(water_2_tex_dummy, 1, G_IM_FMT_I, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPDisplayList(0x08000000),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_c6_r3_1_v[301], 28, 0),
    gsSPNTrianglesInit_5b(23,      // tri count
                          0, 1, 2, // tri0
                          2, 3, 0, // tri1
                          1, 4, 2  // tri2
                          ),
    gsSPNTriangles_5b(5, 1, 6, // tri0
                      5, 4, 1, // tri1
                      7, 5, 8, // tri2
                      5, 6, 8  // tri3
                      ),
    gsSPNTriangles_5b(9, 10, 11,  // tri0
                      12, 9, 11,  // tri1
                      12, 11, 13, // tri2
                      14, 12, 13  // tri3
                      ),
    gsSPNTriangles_5b(15, 14, 13, // tri0
                      15, 13, 16, // tri1
                      17, 15, 16, // tri2
                      8, 17, 16   // tri3
                      ),
    gsSPNTriangles_5b(8, 16, 18,  // tri0
                      8, 18, 7,   // tri1
                      19, 20, 21, // tri2
                      19, 22, 20  // tri3
                      ),
    gsSPNTriangles_5b(23, 24, 20, // tri0
                      23, 25, 24, // tri1
                      25, 26, 24, // tri2
                      25, 27, 26  // tri3
                      ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_c6_r3_1_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_c6_r3_1_v[0], 32, 0),
    gsSPNTrianglesInit_5b(20,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          4, 1, 5  // tri2
                          ),
    gsSPNTriangles_5b(1, 6, 5,   // tri0
                      7, 8, 9,   // tri1
                      8, 10, 9,  // tri2
                      11, 12, 13 // tri3
                      ),
    gsSPNTriangles_5b(11, 14, 12, // tri0
                      12, 15, 13, // tri1
                      16, 17, 18, // tri2
                      16, 19, 17  // tri3
                      ),
    gsSPNTriangles_5b(16, 20, 19, // tri0
                      17, 21, 18, // tri1
                      19, 22, 17, // tri2
                      23, 24, 25  // tri3
                      ),
    gsSPNTriangles_5b(24, 26, 25, // tri0
                      26, 27, 25, // tri1
                      28, 16, 29, // tri2
                      16, 18, 29  // tri3
                      ),
    gsSPNTriangles_5b(4, 30, 1, // tri0
                      0, 0, 0,  // tri1
                      0, 0, 0,  // tri2
                      0, 0, 0   // tri3
                      ),
    gsSPVertex(&grd_s_c6_r3_1_v[31], 32, 0),
    gsSPNTrianglesInit_5b(19,      // tri count
                          0, 1, 2, // tri0
                          3, 0, 2, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(7, 8, 9,    // tri0
                      10, 7, 9,   // tri1
                      11, 12, 13, // tri2
                      14, 15, 16  // tri3
                      ),
    gsSPNTriangles_5b(17, 18, 19, // tri0
                      17, 20, 21, // tri1
                      17, 19, 20, // tri2
                      6, 8, 7     // tri3
                      ),
    gsSPNTriangles_5b(4, 6, 22,  // tri0
                      6, 7, 22,  // tri1
                      7, 23, 22, // tri2
                      1, 24, 25  // tri3
                      ),
    gsSPNTriangles_5b(1, 26, 2,   // tri0
                      26, 1, 27,  // tri1
                      20, 19, 28, // tri2
                      19, 29, 28  // tri3
                      ),
    gsSPVertex(&grd_s_c6_r3_1_v[61], 15, 0),
    gsSPNTrianglesInit_5b(9,       // tri count
                          0, 1, 2, // tri0
                          0, 3, 1, // tri1
                          0, 4, 3  // tri2
                          ),
    gsSPNTriangles_5b(5, 4, 0,   // tri0
                      6, 7, 8,   // tri1
                      9, 10, 11, // tri2
                      10, 12, 11 // tri3
                      ),
    gsSPNTriangles_5b(12, 13, 14, // tri0
                      12, 10, 13, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_c6_r3_1_v[76], 32, 0),
    gsSPNTrianglesInit_5b(15,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 1, // tri1
                          5, 6, 7  // tri2
                          ),
    gsSPNTriangles_5b(8, 7, 4,    // tri0
                      9, 10, 6,   // tri1
                      11, 12, 13, // tri2
                      14, 15, 16  // tri3
                      ),
    gsSPNTriangles_5b(17, 13, 15, // tri0
                      18, 16, 19, // tri1
                      20, 19, 21, // tri2
                      22, 23, 12  // tri3
                      ),
    gsSPNTriangles_5b(24, 25, 23, // tri0
                      26, 27, 28, // tri1
                      29, 28, 25, // tri2
                      30, 31, 27  // tri3
                      ),
    gsSPVertex(&grd_s_c6_r3_1_v[108], 32, 0),
    gsSPNTrianglesInit_5b(16,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          6, 7, 8  // tri2
                          ),
    gsSPNTriangles_5b(9, 10, 11,  // tri0
                      1, 0, 12,   // tri1
                      13, 14, 15, // tri2
                      16, 13, 17  // tri3
                      ),
    gsSPNTriangles_5b(18, 19, 20, // tri0
                      19, 16, 21, // tri1
                      16, 17, 21, // tri2
                      22, 23, 24  // tri3
                      ),
    gsSPNTriangles_5b(25, 22, 24, // tri0
                      26, 25, 27, // tri1
                      22, 28, 23, // tri2
                      28, 18, 29  // tri3
                      ),
    gsSPNTriangles_5b(30, 26, 31, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_c6_r3_1_v[140], 3, 0),
    gsSPNTrianglesInit_5b(1,       // tri count
                          0, 1, 2, // tri0
                          0, 0, 0, // tri1
                          0, 0, 0  // tri2
                          ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, cliff_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(cliff_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_c6_r3_1_v[143], 32, 0),
    gsSPNTrianglesInit_5b(20,      // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          0, 4, 1  // tri2
                          ),
    gsSPNTriangles_5b(4, 5, 1,  // tri0
                      6, 7, 8,  // tri1
                      6, 9, 7,  // tri2
                      10, 11, 0 // tri3
                      ),
    gsSPNTriangles_5b(11, 12, 13, // tri0
                      14, 15, 13, // tri1
                      16, 6, 15,  // tri2
                      17, 18, 6   // tri3
                      ),
    gsSPNTriangles_5b(17, 19, 18, // tri0
                      17, 20, 19, // tri1
                      20, 21, 19, // tri2
                      22, 23, 21  // tri3
                      ),
    gsSPNTriangles_5b(22, 24, 23, // tri0
                      24, 25, 26, // tri1
                      27, 28, 26, // tri2
                      27, 29, 28  // tri3
                      ),
    gsSPNTriangles_5b(30, 31, 29, // tri0
                      0, 0, 0,    // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_c6_r3_1_v[175], 32, 0),
    gsSPNTrianglesInit_5b(21,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          4, 6, 5  // tri2
                          ),
    gsSPNTriangles_5b(7, 6, 8,    // tri0
                      9, 8, 10,   // tri1
                      11, 10, 12, // tri2
                      13, 14, 15  // tri3
                      ),
    gsSPNTriangles_5b(15, 16, 17, // tri0
                      16, 18, 19, // tri1
                      20, 21, 22, // tri2
                      20, 18, 21  // tri3
                      ),
    gsSPNTriangles_5b(2, 22, 0,   // tri0
                      23, 24, 25, // tri1
                      23, 26, 24, // tri2
                      23, 5, 26   // tri3
                      ),
    gsSPNTriangles_5b(5, 7, 26,  // tri0
                      7, 27, 26, // tri1
                      28, 27, 9, // tri2
                      28, 9, 11  // tri3
                      ),
    gsSPNTriangles_5b(7, 9, 27,   // tri0
                      29, 30, 31, // tri1
                      0, 0, 0,    // tri2
                      0, 0, 0     // tri3
                      ),
    gsSPVertex(&grd_s_c6_r3_1_v[207], 18, 0),
    gsSPNTrianglesInit_5b(14,      // tri count
                          0, 1, 2, // tri0
                          0, 3, 1, // tri1
                          4, 5, 0  // tri2
                          ),
    gsSPNTriangles_5b(0, 5, 3, // tri0
                      4, 6, 5, // tri1
                      6, 7, 5, // tri2
                      7, 8, 9  // tri3
                      ),
    gsSPNTriangles_5b(7, 6, 8,   // tri0
                      8, 10, 9,  // tri1
                      10, 11, 9, // tri2
                      11, 12, 9  // tri3
                      ),
    gsSPNTriangles_5b(11, 13, 12, // tri0
                      13, 14, 12, // tri1
                      15, 16, 17, // tri2
                      0, 0, 0     // tri3
                      ),
    gsDPLoadTextureBlock_4b_Dolphin(river_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_c6_r3_1_v[225], 32, 0),
    gsSPNTrianglesInit_5b(15,      // tri count
                          0, 1, 2, // tri0
                          0, 3, 1, // tri1
                          4, 5, 6  // tri2
                          ),
    gsSPNTriangles_5b(6, 7, 8,    // tri0
                      9, 10, 8,   // tri1
                      11, 12, 10, // tri2
                      13, 14, 12  // tri3
                      ),
    gsSPNTriangles_5b(13, 15, 16, // tri0
                      17, 18, 15, // tri1
                      19, 20, 18, // tri2
                      20, 21, 22  // tri3
                      ),
    gsSPNTriangles_5b(23, 24, 22, // tri0
                      25, 26, 24, // tri1
                      26, 27, 28, // tri2
                      29, 30, 28  // tri3
                      ),
    gsSPVertex(&grd_s_c6_r3_1_v[256], 32, 0),
    gsSPNTrianglesInit_5b(19,      // tri count
                          0, 1, 2, // tri0
                          3, 4, 5, // tri1
                          4, 6, 7  // tri2
                          ),
    gsSPNTriangles_5b(6, 8, 9,    // tri0
                      10, 8, 11,  // tri1
                      12, 13, 14, // tri2
                      12, 11, 13  // tri3
                      ),
    gsSPNTriangles_5b(15, 16, 17, // tri0
                      18, 19, 20, // tri1
                      0, 21, 1,   // tri2
                      22, 23, 21  // tri3
                      ),
    gsSPNTriangles_5b(21, 0, 22,  // tri0
                      23, 24, 25, // tri1
                      26, 27, 25, // tri2
                      28, 29, 27  // tri3
                      ),
    gsSPNTriangles_5b(23, 22, 24, // tri0
                      25, 24, 26, // tri1
                      27, 26, 28, // tri2
                      11, 30, 31  // tri3
                      ),
    gsSPVertex(&grd_s_c6_r3_1_v[288], 13, 0),
    gsSPNTrianglesInit_5b(9,       // tri count
                          0, 1, 2, // tri0
                          1, 3, 2, // tri1
                          4, 5, 3  // tri2
                          ),
    gsSPNTriangles_5b(6, 7, 5,    // tri0
                      8, 9, 10,   // tri1
                      10, 11, 12, // tri2
                      1, 4, 3     // tri3
                      ),
    gsSPNTriangles_5b(5, 4, 6,   // tri0
                      9, 11, 10, // tri1
                      0, 0, 0,   // tri2
                      0, 0, 0    // tri3
                      ),
    gsSPEndDisplayList(),
};
