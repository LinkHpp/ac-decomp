#include "libu64/gfxprint.h"
#include "libc64/aprintf.h"

static u8 gfxprint_font[] = {
    0x00, 0xdf, 0xfd, 0x00, 0x0a, 0xee, 0xff, 0xa0, 0x0d, 0xf2, 0x2d, 0xd0, 0x06, 0x61, 0x1d, 0xc0,
    0x01, 0x12, 0x2d, 0xd0, 0x06, 0x71, 0x99, 0x00, 0x01, 0x1e, 0xed, 0x10, 0x07, 0x7e, 0xf7, 0x00,
    0x01, 0x56, 0x29, 0x90, 0x05, 0x58, 0x97, 0x60, 0x0d, 0xd2, 0x29, 0x90, 0x05, 0x59, 0x97, 0x70,
    0x04, 0xdf, 0xfd, 0x40, 0x02, 0x6e, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0xbf, 0xfb, 0x00, 0x0e, 0xff, 0xff, 0xc0, 0x0b, 0xf0, 0x0f, 0xb0, 0x0f, 0xf0, 0x03, 0x30,
    0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x02, 0x20, 0x0c, 0xfb, 0xbf, 0x60, 0x0f, 0xfc, 0xce, 0x20,
    0x0d, 0xd4, 0x4f, 0xf0, 0x0f, 0xf0, 0x02, 0x20, 0x0f, 0xf0, 0x0f, 0xf0, 0x0f, 0xf0, 0x03, 0x30,
    0x0c, 0xfb, 0xbf, 0x40, 0x0e, 0xf7, 0x77, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xdf, 0xfd, 0x00, 0x0a, 0xee, 0xff, 0xa0, 0x0d, 0xf2, 0x2d, 0xd0, 0x06, 0x61, 0x1d, 0xc0,
    0x01, 0x12, 0x2d, 0xd0, 0x06, 0x71, 0x99, 0x00, 0x01, 0x1e, 0xed, 0x10, 0x07, 0x7e, 0xf7, 0x00,
    0x01, 0x56, 0x29, 0x90, 0x05, 0x58, 0x97, 0x60, 0x0d, 0xd2, 0x29, 0x90, 0x05, 0x59, 0x97, 0x70,
    0x04, 0xdf, 0xfd, 0x40, 0x02, 0x6e, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0xbf, 0xfb, 0x00, 0x00, 0x0d, 0xe0, 0x00, 0x0b, 0xf0, 0x0f, 0xb0, 0x00, 0x5d, 0xe6, 0x00,
    0x0f, 0xf0, 0x0f, 0xf0, 0x05, 0x5c, 0xc6, 0x60, 0x0c, 0xfb, 0xbf, 0x60, 0x77, 0x3f, 0xf3, 0x77,
    0x0d, 0xd4, 0x4f, 0xf0, 0xbb, 0x3f, 0xf3, 0xbb, 0x0f, 0xf0, 0x0f, 0xf0, 0x09, 0x9c, 0xca, 0xa0,
    0x0c, 0xfb, 0xbf, 0x40, 0x00, 0x9d, 0xea, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0xe0, 0x00,
    0x04, 0xc2, 0x2c, 0x40, 0x02, 0x8d, 0x50, 0x20, 0x0c, 0xca, 0xac, 0xc0, 0x21, 0xf9, 0x17, 0x10,
    0x04, 0xc2, 0x2c, 0x40, 0x12, 0x49, 0x34, 0x00, 0x00, 0x82, 0x08, 0x00, 0x01, 0x97, 0x51, 0x10,
    0x08, 0x8a, 0x88, 0x80, 0x04, 0x61, 0x52, 0x41, 0x00, 0x80, 0x08, 0x00, 0x43, 0x11, 0x75, 0x30,
    0x00, 0xa2, 0x08, 0x00, 0x60, 0x05, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x40, 0x00, 0x40,
    0x00, 0x22, 0x11, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x0f, 0xb0, 0x00, 0x00, 0x00, 0x08, 0x80,
    0x04, 0x0d, 0xa4, 0x00, 0x00, 0x00, 0x88, 0x00, 0x08, 0xcd, 0xe8, 0x80, 0x02, 0x2a, 0xa2, 0x20,
    0x08, 0xcd, 0xe8, 0x80, 0x02, 0xaa, 0x22, 0x20, 0x04, 0x0d, 0xa4, 0x00, 0x0c, 0xd1, 0x00, 0x00,
    0x00, 0x0f, 0xb0, 0x00, 0x8c, 0x51, 0x00, 0x00, 0x00, 0x22, 0x11, 0x00, 0x81, 0x10, 0x00, 0x00,
    0x00, 0xdf, 0xfd, 0x00, 0x0a, 0xee, 0xff, 0xa0, 0x0d, 0xf2, 0x2d, 0xd0, 0x06, 0x61, 0x1d, 0xc0,
    0x01, 0x12, 0x2d, 0xd0, 0x06, 0x71, 0x99, 0x00, 0x01, 0x1e, 0xed, 0x10, 0x07, 0x7e, 0xf7, 0x00,
    0x01, 0x56, 0x29, 0x90, 0x05, 0x58, 0x97, 0x60, 0x0d, 0xd2, 0x29, 0x90, 0x05, 0x59, 0x97, 0x70,
    0x04, 0xdf, 0xfd, 0x40, 0x02, 0x6e, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x33, 0x33, 0x00, 0x04, 0x48, 0x99, 0x80, 0x03, 0x3c, 0xc3, 0x30, 0x00, 0xcd, 0x10, 0x88,
    0x03, 0x3c, 0xc3, 0x30, 0x02, 0xbf, 0x62, 0xa8, 0x00, 0x33, 0x33, 0x20, 0x01, 0x10, 0x4c, 0x80,
    0x01, 0x10, 0x03, 0x30, 0x00, 0x15, 0xc8, 0x00, 0x03, 0x3c, 0xc3, 0x30, 0x02, 0x67, 0x32, 0x20,
    0x00, 0x3f, 0xf3, 0x00, 0x04, 0x40, 0x99, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x05, 0xdf, 0xfd, 0x10, 0x07, 0xff, 0xff, 0x60, 0x1c, 0xe0, 0x0e, 0xc1, 0x0f, 0xf0, 0x09, 0x90,
    0x1e, 0xe1, 0x16, 0x61, 0x0f, 0xf0, 0x01, 0x10, 0x1e, 0xf4, 0x56, 0x21, 0x0f, 0xf6, 0x67, 0x10,
    0x1e, 0xf2, 0x36, 0x61, 0x0f, 0xf0, 0x89, 0x90, 0x1e, 0xf1, 0x0f, 0xe1, 0x0f, 0xf0, 0x09, 0x90,
    0x16, 0xec, 0xce, 0x21, 0x07, 0xfb, 0xbb, 0x20, 0x01, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x09, 0xb6, 0x6f, 0xd0, 0x27, 0xd8, 0x8e, 0x60, 0x09, 0x92, 0xed, 0x10, 0x2f, 0xf0, 0x2e, 0xe0,
    0x09, 0x9a, 0xe5, 0x10, 0x2f, 0xf6, 0x2e, 0xe0, 0x09, 0x9b, 0x75, 0x10, 0x2f, 0xd6, 0x4e, 0xe0,
    0x0d, 0xda, 0xe5, 0x10, 0x2f, 0xd0, 0x4e, 0xe0, 0x0d, 0xd2, 0xed, 0x10, 0x2f, 0xd0, 0x0e, 0xe0,
    0x09, 0xf6, 0x6f, 0x90, 0x27, 0xd9, 0x9f, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0xff, 0xff, 0x00, 0x8f, 0x71, 0x1f, 0xf0, 0x2f, 0xd0, 0x0f, 0xf0, 0x8f, 0x71, 0x1f, 0xf0,
    0x2f, 0xd0, 0x07, 0x70, 0x8e, 0x61, 0x1e, 0xe0, 0x27, 0xdd, 0xdf, 0x60, 0x8e, 0x69, 0x1e, 0xe0,
    0x27, 0x76, 0x4a, 0xa0, 0x8e, 0xe9, 0x9e, 0xe0, 0x2f, 0xd0, 0x6e, 0x80, 0x8a, 0xe7, 0xfe, 0xa0,
    0x07, 0xfa, 0x8e, 0x60, 0x88, 0x27, 0x7a, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x7c, 0xcf, 0xf0, 0x13, 0x26, 0x60, 0x11, 0x07, 0x7c, 0xcf, 0xf0, 0x03, 0x76, 0x65, 0x10,
    0x02, 0x39, 0xd7, 0x20, 0x04, 0x53, 0x35, 0x40, 0x00, 0x2f, 0xf2, 0x00, 0x01, 0x13, 0x31, 0x10,
    0x00, 0x5f, 0xb1, 0x00, 0x00, 0x03, 0x30, 0x00, 0x05, 0x5e, 0xe5, 0x50, 0x01, 0x13, 0x31, 0x10,
    0x05, 0x5e, 0xed, 0xd0, 0x02, 0x23, 0x30, 0x00, 0x00, 0x08, 0x88, 0x80, 0x8a, 0xab, 0xb8, 0x88,
    0x00, 0x00, 0x11, 0x00, 0x00, 0x04, 0x45, 0x10, 0x04, 0x62, 0x33, 0x20, 0x00, 0x44, 0x01, 0x10,
    0x04, 0xc8, 0x9a, 0xa0, 0x00, 0xee, 0xab, 0x10, 0x0c, 0xe6, 0x67, 0x20, 0x0e, 0xf5, 0x5f, 0xb0,
    0x0e, 0xe0, 0x06, 0x60, 0x0b, 0xf6, 0x2b, 0x90, 0x0e, 0xe0, 0x06, 0x60, 0x03, 0xfc, 0x89, 0x90,
    0x04, 0xee, 0xee, 0xa0, 0x00, 0x77, 0x3b, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x08, 0x88, 0x88, 0x00,
    0x09, 0x90, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x09, 0x92, 0x24, 0x40, 0x00, 0x01, 0x10, 0x00,
    0x09, 0x90, 0x88, 0x00, 0x26, 0xef, 0xde, 0x20, 0x09, 0x9b, 0xb5, 0x40, 0x2e, 0xc3, 0x3c, 0xe2,
    0x0d, 0x9a, 0x25, 0x50, 0x2e, 0xc3, 0x3c, 0xe2, 0x0d, 0xda, 0xa5, 0x50, 0x2e, 0xc3, 0x3c, 0xe2,
    0x09, 0xd6, 0xed, 0x10, 0x26, 0xcb, 0xbc, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00,
    0x05, 0xfb, 0xff, 0xe0, 0x8e, 0x61, 0x16, 0xe8, 0x0f, 0xf4, 0x03, 0x30, 0x8f, 0x71, 0x17, 0xf8,
    0x07, 0xfc, 0x8b, 0x30, 0x8e, 0x69, 0x96, 0xe8, 0x05, 0x73, 0x3b, 0xa0, 0x8a, 0x6d, 0xd6, 0xa8,
    0x0d, 0xd8, 0x8a, 0x20, 0x08, 0xa7, 0x79, 0xb2, 0x01, 0x10, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0x8a, 0x01, 0x10, 0x00, 0x00, 0x00, 0x08, 0x00, 0x80, 0xa1, 0x10, 0x00,
    0x07, 0x74, 0x4f, 0x70, 0x80, 0xa9, 0x90, 0x00, 0x02, 0x31, 0xdf, 0x20, 0x84, 0xe6, 0x00, 0x04,
    0x00, 0x27, 0xda, 0x20, 0xc8, 0xaa, 0x4c, 0x40, 0x00, 0x57, 0x3b, 0x20, 0x00, 0xa1, 0x18, 0x00,
    0x05, 0x54, 0x6f, 0x50, 0x00, 0xa9, 0x98, 0x00, 0x02, 0x22, 0x20, 0x80, 0x02, 0x00, 0x18, 0x88,
    0x00, 0x04, 0x44, 0x40, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x44, 0x40, 0x0c, 0x44, 0x44, 0x00,
    0x00, 0x04, 0x40, 0x00, 0x88, 0xc0, 0x00, 0x00, 0x00, 0x0c, 0xc0, 0x00, 0x0c, 0x46, 0xa4, 0x40,
    0x00, 0x0c, 0xc0, 0x00, 0x08, 0x8e, 0xe0, 0x00, 0x02, 0x08, 0x80, 0x00, 0x80, 0xd0, 0x88, 0x00,
    0x28, 0xa8, 0x80, 0x00, 0x88, 0xcd, 0x4c, 0x40, 0x0a, 0x88, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xe0, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x88, 0x00, 0x80, 0x01, 0x06, 0x10, 0x00, 0x56, 0xe7, 0x50, 0x80, 0x02, 0x1f, 0xf1, 0x00,
    0x38, 0x8c, 0xb8, 0x00, 0x0b, 0xf6, 0x0b, 0x00, 0x94, 0xc0, 0x28, 0x00, 0x06, 0x07, 0x6a, 0x00,
    0xcb, 0xa6, 0xc8, 0x00, 0x00, 0x47, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0a, 0x80, 0x00, 0x00, 0x39, 0x14, 0x20, 0x02, 0x22, 0x24, 0x00, 0x08, 0xae, 0xa8, 0x60,
    0x04, 0x28, 0x99, 0x70, 0x07, 0x75, 0xd1, 0x04, 0x0f, 0xb3, 0x33, 0xd0, 0x00, 0xae, 0xbe, 0xa4,
    0x25, 0x15, 0x20, 0xa0, 0x02, 0x61, 0x0c, 0x02, 0x20, 0x42, 0x08, 0x20, 0x2c, 0x30, 0x14, 0x02,
    0x02, 0x28, 0x82, 0x00, 0x03, 0xac, 0xc1, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x12, 0x00, 0x08, 0x00, 0x28, 0x00, 0x0a, 0xcf, 0xee, 0x20, 0x0b, 0x62, 0x2e, 0x20,
    0x02, 0x10, 0x82, 0x40, 0x01, 0x44, 0xe4, 0x40, 0x03, 0x00, 0x0e, 0x00, 0x8d, 0xea, 0xac, 0x00,
    0x02, 0x10, 0x0a, 0x00, 0x01, 0xe0, 0x24, 0x00, 0x0c, 0x21, 0x02, 0x00, 0x09, 0x42, 0x21, 0x00,
    0x00, 0xcc, 0xf4, 0x40, 0x02, 0xbf, 0xd4, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x44, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x44, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x04, 0x40, 0x00, 0x0c, 0xcc, 0xc4, 0x40, 0x00, 0x0c, 0xc0, 0x00, 0x00, 0x02, 0xa0, 0x40,
    0x00, 0x0c, 0xc0, 0x00, 0x04, 0xce, 0x64, 0x40, 0x02, 0x08, 0x80, 0x00, 0x00, 0x90, 0x00, 0x40,
    0x28, 0xa8, 0x80, 0x00, 0x08, 0x01, 0x04, 0x00, 0x0a, 0x88, 0x80, 0x00, 0x04, 0x44, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x29, 0x00, 0x00, 0x00, 0x54, 0x44, 0x00, 0xee, 0xfe, 0xe0, 0x00, 0x09, 0x3b, 0x3f, 0x00,
    0x21, 0xd8, 0x20, 0x00, 0x00, 0x54, 0x4f, 0x00, 0x18, 0x58, 0x20, 0x00, 0x00, 0x01, 0x86, 0x00,
    0xc6, 0x7e, 0x40, 0x00, 0x00, 0xef, 0x66, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x04, 0x00, 0x00, 0xc0, 0x20, 0x00, 0xaa, 0xaa, 0xea, 0x20, 0xef, 0xff, 0xff, 0x00,
    0x80, 0x44, 0x19, 0x30, 0x00, 0x49, 0x24, 0x00, 0xc5, 0x35, 0x1b, 0x10, 0x00, 0x4b, 0x24, 0x00,
    0x01, 0x35, 0xa0, 0x00, 0x8c, 0xa9, 0xac, 0x80, 0x00, 0x2c, 0x00, 0x00, 0x04, 0x21, 0xa4, 0x00,
    0x2a, 0x84, 0x00, 0x00, 0x73, 0x11, 0xf1, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0b, 0x11, 0x19, 0x00, 0x00, 0x40, 0x00, 0x00, 0x8f, 0xee, 0xef, 0xe0, 0x0b, 0x76, 0x66, 0xd0,
    0x1a, 0x00, 0x0b, 0x40, 0x4c, 0x40, 0x02, 0xd0, 0x28, 0x00, 0x1a, 0x40, 0x01, 0xd0, 0x2c, 0x10,
    0x00, 0x00, 0x38, 0x40, 0x00, 0x40, 0x28, 0x10, 0x00, 0x01, 0xa0, 0x40, 0x00, 0x42, 0x83, 0x00,
    0x05, 0xfe, 0x44, 0x40, 0x03, 0xfd, 0x54, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x99, 0x9b, 0x00, 0x00, 0x10, 0x20, 0x00, 0x07, 0x26, 0x21, 0x40, 0x2a, 0xfe, 0xee, 0xa0,
    0x8d, 0x8c, 0xa9, 0xc0, 0x00, 0x10, 0x20, 0x80, 0x32, 0x33, 0xb3, 0x60, 0x00, 0x19, 0x28, 0x00,
    0x00, 0x00, 0xa1, 0x40, 0x00, 0x10, 0xb1, 0x00, 0x00, 0x08, 0x34, 0x00, 0x00, 0x1a, 0x08, 0x00,
    0x05, 0xf7, 0x40, 0x00, 0x8e, 0xf4, 0x44, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x14, 0x02, 0x80, 0x00, 0x04, 0x00, 0x00, 0x1d, 0x11, 0xdb, 0x00, 0xdd, 0xfd, 0xdd, 0xd0,
    0x0c, 0x88, 0x07, 0x00, 0x02, 0x06, 0x00, 0x90, 0x48, 0x00, 0x34, 0x00, 0x2c, 0x04, 0x2c, 0x10,
    0x48, 0x11, 0x21, 0x40, 0x04, 0x84, 0x83, 0x40, 0x59, 0x03, 0x00, 0x50, 0x40, 0x0c, 0x10, 0x60,
    0x42, 0xa9, 0x88, 0xc0, 0x40, 0x15, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x11, 0x02, 0x00, 0x40, 0x08, 0x98, 0x88, 0x80, 0x08, 0xf9, 0x98, 0xc0, 0x06, 0x77, 0x75, 0x50,
    0x02, 0x0c, 0x05, 0x00, 0x19, 0x98, 0xa8, 0xd0, 0x0b, 0x99, 0xca, 0x80, 0x04, 0x54, 0x65, 0xc0,
    0x20, 0x08, 0x50, 0x20, 0x00, 0x10, 0x20, 0xc0, 0x31, 0x1c, 0x04, 0x20, 0x00, 0x01, 0x28, 0x40,
    0x26, 0x63, 0xbb, 0xe0, 0x26, 0xef, 0xe6, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x02, 0x01, 0x00, 0xc8, 0xc0, 0x00, 0x00, 0x0f, 0x8a, 0x89, 0x80, 0xc3, 0xf3, 0x11, 0x30,
    0x0f, 0x02, 0x01, 0x80, 0xc9, 0xc0, 0x00, 0x30, 0x0f, 0x02, 0x05, 0xa0, 0x00, 0x00, 0x00, 0x30,
    0x0e, 0x02, 0x05, 0xa0, 0x00, 0x00, 0x00, 0x30, 0x0e, 0x02, 0x52, 0x80, 0x00, 0x00, 0x03, 0x00,
    0x2c, 0xdf, 0xa8, 0x80, 0x02, 0x33, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x03, 0x88, 0x00, 0x01, 0x02, 0x80, 0x00, 0x03, 0xff, 0xf7, 0x00, 0x0f, 0x26, 0xe4, 0x72,
    0xcc, 0x38, 0x00, 0x40, 0x0c, 0x38, 0x99, 0x00, 0x03, 0x0a, 0x31, 0x50, 0x0c, 0xb1, 0x82, 0x80,
    0x03, 0x28, 0x06, 0x00, 0x87, 0x88, 0x2a, 0xa0, 0x01, 0x05, 0xc2, 0x00, 0x85, 0x82, 0xc2, 0x80,
    0x10, 0x00, 0x39, 0x10, 0x08, 0x51, 0xbf, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x80, 0x04, 0x00, 0x48, 0x9d, 0xcc, 0x40, 0xc9, 0xe6, 0x7f, 0x40, 0x40, 0x00, 0x94, 0x00,
    0x5b, 0x21, 0x0c, 0xb0, 0x48, 0xae, 0xcc, 0x40, 0xe1, 0x30, 0x0c, 0x30, 0x43, 0x01, 0xa4, 0x00,
    0xe1, 0x24, 0x5d, 0x30, 0x78, 0x8c, 0xd6, 0x10, 0xf1, 0x60, 0x94, 0x70, 0xd0, 0x40, 0x9c, 0x70,
    0x0b, 0x8c, 0x53, 0x00, 0x0c, 0x9d, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x39, 0x50, 0x00, 0x00, 0x88, 0xf0, 0x00, 0x2e, 0xaf, 0xc6, 0x00, 0x03, 0x01, 0x77, 0x60,
    0x04, 0xf0, 0x41, 0x60, 0x03, 0x92, 0xf8, 0x12, 0x0f, 0xbd, 0x91, 0x40, 0x1b, 0x28, 0x60, 0x92,
    0x70, 0xf4, 0x01, 0xf0, 0x0a, 0xd4, 0x65, 0x82, 0x53, 0xe0, 0x01, 0xe0, 0x04, 0x10, 0x68, 0x60,
    0x04, 0x2a, 0xbe, 0x00, 0x00, 0x4f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x3a, 0xee, 0x00, 0xc8, 0xc0, 0x00, 0x00, 0x0d, 0x84, 0xa5, 0x00, 0xc1, 0xc2, 0x11, 0x00,
    0x45, 0x0e, 0x27, 0x00, 0xd9, 0xc3, 0x00, 0x10, 0x07, 0xf8, 0x8d, 0x20, 0x01, 0x30, 0x00, 0x10,
    0xac, 0x02, 0x25, 0xa0, 0x01, 0x22, 0x00, 0x10, 0x44, 0x20, 0x16, 0xa0, 0x13, 0x02, 0x00, 0x30,
    0x04, 0x1b, 0xaa, 0x40, 0x21, 0x00, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static u16 gfxprint_moji_tlut[] = {
    0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0xffff, 0x0000, 0xffff,
	0x0000, 0x0000, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff, 0x0000, 0x0000, 0xffff, 0xffff,
	0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff,
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff
};

static void gfxprint_setup(gfxprint_t* this) {
    int i;
    int tile;

    /* Initialize RDP & RSP settings */
    gDPPipeSync(this->glistp++);
    gDPSetOtherMode(
        this->glistp++,
        G_AD_DISABLE | G_CD_DISABLE | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_IA16 | G_TL_TILE | G_TD_CLAMP | G_TP_NONE | G_CYC_1CYCLE | G_PM_NPRIMITIVE,
        G_RM_XLU_SURF | G_RM_XLU_SURF2 | G_ZS_PRIM
    );
    gDPSetCombineMode(this->glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);

    /* Initialize font texture */
    gDPLoadTextureBlock_4b(
        this->glistp++,
        gfxprint_font,
        G_IM_FMT_CI,
        16, 256, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
        0, 0, 0, 0
    );

    /* Load font palette */
    gDPLoadTLUT_palX(this->glistp++, 0, gfxprint_moji_tlut, 64);

    /* Initialize tile settings */
    for (i = 0, tile = 1; i < 3; i++, tile++) {
        gDPSetTile(this->glistp++, G_IM_FMT_CI, G_IM_SIZ_4b, ((((16)>>1)+7)>>3), 0, tile * 2, tile, G_TX_NOMIRROR | G_TX_CLAMP, 0, 0, G_TX_NOMIRROR | G_TX_CLAMP, 0, 0);
        gDPSetTileSize(this->glistp++, tile * 2, 0, 0, (16-1) << G_TEXTURE_IMAGE_FRAC, (256-1) << G_TEXTURE_IMAGE_FRAC);
    }

    /* Initialize font color */
    gDPSetColor(this->glistp++, G_SETPRIMCOLOR, this->color.rgba8888);
}

extern void gfxprint_color(gfxprint_t* this, u32 r, u32 g, u32 b, u32 a) {
    this->color.c.r = r;
    this->color.c.g = g;
    this->color.c.b = b;
    this->color.c.a = a;

    gDPPipeSync(this->glistp++);
    gDPSetColor(this->glistp++, G_SETPRIMCOLOR, this->color.rgba8888);
}

extern void gfxprint_locate(gfxprint_t* this, int x, int y) {
    this->position_x = this->offset_x + x * 4;
    this->position_y = this->offset_y + y * 4;
}

extern void gfxprint_locate8x8(struct gfxprint_obj* this, int x, int y) {
    gfxprint_locate(this, x * 8, y * 8);
}

static void gfxprint_putc1(gfxprint_t* this, char c) {
    int tile;
    int x0;
    int x1;
    
    tile = (c & 3) * 2;
    x0 = (c & 4) * 2;
    x1 = c & 0xF8;
    
    if (gfxprint_isChanged(this)) {
        gfxprint_clrChanged(this);
        gDPPipeSync(this->glistp++);
        gDPSetTextureLUT(this->glistp++, G_TT_IA16);
        gDPSetCycleType(this->glistp++, G_CYC_1CYCLE);
        gDPSetRenderMode(this->glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(this->glistp++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
    }

    if (gfxprint_isShadow(this)) {
        gDPSetColor(this->glistp++, G_SETPRIMCOLOR, 0);
        if (gfxprint_isHighres(this)) {
            gSPTextureRectangle(
                this->glistp++,
                (this->position_x + 4) << 1, (this->position_y + 4) << 1,
                (this->position_x + 32) << 1, (this->position_y + 32) << 1,
                tile,
                x0 << 5, x1 << 5,
                512, 512
            );
        }
        else {
            gSPTextureRectangle(
                this->glistp++,
                this->position_x + 4, this->position_y + 4,
                this->position_x + 32, this->position_y + 32,
                tile,
                x0 << 5, x1 << 5,
                1024, 1024
            );
        }
        gDPSetColor(this->glistp++, G_SETPRIMCOLOR, this->color.rgba8888);
    }

    if (gfxprint_isHighres(this)) {
        gSPTextureRectangle(
            this->glistp++,
            this->position_x << 1, this->position_y << 1,
            (this->position_x + 28) << 1, (this->position_y + 28) << 1,
            tile,
            x0 << 5, x1 << 5,
            512, 512
        );
    }
    else {
        gSPTextureRectangle(
            this->glistp++,
            this->position_x, this->position_y,
            this->position_x + 28, this->position_y + 28,
            tile,
            x0 << 5, x1 << 5,
            1024, 1024
        );
    }

    this->position_x += 32;
}


extern void gfxprint_putc(gfxprint_t* this, char c) {
    u8 param = c;

    if (param == ' ') {
        this->position_x += 32;
    }
    else if (param > ' ' && param <= 0x7E) {
        gfxprint_putc1(this, param);
    }
    else if (param >= 0xA0 && param <= 0xDF) {
        if (gfxprint_isHiragana(this)) {
            if (param <= 0xBF) {
                param -= 0x20;
            }
            else {
                param += 0x20;
            }
        }

        gfxprint_putc1(this, param);
    }
    else {
        switch (param) {
            case '\0':
                break;
            case '\n':
                this->position_y += 32;
                #pragma fallthrough
            case '\r':
                this->position_x = this->offset_x;
                break;
            case '\t':
                do {
                    gfxprint_putc1(this, ' ');
                } while ((this->position_x - this->offset_x) % 256);
                break;
            case '\x8D':
                gfxprint_setHiragana(this);
                break;
            case '\x8C':
                gfxprint_setKatakana(this);
                break;
            case '\x8B':
                gfxprint_setGradient(this);
                gfxprint_setChanged(this);
                break;
            case '\x8A':
                gfxprint_clrGradient(this);
                gfxprint_setChanged(this);
                break;
            case '\x8E':
                break;
            default:
                break;
        }
    }
}

extern void gfxprint_write(gfxprint_t* this, const void* buffer, size_t size, size_t n) {
    char* buf = (char*)buffer;
    size_t i;
    
    for (i = size * n; i != 0; i--) {
        gfxprint_putc(this, *buf++);
    }
}

static void* gfxprint_prout(void* this, const char* buffer, int n) {
    gfxprint_write((gfxprint_t*)this, buffer, sizeof(char), (size_t)n);
    return this;
}

extern void gfxprint_init(gfxprint_t* this) {
    gfxprint_clrOpened(this);
    this->prout_func = &gfxprint_prout;
    this->glistp = NULL;
    this->position_x = 0;
    this->position_y = 0;
    this->offset_x = 0;
    this->offset_y = 0;
    this->color.rgba8888 = 0;
    gfxprint_setKatakana(this);
    gfxprint_clrGradient(this);
    gfxprint_setShadow(this);
    gfxprint_setChanged(this);

    if ((__gfxprint_default_flags & GFXPRINT_FLAG_HIGHRES) != 0) {
        gfxprint_setHighres(this);
    }
    else {
        gfxprint_clrHighres(this);
    }
}

extern void gfxprint_cleanup(gfxprint_t* this) { }

extern void gfxprint_open(gfxprint_t* this, Gfx* glistp) {
    if (!gfxprint_isOpened(this)) {
        gfxprint_setOpened(this);
        this->glistp = glistp;
        gfxprint_setup(this);
    }
    else {
        osSyncPrintf("gfxprint_open:２重オープンです\n");
    }
}

extern Gfx* gfxprint_close(gfxprint_t* this) {
    Gfx* list;
    
    gfxprint_clrOpened(this);
    gDPPipeSync(this->glistp++);
    list = this->glistp;
    this->glistp = NULL;
    return list;
}

extern int gfxprint_vprintf(gfxprint_t* this, const char* fmt, va_list ap) {
    return vaprintf(&this->prout_func, fmt, ap);
}

extern int gfxprint_printf(gfxprint_t* this, const char* fmt, ...) {
    int res;
    
    va_list ap;
    va_start(ap, fmt);
    res = gfxprint_vprintf(this, fmt, ap);
    va_end(ap);

    return res;
}
