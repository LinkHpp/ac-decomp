extern u16 int_tak_tailor_off_pal[];
extern u16 int_tak_tailor_on_pal[];

static void fTTR_ct(FTR_ACTOR* ftr_actor, u8* data) {
    ftr_actor->pal_p = (u16*)zelda_malloc_align(16 * sizeof(u16), 32);
    fFTR_MorphHousepaletteCt(ftr_actor->pal_p, int_tak_tailor_off_pal, int_tak_tailor_on_pal, ftr_actor);
}

static void fTTR_mv(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data) {
    fFTR_MorphHousePalette(ftr_actor->pal_p, int_tak_tailor_off_pal, int_tak_tailor_on_pal, ftr_actor);
}

static void fTTR_dt(FTR_ACTOR* ftr_actor, u8* data) {
    if (ftr_actor->pal_p != NULL) {
        zelda_free(ftr_actor->pal_p);
    }
}

extern Gfx int_tak_tailor_on_model[];
extern Gfx int_tak_tailor_onT_model[];
extern Gfx int_tak_tailor_offT_model[];

static void fTTR_dw(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data) {
    u16* pal_p = ftr_actor->pal_p;

    OPEN_DISP(game->graph);

    gSPMatrix(NEXT_POLY_OPA_DISP, _Matrix_to_Mtx_new(game->graph), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPSegment(NEXT_POLY_OPA_DISP, G_MWO_SEGMENT_8, pal_p);
    gSPDisplayList(NEXT_POLY_OPA_DISP, int_tak_tailor_on_model);
    gSPDisplayList(NEXT_POLY_OPA_DISP, int_tak_tailor_onT_model);
    gSPDisplayList(NEXT_POLY_OPA_DISP, int_tak_tailor_offT_model);

    CLOSE_DISP(game->graph);
}

static aFTR_vtable_c fTTR_func = {
    &fTTR_ct, &fTTR_mv, &fTTR_dw, &fTTR_dt, NULL,
};

aFTR_PROFILE iam_tak_tailor = {
    // clang-format off
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	15.7f,
	0.01f,
	aFTR_SHAPE_TYPEA,
	mCoBG_FTR_TYPEA,
	0,
	0,
	0,
	0,
	&fTTR_func,
    // clang-format on
};
