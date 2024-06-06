#include "jaudio_NES/melody.h"

#include "jaudio_NES/game64_cpp.h"
#include "jaudio_NES/sub_sys.h"
#include "jaudio_NES/system.h"
#include "jaudio_NES/audiowork.h"

static s32 current_sub_track = 0;
u32 na_melody_id_hist[2];

// clang-format off
static const s32 melody_seq_size[] = {
    0x120,
    0x1C0,
    0x1E0,
    0x120,
    0x120,
    0x120,
    0x1A0,
    0x1E0,
    0x180,
    0x1A0,
    0x140,
    0x1A0,
    0x1A0,
    0x280,
    0x1C0,
    0x140,
    0x120,
    0x280,
    0x180,
    0x120,
    0x160,
    0x120,
    0x1A0,
    0x100,
    0x100,
    0x1A0,
    0x260,
    0x120,
    0x120,
    0x100,
    0x120,
    0x1C0,
    0x1C0,
    0x100,
    0x260,
    0x1C0,
    0x1C0,
    0x2A0,
    0x2A0,
    0x260,
    0x340,
    0x2A0,
    0x300,
    0x2A0,
    0x360,
    0x2A0,
    0x180,
    0x140,
    0x120,
    0x120,
    0x2E0,
    0x120,
    0x1C0,
    0x180,
    0x160,
    0x140,
    0x120,
    0x120,
    0x140,
    0x120,
    0x120,
    0x180,
    0x120,
    0x160,
    0x120,
    0x120,
    0x120,
    0x1C0,
    0x1A0,
    0x1C0,
    0x1C0,
    0x1C0,
    0x1C0,
    0x1A0,
    0x260,
    0x1A0,
    0x1A0,
    0x120,
    0x180,
    0x100,
    0x1C0,
    0x100,
    0x1A0,
    0x240,
    0x180,
    0x1C0,
    0x140,
    0x120,
    0x100,
    0x1A0,
    0x120,
    0x260,
    0x1C0,
    0x100,
    0x180,
    0x1C0,
    0x120,
    0x3A0,
    0x120,
    0x180,
    0x1C0,
    0x120,
    0x1E0,
    0x260,
    0x1C0,
    0x100,
    0x1C0,
    0x1E0,
    0x120,
    0x120,
    0x120,
    0x140,
    0x120,
    0x120,
    0x120,
    0x180,
    0x120,
    0x120,
    0x120,
    0x1C0,
    0x120,
    0x260,
    0x1C0,
    0x140,
    0x280,
    0x300,
    0x320,
    0x280,
    0x280,
    0x280,
    0x340,
    0x280,
    0x280,
    0x340,
    0x1C0,
    0x1C0,
    0x1C0,
    0x1A0,
    0x1A0,
    0x1E0,
    0x1E0,
    0x1E0,
    0x1C0,
    0x3A0,
    0x1A0,
    0x1E0,
    0x1C0,
    0x1C0,
    0x100,
    0x1C0,
    0x120,
    0x120,
    0x100,
    0x120,
    0x1C0,
    0x1C0,
    0x1E0,
    0x1E0,
    0x2A0,
    0x1E0,
    0x1C0,
    0x2A0,
    0x1E0,
    0x1C0,
    0x120,
    0x120,
    0x120,
    0x180,
    0x120,
    0x260,
    0x120,
    0x100,
    0x120,
    0x120,
    0x1E0,
    0x120,
    0x280,
    0x1C0,
    0x2C0,
    0x1E0,
    0x1E0,
    0x1E0,
    0x2A0,
    0x1E0,
    0x1C0,
    0x1E0,
    0x1E0,
    0x1C0,
    0x160,
    0x100,
    0x160,
    0x1C0,
    0x180,
    0x100,
    0x100,
    0x120,
    0x1E0,
    0x1E0,
    0x3A0,
    0x180,
    0x2A0,
    0x180,
    0x100,
    0x120,
    0x100,
    0x180,
    0x260,
    0x120,
    0x100,
    0x180,
    0x120,
    0x120,
    0x100,
    0x100,
    0x120,
    0x180,
    0x120,
    0x100,
    0x180,
    0x120,
    0x120,
    0x120,
    0x120,
    0x100,
    0x120,
    0x1C0,
    0x120,
    0x120,
    0x180,
    0x120,
    0x120,
    0x160,
    0x120,
    0x120,
    0x100,
    0x100,
    0x120,
    0x120,
    0x120,
    0x120,
    0x120,
    0x120,
    0x100,
    0x180,
    0x1C0,
    0x1C0,
    0x140,
    0x1E0,
    0x120,
    0x120,
    0x180,
    0x1C0,
    0x120,
    0x120,
    0x120,
    0x120,
    0x120,
    0x120,
    0x120,
    0x100,
    0x1C0,
    0x1C0,
    0x1A0,
    0x260,
    0x1A0,
    0x260,
    0x1C0,
    0x1A0,
    0x1A0,
    0x260,
    0x1C0,
    0x1C0,
    0x1A0,
    0x260,
    0x1A0,
    0x1A0,
    0x1A0,
    0x280,
    0x180,
    0x220,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
    0x1C0,
    0x120,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
    0x100,
};
// clang-format on

