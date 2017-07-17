#ifndef __SENSOR_ISP_TABLE__
#define __SENSOR_ISP_TABLE__

#include "project.h"
const INT8U g_nd_edge_table[256] = // add by Comi , not strong edge
{
    0x00, 0x01, 0x02, 0x04, 0x07, 0x0a, 0x0e, 0x12, 0x17, 0x1d, 0x23, 0x29, 0x31, 0x38, 0x41, 0x4a,
    0x53, 0x5d, 0x68, 0x7B, 0x80, 0x84, 0x88, 0x8C, 0x90, 0x93, 0x97, 0x9B, 0x9F, 0xA2, 0xA5, 0xA8,
    0xAC, 0xAE, 0xB1, 0xB4, 0xB6, 0xB9, 0xBB, 0xBD, 0xC0, 0xC1, 0xC3, 0xC5, 0xC7, 0xC9, 0xCA, 0xCC,
    0xCD, 0xCE, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDB, 0xDC,
    0xDD, 0xDD, 0xDE, 0xDF, 0xDF, 0xE0, 0xE0, 0xE1, 0xE2, 0xE2, 0xE3, 0xE3, 0xE4, 0xE4, 0xE4, 0xE5,
    0xE5, 0xE6, 0xE6, 0xE6, 0xE7, 0xE7, 0xE8, 0xE8, 0xE8, 0xE9, 0xE9, 0xE9, 0xE9, 0xEA, 0xEA, 0xEA,
    0xEB, 0xEB, 0xEB, 0xEB, 0xEC, 0xEC, 0xEC, 0xEC, 0xEC, 0xED, 0xED, 0xED, 0xED, 0xED, 0xEE, 0xEE,
    0xEE, 0xEE, 0xEE, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xEF, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0,
    0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF1, 0xF2, 0xF2, 0xF2, 0xF2, 0xF2, 0xF2, 0xF2, 0xF2,
    0xF2, 0xF3, 0xF3, 0xF3, 0xF3, 0xF3, 0xF3, 0xF3, 0xF3, 0xF3, 0xF3, 0xF4, 0xF4, 0xF4, 0xF4, 0xF4,
    0xF4, 0xF4, 0xF4, 0xF4, 0xF4, 0xF4, 0xF4, 0xF4, 0xF5, 0xF5, 0xF5, 0xF5, 0xF5, 0xF5, 0xF5, 0xF5,
    0xF5, 0xF5, 0xF5, 0xF5, 0xF5, 0xF5, 0xF5, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6,
    0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF6, 0xF7, 0xf8, 0xf6, 0xf4, 0xf1, 0xef, 0xed,
    0xeb, 0xe9, 0xe6, 0xe4, 0xe2, 0xe0, 0xde, 0xdc, 0xda, 0xd8, 0xd6, 0xd5, 0xd3, 0xd1, 0xcf, 0xcd,
    0xcb, 0xca, 0xc8, 0xc6, 0xc5, 0xc3, 0xc1, 0xc0, 0xbe, 0xbc, 0xbb, 0xb9, 0xb8, 0xb6, 0xb5, 0xb3,
    0xb2, 0xb0, 0xaf, 0xae, 0xac, 0xab, 0xa9, 0xa8, 0xa7, 0xa5, 0xa4, 0xa3, 0xa2, 0xa0, 0x9f, 0x9e
};

