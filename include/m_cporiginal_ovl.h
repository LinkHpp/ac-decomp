#ifndef M_CPORIGINAL_OVL_H
#define M_CPORIGINAL_OVL_H

#include "types.h"
#include "m_submenu_ovl.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void mCO_swap_image(Submenu* submenu, mActor_name_t item0, mActor_name_t item1);
extern int mCO_top_folder(Submenu* submenu);
extern int mCO_check_hide_flg(Submenu* submenu, int folder, int idx);
extern void mCO_on_hide_flg(Submenu* submenu, int folder, int idx);
extern void mCO_clear_hide_flg(Submenu* submenu);
extern void mCO_draw_cporiginal(Submenu* submenu, GRAPH* graph, f32 pos_x, f32 pos_y, f32 scale, int idx,
                                int color_flag);

extern void mCO_cporiginal_ovl_construct(Submenu* submenu);
extern void mCO_cporiginal_ovl_destruct(Submenu* submenu);
extern void mCO_cporiginal_ovl_set_proc(Submenu* submenu);

#ifdef __cplusplus
}
#endif

#endif