// clang-format off
static const s32 melody_seq_offset[] = {
    0x00000,
    0x00120,
    0x002E0,
    0x004C0,
    0x005E0,
    0x00700,
    0x00820,
    0x009C0,
    0x00BA0,
    0x00D20,
    0x00EC0,
    0x01000,
    0x011A0,
    0x01340,
    0x015C0,
    0x01780,
    0x018C0,
    0x019E0,
    0x01C60,
    0x01DE0,
    0x01F00,
    0x02060,
    0x02180,
    0x02320,
    0x02420,
    0x02520,
    0x026C0,
    0x02920,
    0x02A40,
    0x02B60,
    0x02C60,
    0x02D80,
    0x02F40,
    0x03100,
    0x03200,
    0x03460,
    0x03620,
    0x037E0,
    0x03A80,
    0x03D20,
    0x03F80,
    0x042C0,
    0x04560,
    0x04860,
    0x04B00,
    0x04E60,
    0x05100,
    0x05280,
    0x053C0,
    0x054E0,
    0x05600,
    0x058E0,
    0x05A00,
    0x05BC0,
    0x05D40,
    0x05EA0,
    0x05FE0,
    0x06100,
    0x06220,
    0x06360,
    0x06480,
    0x065A0,
    0x06720,
    0x06840,
    0x069A0,
    0x06AC0,
    0x06BE0,
    0x06D00,
    0x06EC0,
    0x07060,
    0x07220,
    0x073E0,
    0x075A0,
    0x07760,
    0x07900,
    0x07B60,
    0x07D00,
    0x07EA0,
    0x07FC0,
    0x08140,
    0x08240,
    0x08400,
    0x08500,
    0x086A0,
    0x088E0,
    0x08A60,
    0x08C20,
    0x08D60,
    0x08E80,
    0x08F80,
    0x09120,
    0x09240,
    0x094A0,
    0x09660,
    0x09760,
    0x098E0,
    0x09AA0,
    0x09BC0,
    0x09F60,
    0x0A080,
    0x0A200,
    0x0A3C0,
    0x0A4E0,
    0x0A6C0,
    0x0A920,
    0x0AAE0,
    0x0ABE0,
    0x0ADA0,
    0x0AF80,
    0x0B0A0,
    0x0B1C0,
    0x0B2E0,
    0x0B420,
    0x0B540,
    0x0B660,
    0x0B780,
    0x0B900,
    0x0BA20,
    0x0BB40,
    0x0BC60,
    0x0BE20,
    0x0BF40,
    0x0C1A0,
    0x0C360,
    0x0C4A0,
    0x0C720,
    0x0CA20,
    0x0CD40,
    0x0CFC0,
    0x0D240,
    0x0D4C0,
    0x0D800,
    0x0DA80,
    0x0DD00,
    0x0E040,
    0x0E200,
    0x0E3C0,
    0x0E580,
    0x0E720,
    0x0E8C0,
    0x0EAA0,
    0x0EC80,
    0x0EE60,
    0x0F020,
    0x0F3C0,
    0x0F560,
    0x0F740,
    0x0F900,
    0x0FAC0,
    0x0FBC0,
    0x0FD80,
    0x0FEA0,
    0x0FFC0,
    0x100C0,
    0x101E0,
    0x103A0,
    0x10560,
    0x10740,
    0x10920,
    0x10BC0,
    0x10DA0,
    0x10F60,
    0x11200,
    0x113E0,
    0x115A0,
    0x116C0,
    0x117E0,
    0x11900,
    0x11A80,
    0x11BA0,
    0x11E00,
    0x11F20,
    0x12020,
    0x12140,
    0x12260,
    0x12440,
    0x12560,
    0x127E0,
    0x129A0,
    0x12C60,
    0x12E40,
    0x13020,
    0x13200,
    0x134A0,
    0x13680,
    0x13840,
    0x13A20,
    0x13C00,
    0x13DC0,
    0x13F20,
    0x14020,
    0x14180,
    0x14340,
    0x144C0,
    0x145C0,
    0x146C0,
    0x147E0,
    0x149C0,
    0x14BA0,
    0x14F40,
    0x150C0,
    0x15360,
    0x154E0,
    0x155E0,
    0x15700,
    0x15800,
    0x15980,
    0x15BE0,
    0x15D00,
    0x15E00,
    0x15F80,
    0x160A0,
    0x161C0,
    0x162C0,
    0x163C0,
    0x164E0,
    0x16660,
    0x16780,
    0x16880,
    0x16A00,
    0x16B20,
    0x16C40,
    0x16D60,
    0x16E80,
    0x16F80,
    0x170A0,
    0x17260,
    0x17380,
    0x174A0,
    0x17620,
    0x17740,
    0x17860,
    0x179C0,
    0x17AE0,
    0x17C00,
    0x17D00,
    0x17E00,
    0x17F20,
    0x18040,
    0x18160,
    0x18280,
    0x183A0,
    0x184C0,
    0x185C0,
    0x18740,
    0x18900,
    0x18AC0,
    0x18C00,
    0x18DE0,
    0x18F00,
    0x19020,
    0x191A0,
    0x19360,
    0x19480,
    0x195A0,
    0x196C0,
    0x197E0,
    0x19900,
    0x19A20,
    0x19B40,
    0x19C40,
    0x19E00,
    0x19FC0,
    0x1A160,
    0x1A3C0,
    0x1A560,
    0x1A7C0,
    0x1A980,
    0x1AB20,
    0x1ACC0,
    0x1AF20,
    0x1B0E0,
    0x1B2A0,
    0x1B440,
    0x1B6A0,
    0x1B840,
    0x1B9E0,
    0x1BB80,
    0x1BE00,
    0x1BF80,
    0x1C1A0,
    0x1C2A0,
    0x1C3A0,
    0x1C4A0,
    0x1C5A0,
    0x1C6A0,
    0x1C860,
    0x1C980,
    0x1CA80,
    0x1CB80,
    0x1CC80,
    0x1CD80,
    0x1CE80,
    0x1CF80,
    0x1D080,
    0x1D180,
    0x1D280,
    0x1D380,
    0x1D480,
};
// clang-format on