/*
INT8U LiTable_rgb[48]=
{	//R*16,Gb/Gr*16,B*16
	0x1e,
	0x2e,
	0x3e,
	0x4e,
	0x5e,
	0x6e,
	0x7e,
	0x8e,
	0x9e,
	0xae,
	0xbe,
	0xce,
	0xde,
	0xee,
	0xfe,
	0xff,
	0x0f,
	0x1f,
	0x2f,
	0x3f,
	0x4f,
	0x5f,
	0x6f,
	0x7f,
	0x8f,
	0x9f,
	0xaf,
	0xbf,
	0xcf,
	0xdf,
	0xef,
	0xff,
	0x07,
	0x17,
	0x27,
	0x37,
	0x47,
	0x57,
	0x67,
	0x77,
	0x87,
	0x97,
	0xa7,
	0xb7,
	0xc7,
	0xd7,
	0xe7,
	0xf7
};

INT16U MaxTan8[32]=
{
	0x0C0,
	0x155,
	0x154,
	0x0C1,
	0x0BF,
	0x156,
	0x153,
	0x0C2,
	0x0BF,
	0x154,
	0x153,
	0x0C0,
	0x0BE,
	0x155,
	0x152,
	0x0C1,
	0x0BE,
	0x153,
	0x152,
	0x0BF,
	0x0BD,
	0x154,
	0x151,
	0x0C0,
	0x0BD,
	0x152,
	0x151,
	0x0BE,
	0x0BC,
	0x153,
	0x150,
	0x0BF
};

INT16U Slope4[16]=
{
	0x155,
	0x154,
	0x153,
	0x152,
	0x151,
	0x152,
	0x153,
	0x154,
	0x155,
	0x154,
	0x153,
	0x152,
	0x151,
	0x152,
	0x153,
	0x154
};

INT16U CLPoint[8]=		//Sensor Center is Weight/2, Hight/2 for RGB
{
	#if 0	//for VGA
		//R Center
		0x140,//X=320
		0x0F0,//Y=
		//Gr Center
		0x13F,//
		0x0F0,//
		0x140,
		0x0EF,
		0x13F,
		0x0EF
	#else	//For XQGA
		0x400,
		0x300,
		0x400,
		0x300,
		0x400,
		0x300,
		0x400,
		0x300
	#endif
};

INT16U Radius_File_0[512]=
{
	0x100,
	0x101,
	0x102,
	0x103,
	0x104,
	0x105,
	0x106,
	0x107,
	0x102,
	0x103,
	0x104,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x104,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x102,
	0x103,
	0x104,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x104,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x104,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x128,
	0x129,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x128,
	0x129,
	0x124,
	0x125,
	0x126,
	0x127,
	0x128,
	0x129,
	0x12a,
	0x12b
};

INT16U Radius_File_1[512]=
{
	0x101,
	0x102,
	0x103,
	0x104,
	0x105,
	0x106,
	0x107,
	0x108,
	0x103,
	0x104,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x103,
	0x104,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x128,
	0x105,
	0x106,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x128,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x128,
	0x129,
	0x12a,
	0x107,
	0x108,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x109,
	0x10a,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x10b,
	0x10c,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x10d,
	0x10e,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x10f,
	0x110,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x111,
	0x112,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x113,
	0x114,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x115,
	0x116,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x117,
	0x118,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x119,
	0x11a,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x11b,
	0x11c,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x11d,
	0x11e,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x11f,
	0x120,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x121,
	0x122,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x128,
	0x123,
	0x124,
	0x125,
	0x126,
	0x127,
	0x128,
	0x129,
	0x12a,
	0x125,
	0x126,
	0x127,
	0x128,
	0x129,
	0x12a,
	0x12b,
	0x12c
};
*/
INT8U LEElut[256] =
{
    0x40,	//0xaa,
    0x42,   //0xa1,
    0x44,   //0xaa,
    0x46,   //0xa1,
    0x49,   //0xaa,
    0x4B,   //0xa1,
    0x4E,   //0xa2,
    0x51,   //0xa1,
    0x53,   //0xa2,
    0x57,   //0xa1,
    0x5A,   //0xa2,
    0x5D,   //0xa1,
    0x60,   //0xa2,
    0x64,   //0xa1,
    0x68,   //0xa2,
    0x6C,   //0xa1,
    0x6F,   //0xa2,
    0x73,   //0xa1,
    0x77,   //0xa2,
    0x7B,   //0xa1,
    0x80,   //0xa2,
    0x84,   //0xa1,
    0x88,   //0xa4,
    0x8C,   //0xa1,
    0x90,   //0xa4,
    0x93,   //0xa1,
    0x97,   //0xa4,
    0x9B,   //0xa1,
    0x9F,   //0xa4,
    0xA2,   //0xa1,
    0xA5,   //0xa4,
    0xA8,   //0xa1,
    0xAC,   //0xa4,
    0xAE,   //0xa1,
    0xB1,   //0xa4,
    0xB4,   //0xa1,
    0xB6,   //0xa4,
    0xB9,   //0xa1,
    0xBB,   //0xa4,
    0xBD,   //0xa1,
    0xC0,   //0xa4,
    0xC1,   //0xa1,
    0xC3,   //0xa4,
    0xC5,   //0xa1,
    0xC7,   //0xa4,
    0xC9,   //0xa1,
    0xCA,   //0xa6,
    0xCC,   //0xa1,
    0xCD,   //0xa6,
    0xCE,   //0xa1,
    0xD0,   //0xa6,
    0xD1,   //0xa1,
    0xD2,   //0xa6,
    0xD3,   //0xa1,
    0xD4,   //0xa6,
    0xD5,   //0xa1,
    0xD6,   //0xa6,
    0xD7,   //0xa1,
    0xD8,   //0xa6,
    0xD9,   //0xa1,
    0xDA,   //0xa6,
    0xDB,   //0xa1,
    0xDB,   //0xa6,
    0xDC,   //0xa1,
    0xDD,   //0xa6,
    0xDD,   //0xa1,
    0xDE,   //0xa6,
    0xDF,   //0xa1,
    0xDF,   //0xa6,
    0xE0,   //0xa1,
    0xE0,   //0xa8,
    0xE1,   //0xa1,
    0xE2,   //0xa8,
    0xE2,   //0xa1,
    0xE3,   //0xa8,
    0xE3,   //0xa1,
    0xE4,   //0xa8,
    0xE4,   //0xa1,
    0xE4,   //0xa8,
    0xE5,   //0xa1,
    0xE5,   //0xa8,
    0xE6,   //0xa1,
    0xE6,   //0xa8,
    0xE6,   //0xa1,
    0xE7,   //0xa8,
    0xE7,   //0xa1,
    0xE8,   //0xa8,
    0xE8,   //0xa1,
    0xE8,   //0xa8,
    0xE9,   //0xa1,
    0xE9,   //0xa8,
    0xE9,   //0xa1,
    0xE9,   //0xa8,
    0xEA,   //0xa1,
    0xEA,   //0xaA,
    0xEA,   //0xa1,
    0xEB,   //0xaA,
    0xEB,   //0xa1,
    0xEB,   //0xaA,
    0xEB,   //0xa1,
    0xEC,   //0xaA,
    0xEC,   //0xa1,
    0xEC,   //0xaA,
    0xEC,   //0xa1,
    0xEC,   //0xaA,
    0xED,   //0xa1,
    0xED,   //0xaA,
    0xED,   //0xa1,
    0xED,   //0xaA,
    0xED,   //0xa1,
    0xEE,   //0xaA,
    0xEE,   //0xa1,
    0xEE,   //0xaA,
    0xEE,   //0xa1,
    0xEE,   //0xaA,
    0xEF,   //0xa1,
    0xEF,   //0xaA,
    0xEF,   //0xa1,
    0xEF,   //0xaA,
    0xEF,   //0xa1,
    0xEF,   //0xaC,
    0xF0,   //0xa1,
    0xF0,   //0xaC,
    0xF0,   //0xa1,
    0xF0,   //0xaC,
    0xF0,   //0xa1,
    0xF0,   //0xaC,
    0xF0,   //0xa1,
    0xF1,   //0xaC,
    0xF1,   //0xa1,
    0xF1,   //0xaC,
    0xF1,   //0xa1,
    0xF1,   //0xaC,
    0xF1,   //0xa1,
    0xF1,   //0xaC,
    0xF1,   //0xa1,
    0xF2,   //0xaC,
    0xF2,   //0xa1,
    0xF2,   //0xaC,
    0xF2,   //0xa1,
    0xF2,   //0xaC,
    0xF2,   //0xa1,
    0xF2,   //0xaC,
    0xF2,   //0xa1,
    0xF2,   //0xaC,
    0xF3,   //0xa1,
    0xF3,   //0xaC,
    0xF3,   //0xa1,
    0xF3,   //0xaC,
    0xF3,   //0xa1,
    0xF3,   //0xaE,
    0xF3,   //0xa1,
    0xF3,   //0xaE,
    0xF3,   //0xa1,
    0xF3,   //0xaE,
    0xF4,   //0xa1,
    0xF4,   //0xaE,
    0xF4,   //0xa1,
    0xF4,   //0xaE,
    0xF4,   //0xa1,
    0xF4,   //0xaE,
    0xF4,   //0xa1,
    0xF4,   //0xaE,
    0xF4,   //0xa1,
    0xF4,   //0xaE,
    0xF4,   //0xa1,
    0xF4,   //0xaE,
    0xF4,   //0xa1,
    0xF5,   //0xaE,
    0xF5,   //0xa1,
    0xF5,   //0xaE,
    0xF5,   //0xa1,
    0xF5,   //0xaE,
    0xF5,   //0xa1,
    0xF5,   //0x1a,
    0xF5,   //0xa1,
    0xF5,   //0x1a,
    0xF5,   //0xa1,
    0xF5,   //0x1a,
    0xF5,   //0xa1,
    0xF5,   //0x1a,
    0xF5,   //0xa1,
    0xF5,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF6,   //0xa1,
    0xF6,   //0x1a,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF7,   //0x12,
    0xF7,   //0xa1,
    0xF8,   //0xa0,
    0xF8,   //0xa1,
    0xF8,   //0xa2,
    0xF8,   //0xa3,
    0xF8,   //0xa4,
    0xF8,   //0xa5,
    0xF8,   //0xa6,
    0xF8,   //0xa7,
    0xF8,   //0xa8,
    0xF8,   //0xa9,
    0xF8,   //0xb0,
    0xF8,   //0xb1,
    0xF8,   //0xb2,
    0xF8,   //0xb3,
    0xF8,   //0xb4,
    0xF8,   //0xb5,
    0xF8,   //0xb6,
    0xF8,   //0xb7,
    0xF8,   //0xb8,
    0xF8,   //0xb9,
    0xF8,   //0xc0,
    0xF8,   //0xc1,
    0xF8,   //0xc2,
    0xF8,   //0xc3,
    0xF8,   //0xc4,
    0xF8,   //0xc5,
    0xF8,   //0xc6,
    0xF8,   //0xc7,
    0xF8,   //0xc8,
    0xF9,   //0xc9,
    0xF9,   //0xd0,
    0xF9    //0xd1
};

#if 1
INT32U gammatable[128] =
{
    0x159f00,
    0x15550d,
    0x145415,
    0x11451a,
    0x04451f,
    0x111124,
    0x111128,
    0x04112c,
    0x044430,
    0x011133,
    0x110437,
    0x10443a,
    0x10413d,
    0x104140,
    0x104443,
    0x010446,
    0x041049,
    0x10414b,
    0x01044e,
    0x041051,
    0x004153,
    0x041056,
    0x010158,
    0x10405b,
    0x04045d,
    0x01015f,
    0x104062,
    0x101064,
    0x040466,
    0x010468,
    0x01016a,
    0x00416c,
    0x00406f,
    0x004071,
    0x004073,
    0x004075,
    0x004077,
    0x004079,
    0x00407b,
    0x00407d,
    0x01017e,
    0x010180,
    0x040482,
    0x100484,
    0x101086,
    0x004088,
    0x01008a,
    0x04018b,
    0x10048d,
    0x00108f,
    0x004091,
    0x040192,
    0x100494,
    0x004096,
    0x010098,
    0x100499,
    0x00409b,
    0x01009d,
    0x10049e,
    0x0040a0,
    0x0401a1,
    0x0010a3,
    0x0100a5,
    0x1004a6,
    0x0040a8,
    0x0401a9,
    0x0010ab,
    0x0400ad,
    0x0010ae,
    0x0100b0,
    0x0004b1,
    0x0100b3,
    0x0004b4,
    0x0100b6,
    0x0004b7,
    0x0100b9,
    0x0010ba,
    0x0100bc,
    0x0010bd,
    0x0400bf,
    0x0040c0,
    0x1001c1,
    0x0040c3,
    0x0004c4,
    0x0100c6,
    0x0010c7,
    0x0401c8,
    0x0040ca,
    0x0004cb,
    0x0100cd,
    0x0010ce,
    0x1001cf,
    0x0100d1,
    0x0010d2,
    0x0400d4,
    0x0040d5,
    0x0004d6,
    0x0400d8,
    0x0040d9,
    0x0004da,
    0x0400dc,
    0x0100dd,
    0x0010de,
    0x1001df,
    0x0100e1,
    0x0010e2,
    0x0001e3,
    0x0400e5,
    0x0040e6,
    0x0004e7,
    0x1001e8,
    0x0100ea,
    0x0040eb,
    0x0004ec,
    0x1000ee,
    0x0100ef,
    0x0040f0,
    0x0004f1,
    0x1001f2,
    0x0400f4,
    0x0040f5,
    0x0010f6,
    0x0001f7,
    0x0400f9,
    0x0100fa,
    0x0040fb,
    0x0004fc,
    0x1001fd
};
#endif