static void Na_MelodyStart(u16 voice, s16 subTrack, const u8* pData);

extern void Na_MelodyInit(void) {
    current_sub_track = 0;
    na_melody_id_hist[0] = 0xFFFFFFFF;
    na_melody_id_hist[1] = 0xFFFFFFFF;
}

extern void Na_Inst(u16 inst, u8* pData) {
    if (!sou_chime_status && (inst == 0xFF || inst == 0xFE)) {
        return;
    }

    Na_MelodyStart(inst, Na_MelodyGetSubTrackNum(inst), pData);
    Nap_SetF32(NA_MAKE_COMMAND(0x01, 0x00, 0x06, 0x00), 1.0f);
}

static void Na_MelodyStart(u16 voice, s16 subTrack, const u8* pData) {
    Nap_SetS8(NA_MAKE_COMMAND(0x06, 0x00, subTrack, 0x00), 1);
    s32 unused = Nap_SendStart();
    Nap_WaitVsync();

    u8* dst;
    s16 seq_idx = 248;
    u16 size = ((u16*)AG.groups[0].seq_data)[2];

    switch (subTrack) {
        case 6:
            break;
        case 7:
            size += 0x600;
            break;
        case 15:
            size += 0xC00;
            break;
    }

    u8* src;

    dst = AG.groups[0].seq_data + size;
    ArcHeader* seq_header = AG.seq_header;
    size_t seq_size = melody_seq_size[voice];
    int medium = seq_header->entries[seq_idx].medium;
    src = (u8*)seq_header->entries[seq_idx].addr + melody_seq_offset[voice];
    // clang-format off
    Nas_FastCopy(
        src,        /* Voice melody data is broken up in single sequence */
        dst,        /* Destination buffer */
        seq_size,   /* melody sequence size */
        medium      /* medium (always cart in AC?) */
    );
    // clang-format on

    u16* dst16 = (u16*)(dst + 4);
    for (int i = 0; i < 19; i++) {
        dst16[i] += size;
    }

    Nap_SetS32(NA_MAKE_COMMAND(0x10, 0x00, subTrack, 0x00), (u64)pData);
    Nap_SetS8(NA_MAKE_COMMAND(0x06, 0x00, subTrack, 0x02), voice);
    Nap_SetS8(NA_MAKE_COMMAND(0x06, 0x00, subTrack, 0x00), 0);
}