INT32U OV7725_gammatable[128] =	//for ov7725
{
    0x045102, 0x111407, 0x04510b, 0x114410, 0x111114, 0x051118, 0x04441d, 0x044421,
    0x044425, 0x044429, 0x04442d, 0x111031, 0x111134, 0x044438, 0x11043c, 0x04113f,
    0x110443, 0x041146, 0x11104a, 0x10444d, 0x044150, 0x041153, 0x011057, 0x01105a,
    0x01045d, 0x010460, 0x011063, 0x041066, 0x044168, 0x10416b, 0x01046e, 0x041071,
    0x104173, 0x041076, 0x104178, 0x04107b, 0x01017d, 0x101080, 0x040482, 0x010184,
    0x104087, 0x101089, 0x04048b, 0x04048d, 0x01018f, 0x010191, 0x010193, 0x010195,
    0x040197, 0x040499, 0x10049b, 0x10109d, 0x00409f, 0x0100a1, 0x0404a2, 0x0010a4,
    0x0040a6, 0x0401a7, 0x0010a9, 0x0100ab, 0x1004ac, 0x0040ae, 0x1004af, 0x0040b1,
    0x1004b2, 0x0100b4, 0x0004b5, 0x0100b7, 0x0010b8, 0x1001b9, 0x0100bb, 0x0010bc,
    0x1001bd, 0x0100bf, 0x0010c0, 0x1001c1, 0x0100c3, 0x0040c4, 0x0004c5, 0x1001c6,
    0x0100c8, 0x0040c9, 0x0010ca, 0x0001cb, 0x0400cd, 0x0100ce, 0x0040cf, 0x0004d0,
    0x0001d1, 0x0400d3, 0x0100d4, 0x0040d5, 0x0004d6, 0x0001d7, 0x0400d9, 0x0100da,
    0x0010db, 0x0004dc, 0x1001dd, 0x0400df, 0x0040e0, 0x0004e1, 0x1001e2, 0x0100e4,
    0x0040e5, 0x0004e6, 0x0400e8, 0x0040e9, 0x0004ea, 0x0400ec, 0x0040ed, 0x1004ee,
    0x0100f0, 0x0010f1, 0x0400f3, 0x0010f4, 0x0401f5, 0x0010f7, 0x0400f9, 0x0010fa,
    0x0100fc, 0x1004fd, 0x0000ff, 0x0000ff, 0x0000ff, 0x0000ff, 0x0000ff, 0x0000ff,
};

INT8U OV7670_Gamma_TBLValue[512] =
{
    0x00, 0x50, 0x15, 0x00,
    0x06, 0x55, 0x11, 0x00,
    0x0d, 0x45, 0x15, 0x00,
    0x13, 0x55, 0x14, 0x00,
    0x1a, 0x51, 0x14, 0x00,
    0x1f, 0x15, 0x05, 0x00,
    0x25, 0x51, 0x11, 0x00,
    0x2a, 0x11, 0x05, 0x00,
    0x2f, 0x14, 0x11, 0x00,
    0x33, 0x11, 0x11, 0x00,
    0x37, 0x44, 0x10, 0x00,
    0x3a, 0x41, 0x04, 0x00,
    0x3e, 0x44, 0x10, 0x00,
    0x41, 0x41, 0x04, 0x00,
    0x44, 0x11, 0x11, 0x00,
    0x48, 0x44, 0x04, 0x00,
    0x4c, 0x10, 0x11, 0x00,
    0x4f, 0x41, 0x04, 0x00,
    0x52, 0x11, 0x04, 0x00,
    0x56, 0x10, 0x11, 0x00,
    0x59, 0x41, 0x04, 0x00,
    0x5c, 0x11, 0x04, 0x00,
    0x60, 0x10, 0x01, 0x00,
    0x63, 0x10, 0x01, 0x00,
    0x66, 0x04, 0x01, 0x00,
    0x69, 0x04, 0x01, 0x00,
    0x6c, 0x10, 0x01, 0x00,
    0x6f, 0x10, 0x04, 0x00,
    0x72, 0x10, 0x04, 0x00,
    0x74, 0x41, 0x10, 0x00,
    0x77, 0x04, 0x01, 0x00,
    0x7a, 0x10, 0x04, 0x00,
    0x7c, 0x41, 0x10, 0x00,
    0x7f, 0x04, 0x01, 0x00,
    0x82, 0x40, 0x10, 0x00,
    0x84, 0x04, 0x01, 0x00,
    0x86, 0x41, 0x10, 0x00,
    0x89, 0x10, 0x04, 0x00,
    0x8b, 0x01, 0x01, 0x00,
    0x8e, 0x40, 0x10, 0x00,
    0x90, 0x10, 0x04, 0x00,
    0x92, 0x04, 0x04, 0x00,
    0x94, 0x01, 0x01, 0x00,
    0x96, 0x01, 0x01, 0x00,
    0x98, 0x41, 0x00, 0x00,
    0x9b, 0x40, 0x00, 0x00,
    0x9d, 0x40, 0x00, 0x00,
    0x9f, 0x40, 0x00, 0x00,
    0xa0, 0x01, 0x01, 0x00,
    0xa2, 0x01, 0x01, 0x00,
    0xa4, 0x04, 0x04, 0x00,
    0xa6, 0x04, 0x10, 0x00,
    0xa8, 0x10, 0x00, 0x00,
    0xaa, 0x00, 0x01, 0x00,
    0xab, 0x01, 0x04, 0x00,
    0xad, 0x10, 0x00, 0x00,
    0xaf, 0x40, 0x00, 0x00,
    0xb0, 0x01, 0x04, 0x00,
    0xb2, 0x10, 0x00, 0x00,
    0xb3, 0x01, 0x04, 0x00,
    0xb5, 0x10, 0x00, 0x00,
    0xb7, 0x00, 0x04, 0x00,
    0xb8, 0x10, 0x00, 0x00,
    0xb9, 0x01, 0x04, 0x00,
    0xbb, 0x40, 0x00, 0x00,
    0xbc, 0x04, 0x00, 0x00,
    0xbe, 0x00, 0x01, 0x00,
    0xbf, 0x10, 0x00, 0x00,
    0xc0, 0x01, 0x00, 0x00,
    0xc2, 0x00, 0x04, 0x00,
    0xc3, 0x40, 0x00, 0x00,
    0xc4, 0x04, 0x00, 0x00,
    0xc5, 0x01, 0x00, 0x00,
    0xc7, 0x00, 0x04, 0x00,
    0xc8, 0x00, 0x01, 0x00,
    0xc9, 0x40, 0x00, 0x00,
    0xca, 0x10, 0x00, 0x00,
    0xcb, 0x04, 0x00, 0x00,
    0xcc, 0x01, 0x00, 0x00,
    0xcd, 0x01, 0x04, 0x00,
    0xcf, 0x10, 0x00, 0x00,
    0xd1, 0x00, 0x01, 0x00,
    0xd2, 0x00, 0x04, 0x00,
    0xd3, 0x00, 0x04, 0x00,
    0xd4, 0x00, 0x04, 0x00,
    0xd5, 0x00, 0x01, 0x00,
    0xd6, 0x00, 0x01, 0x00,
    0xd7, 0x00, 0x01, 0x00,
    0xd8, 0x00, 0x01, 0x00,
    0xd9, 0x00, 0x01, 0x00,
    0xda, 0x10, 0x00, 0x00,
    0xdc, 0x00, 0x01, 0x00,
    0xdd, 0x04, 0x10, 0x00,
    0xdf, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00,
    0xe1, 0x00, 0x00, 0x00,
    0xe2, 0x00, 0x01, 0x00,
    0xe3, 0x04, 0x00, 0x00,
    0xe5, 0x00, 0x00, 0x00,
    0xe6, 0x00, 0x00, 0x00,
    0xe6, 0x04, 0x00, 0x00,
    0xe8, 0x00, 0x04, 0x00,
    0xe9, 0x40, 0x00, 0x00,
    0xea, 0x00, 0x01, 0x00,
    0xeb, 0x00, 0x01, 0x00,
    0xec, 0x00, 0x01, 0x00,
    0xed, 0x40, 0x00, 0x00,
    0xee, 0x00, 0x00, 0x00,
    0xef, 0x00, 0x00, 0x00,
    0xef, 0x40, 0x00, 0x00,
    0xf0, 0x04, 0x00, 0x00,
    0xf2, 0x00, 0x04, 0x00,
    0xf3, 0x00, 0x00, 0x00,
    0xf3, 0x10, 0x00, 0x00,
    0xf4, 0x40, 0x00, 0x00,
    0xf5, 0x40, 0x00, 0x00,
    0xf6, 0x40, 0x00, 0x00,
    0xf7, 0x00, 0x00, 0x00,
    0xf7, 0x01, 0x00, 0x00,
    0xf8, 0x40, 0x00, 0x00,
    0xf9, 0x04, 0x00, 0x00,
    0xfb, 0x00, 0x04, 0x00,
    0xfc, 0x00, 0x00, 0x00,
    0xfc, 0x10, 0x00, 0x00,
    0xfd, 0x00, 0x10, 0x00,
    0xfe, 0x00, 0x00, 0x00,
    0xfe, 0x00, 0x10, 0x00,
    0xff, 0x00, 0x00, 0x00,
};
#endif		/*__SENSOR_ISP_TABLE__*/