extern s8 Na_InstCountGet(void) {
    s8 count = Nap_ReadSubPort(0, 6, 4);
    count--;
    return count;
}

extern s16 Na_MelodyGetSubTrackNum(s16 inst) {
    if (inst == 0) {
        return 6;
    } else if (inst == 255 || inst == 254) {
        return 7;
    } else {
        return 15;
    }
}

extern void Na_FurnitureInst(u32 id, u8 inst, u8* melody, u16 angle, f32 dist) {
    s32 sub_track;

    if (id == na_melody_id_hist[current_sub_track]) {
        sub_track = current_sub_track;
    } else {
        s32 tmp;
        if (current_sub_track == 0) {
            tmp = 1;
        } else {
            tmp = 0;
        }

        sub_track = tmp;
    }

    na_melody_id_hist[sub_track] = id;
    current_sub_track = sub_track;
    sub_track += 14;
    u8 pan = angle2pan(angle, dist);
    f32 vol = distance2vol(dist);

    Nap_SetS32(NA_MAKE_COMMAND(0x10, 0x02, sub_track, 0x00), (u64)melody);
    Nap_SetS8(NA_MAKE_COMMAND(0x06, 0x02, sub_track, 0x02), inst);
    Nap_SetS8(NA_MAKE_COMMAND(0x06, 0x02, sub_track, 0x00), 0);
    Nap_SetF32(NA_MAKE_COMMAND(0x01, 0x02, sub_track, 0x00), vol);
    Nap_SetS8(NA_MAKE_COMMAND(0x03, 0x02, sub_track, 0x00), pan);
}

extern void Na_MelodyVoice(s16 voice) {
    static const u8 melody[16] = { 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14 };

    Na_MelodyStart(voice, 6, melody);
    Nap_SetF32(NA_MAKE_COMMAND(0x01, 0x00, 0x06, 0x00), 1.3f);
}
