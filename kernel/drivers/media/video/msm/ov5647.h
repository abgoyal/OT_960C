/* Copyright (c) 2009-2010, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of Code Aurora Forum, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef CAMSENSOR_OV5647
#define CAMSENSOR_OV5647

#include <mach/board.h>

#define OV5647_DEFAULT_CLOCK_RATE  24000000
#define OV5647_AF_I2C_ADDR 			  0x18 >> 1
#define REG_OV5647_GAIN_MSB           0x350A
#define REG_OV5647_GAIN_LSB           0x350B
#define REG_OV5647_LINE_HSB           0x3500
#define REG_OV5647_LINE_MSB           0x3501
#define REG_OV5647_LINE_LSB           0x3502

#define MIPI_IF
//#define OV5647_PREVIEW_RAW_TEST
struct reg_struct {
	uint16_t line_length_pck;
	uint16_t frame_length_lines;
};

struct reg_struct const ov5647_reg_pat[2] = {
	{ /* Preview */		
		/* line_length_pck*/
		0x0760,
		/* frame_length_lines*/
		0x03D8,		
	},
#ifdef OV5647_PREVIEW_RAW_TEST
	{ /* Snapshot */
		/* line_length_pck */
		0x0760,
		/* frame_length_lines */
		0x03D8,
	}
#else
	{ /* Snapshot */
		/* line_length_pck */
		0x0A8C,
		/* frame_length_lines */
		0x07B0,
	}
#endif
};


typedef struct register_address_value_pair_struct  {
	uint16_t register_address;
	uint8_t register_value;
} register_address_value_pair;

// 2608x1952 to 1296x972 30fps 
static register_address_value_pair ov5647_init_array[] =  {
#ifdef MIPI_IF
//init
// kykim reg_reset: set reg and delay 10ms {0x0103, 0x01},
{0x3035, 0x11},
{0x3036, 0x46},
{0x303c, 0x11},
{0x3821, 0x07},
{0x3820, 0x41},
{0x370c, 0x03},
{0x3612, 0x59},
{0x3618, 0x00},
{0x5000, 0x06},
{0x5003, 0x08},
{0x5a00, 0x08},
{0x3000, 0xff},
{0x3001, 0xff},
{0x3002, 0xff},
{0x301d, 0xf0},
{0x3a18, 0x00},
{0x3a19, 0xf8},
{0x3c01, 0x80},
{0x3b07, 0x0c},
{0x380c, 0x07},
{0x380d, 0x68},
{0x380e, 0x03},
{0x380f, 0xd8},
{0x3814, 0x31},
{0x3815, 0x31},
{0x3708, 0x64},
{0x3709, 0x52},
{0x3808, 0x05},
{0x3809, 0x00},
{0x380a, 0x03},
{0x380b, 0xc0},
{0x3800, 0x00},
{0x3801, 0x18},
{0x3802, 0x00},
{0x3803, 0x0e},
{0x3804, 0x0a},
{0x3805, 0x27},
{0x3806, 0x07},
{0x3807, 0x95},
{0x3630, 0x2e},
{0x3632, 0xe2},
{0x3633, 0x23},
{0x3634, 0x44},
{0x3620, 0x64},
{0x3621, 0xe0},
{0x3600, 0x37},
{0x3704, 0xa0},
{0x3703, 0x5a},
{0x3715, 0x78},
{0x3717, 0x01},
{0x3731, 0x02},
{0x370b, 0x60},
{0x3705, 0x1a},
{0x3f05, 0x02},
{0x3f06, 0x10},
{0x3f01, 0x0a},
{0x3a08, 0x01},
{0x3a09, 0x27},
{0x3a0a, 0x00},
{0x3a0b, 0xf6},
{0x3a0d, 0x04},
{0x3a0e, 0x03},
{0x3a0f, 0x58},
{0x3a10, 0x50},
{0x3a1b, 0x58},
{0x3a1e, 0x50},
{0x3a11, 0x60},
{0x3a1f, 0x28},
{0x4001, 0x02},
{0x4004, 0x02},
{0x4000, 0x09},
               
{0x3503, 0x03},
{0x3000, 0x00},
{0x3001, 0x00},
{0x3002, 0x00},
{0x3017, 0xe0},
{0x301c, 0xfc},
{0x3636, 0x06},
{0x3016, 0x08},
{0x3827, 0xec},
{0x3018, 0x44},
{0x3035, 0x21},
{0x3106, 0xf5},
{0x3034, 0x1a},
{0x301c, 0xf8},
	{0x5001, 0x00},        
	{0x5002, 0x40},

// OV5647 LENC setting d50
{0x5000, 0x86},
{0x5800, 0x1c},
{0x5801, 0xb },
{0x5802, 0x8 },
{0x5803, 0x8 },
{0x5804, 0xc },
{0x5805, 0x1d},
{0x5806, 0x7 },
{0x5807, 0x4 },
{0x5808, 0x3 },
{0x5809, 0x3 },
{0x580a, 0x4 },
{0x580b, 0x6 },
{0x580c, 0x5 },
{0x580d, 0x2 },
{0x580e, 0x0 },
{0x580f, 0x0 },
{0x5810, 0x2 },
{0x5811, 0x2 },
{0x5812, 0x5 },
{0x5813, 0x2 },
{0x5814, 0x0 },
{0x5815, 0x0 },
{0x5816, 0x2 },
{0x5817, 0x2 },
{0x5818, 0x6 },
{0x5819, 0x4 },
{0x581a, 0x3 },
{0x581b, 0x3 },
{0x581c, 0x4 },
{0x581d, 0x6 },
{0x581e, 0x1a},
{0x581f, 0xc },
{0x5820, 0x8 },
{0x5821, 0x8 },
{0x5822, 0xb },
{0x5823, 0x1d},
{0x5824, 0x26},
{0x5825, 0x28},
{0x5826, 0x27},
{0x5827, 0x28},
{0x5828, 0xa },
{0x5829, 0x28},
{0x582a, 0x24},
{0x582b, 0x44},
{0x582c, 0x44},
{0x582d, 0x8 },
{0x582e, 0x26},
{0x582f, 0x42},
{0x5830, 0x40},
{0x5831, 0x42},
{0x5832, 0x26},
{0x5833, 0x28},
{0x5834, 0x24},
{0x5835, 0x24},
{0x5836, 0x24},
{0x5837, 0xa },
{0x5838, 0x28},
{0x5839, 0x26},
{0x583a, 0x28},
{0x583b, 0x27},
{0x583c, 0x48},
{0x583d, 0xce},

#if 0        
     {0x0103, 0x01},  {0x3821, 0x07},        
     {0x3820, 0x41},  {0x370c, 0x03},        
     {0x3612, 0x49},  {0x3618, 0x00},        
     {0x5000, 0x06},  {0x5003, 0x08},        
     {0x5a00, 0x08},  {0x3017, 0xe0},        
     {0x3636, 0x06},  {0x3016, 0x08},        
     {0x3037, 0x01},  {0x3827, 0xec},        
     {0x3018, 0x44},  {0x3035, 0x31},        
     {0x3106, 0x05},  {0x3034, 0x1a},        
     {0x3036, 0x23},  {0x3a18, 0x01},        
     {0x3a19, 0xe0},  {0x3c01, 0x80},        
     {0x3b07, 0x0c},  {0x380c, 0x07},        
     {0x380d, 0x60},  {0x380e, 0x03},        
     {0x380f, 0xd8},  {0x3814, 0x31},        
     {0x3815, 0x31},  {0x3708, 0x22},        
     {0x3709, 0x52},  {0x3815, 0x31},        
     {0x3808, 0x05},  {0x3809, 0x10},        
     {0x380a, 0x03},  {0x380b, 0xcc},        
     {0x3800, 0x00},  {0x3801, 0x08},        
     {0x3802, 0x00},  {0x3803, 0x02},        
     {0x3804, 0x0a},  {0x3805, 0x37},        
     {0x3806, 0x07},  {0x3807, 0xa1},        
     {0x3630, 0x2e},  {0x3632, 0xe2},        
     {0x3633, 0x23},  {0x3634, 0x44},        
     {0x3620, 0x64},  {0x3621, 0xe0},        
     {0x3600, 0x37},  {0x3704, 0xa0},        
     {0x3703, 0x5a},  {0x3715, 0x78},        
     {0x3717, 0x01},  {0x3731, 0x02},        
     {0x370b, 0x60},  {0x3705, 0x1a},        
     {0x3f05, 0x02},  {0x3f06, 0x10},        
     {0x3f01, 0x0a},  {0x4001, 0x02},        
     {0x4004, 0x02},  {0x4000, 0x09},        
     {0x3a08, 0x01},  {0x3a09, 0x27},        
     {0x3a0a, 0x00},  {0x3a0b, 0xf6},        
     {0x3a0d, 0x04},  {0x3a0e, 0x03},        
     {0x3a0f, 0x58},  {0x3a10, 0x50},        
     {0x3a1b, 0x58},  {0x3a1e, 0x50},        
     {0x3a11, 0x60},  {0x3a1f, 0x28},        
     {0x3503, 0x03},  {0x3501, 0x3d},                          
     {0x3502, 0x40},  {0x350a, 0x01},                          
     {0x350b, 0xe0},  {0x5001, 0x01},        
     {0x5180, 0x08},  {0x5186, 0x04},                          
     {0x5187, 0x00},                          
     {0x5188, 0x04},  {0x5189, 0x00},                          
     {0x518a, 0x04},  {0x518b, 0x00},                          
     {0x5000, 0x06},  {0x3011, 0x82},  

//OV5647 LENC setting
//32x32 -1
{0x5000, 0x86},
{0x5800, 0x1f},
{0x5801, 0x12},
{0x5802, 0x0d},
{0x5803, 0x0a},
{0x5804, 0x0f},
{0x5805, 0x1a},
{0x5806, 0x06},
{0x5807, 0x07},
{0x5808, 0x06},
{0x5809, 0x06},
{0x580a, 0x06},
{0x580b, 0x04},
{0x580c, 0x04},
{0x580d, 0x04},
{0x580e, 0x00},
{0x580f, 0x00},
{0x5810, 0x03},
{0x5811, 0x04},
{0x5812, 0x04},
{0x5813, 0x03},
{0x5814, 0x00},
{0x5815, 0x00},
{0x5816, 0x02},
{0x5817, 0x04},
{0x5818, 0x04},
{0x5819, 0x06},
{0x581a, 0x05},
{0x581b, 0x05},
{0x581c, 0x07},
{0x581d, 0x07},
{0x581e, 0x21},
{0x581f, 0x08},
{0x5820, 0x0d},
{0x5821, 0x0a},
{0x5822, 0x0a},
{0x5823, 0x2f},
{0x5824, 0xaf},
{0x5825, 0x34},
{0x5826, 0x38},
{0x5827, 0x34},
{0x5828, 0xaf},
{0x5829, 0x06},
{0x582a, 0x55},
{0x582b, 0x54},
{0x582c, 0x55},
{0x582d, 0x0c},
{0x582e, 0x38},
{0x582f, 0x52},
{0x5830, 0x50},
{0x5831, 0x52},
{0x5832, 0x05},
{0x5833, 0x24},
{0x5834, 0x54},
{0x5835, 0x55},//0x54
{0x5836, 0x44},
{0x5837, 0x08},
{0x5838, 0x35},
{0x5839, 0x5a},
{0x583a, 0x58},
{0x583b, 0x56},
{0x583c, 0x8f},
{0x583d, 0xce},

#endif
#else
	{0x0100, 0x00},   {0x0103, 0x01},   {0x0100, 0x00},   {0x0100, 0x00},
	{0x0100, 0x00},   {0x0100, 0x00},   {0x3034, 0x18},   {0x3035, 0x21},   {0x3036, 0x70}, {0x3037,0x03},{0x3106, 0xF9},
	{0x303c, 0x11},   {0x3821, 0x07},   {0x3820, 0x41},   {0x370c, 0x03},
	{0x3612, 0x49},   {0x3618, 0x00},   {0x5000, 0x06},   {0x5003, 0x08},
	{0x5a00, 0x08},   {0x3000, 0xff},   {0x3001, 0xff},   {0x3002, 0xff},
	{0x3a18, 0x01},   {0x3a19, 0xe0},   {0x3c01, 0x80},   {0x3b07, 0x0c},
	{0x380c, 0x07},   {0x380d, 0x60},   {0x380e, 0x03},   {0x380f, 0xd8},
	{0x3814, 0x31},   {0x3815, 0x31},   {0x3708, 0x22},   {0x3709, 0x52}, 
	{0x3815, 0x31},   {0x3808, 0x05},   {0x3809, 0x10},   {0x380a, 0x03}, 
	{0x380b, 0xcc},   {0x3800, 0x00},   {0x3801, 0x08},   {0x3802, 0x00},
	{0x3803, 0x02},   {0x3804, 0x0a},   {0x3805, 0x37},   {0x3806, 0x07}, 
	{0x3807, 0xa1},   {0x3630, 0x2e},   {0x3632, 0xe2},   {0x3633, 0x23},
	{0x3634, 0x44},   {0x3620, 0x64},   {0x3621, 0xe0},   {0x3600, 0x37},
	{0x3704, 0xa0},   {0x3703, 0x5a},   {0x3715, 0x78},   {0x3717, 0x01}, 
	{0x3731, 0x02},   {0x370b, 0x60},   {0x3705, 0x1a},   {0x3f05, 0x02}, 
	{0x3f06, 0x10},   {0x3f01, 0x0a},   {0x3a08, 0x01},   {0x3a09, 0x27}, 
	{0x3a0a, 0x00},   {0x3a0b, 0xf6},   {0x3a0d, 0x04},   {0x3a0e, 0x03}, 
	{0x3a0f, 0x58},   {0x3a10, 0x50},   {0x3a1b, 0x58},   {0x3a1e, 0x50},
	{0x3a11, 0x60},   {0x3a1f, 0x28},   {0x4001, 0x02},   {0x4004, 0x02},
	{0x4000, 0x09},   {0x0100, 0x01},   {0x3503, 0x03},   {0x3501, 0x10}, 
	{0x3502, 0x80},   {0x350a, 0x00},   {0x350b, 0x7f},   {0x5001, 0x01},
	{0x5180, 0x08},   {0x5186, 0x04},   {0x5187, 0x00},   {0x5188, 0x04},
	{0x5189, 0x00},   {0x518a, 0x04},   {0x518b, 0x00},   {0x3011, 0x62}, 
	{0x5000, 0x86},   {0x3013, 0x08},   {0x301d, 0xf0},
	//new added
	
	{0x5800,0x15}, 
	{0x5801,0xa }, 
	{0x5802,0x9 }, 
	{0x5803,0x9 }, 
	{0x5804,0xb }, 
	{0x5805,0x1c}, 
	{0x5806,0x6 }, 
	{0x5807,0x5 }, 
	{0x5808,0x3 }, 
	{0x5809,0x4 }, 
	{0x580a,0x5 }, 
	{0x580b,0x8 }, 
	{0x580c,0x4 }, 
	{0x580d,0x1 }, 
	{0x580e,0x0 }, 
	{0x580f,0x0 }, 
	{0x5810,0x2 }, 
	{0x5811,0x6 }, 
	{0x5812,0x4 }, 
	{0x5813,0x1 }, 
	{0x5814,0x0 }, 
	{0x5815,0x0 }, 
	{0x5816,0x2 }, 
	{0x5817,0x6 }, 
	{0x5818,0x6 }, 
	{0x5819,0x4 }, 
	{0x581a,0x3 }, 
	{0x581b,0x3 }, 
	{0x581c,0x5 }, 
	{0x581d,0x8 }, 
	{0x581e,0x14}, 
	{0x581f,0xb }, 
	{0x5820,0x9 }, 
	{0x5821,0x9 }, 
	{0x5822,0xb }, 
	{0x5823,0x1a}, 
	{0x5824,0x2c}, 
	{0x5825,0xe }, 
	{0x5826,0xe }, 
	{0x5827,0xe }, 
	{0x5828,0x6c}, 
	{0x5829,0xe }, 
	{0x582a,0x28}, 
	{0x582b,0x24}, 
	{0x582c,0x28}, 
	{0x582d,0x2c}, 
	{0x582e,0xa }, 
	{0x582f,0x42}, 
	{0x5830,0x40}, 
	{0x5831,0x22}, 
	{0x5832,0xa }, 
	{0x5833,0xe }, 
	{0x5834,0x28}, 
	{0x5835,0x24}, 
	{0x5836,0x28}, 
	{0x5837,0x2c}, 
	{0x5838,0x4a}, 
	{0x5839,0x2e}, 
	{0x583a,0x2f}, 
	{0x583b,0xe }, 
	{0x583c,0x6c}, 
	{0x583d,0xce}, 
#endif
};   

// 2608x1952 to 1296x972 30fps 
static register_address_value_pair ov5647_preview_array[] =  {	
#ifdef MIPI_IF
#if 0
      {0x3821, 0x07},  {0x3820, 0x41},
      {0x3612, 0x49},  {0x3618, 0x00},
      {0x3035, 0x31},  {0x3036, 0x23},
      {0x380c, 0x07},  {0x380d, 0x60},
      {0x380e, 0x03},  {0x380f, 0xd8},
      {0x3814, 0x31},  {0x3815, 0x31},
      {0x3708, 0x22},  {0x3709, 0x52},
      {0x3808, 0x05},  {0x3809, 0x10},
      {0x380a, 0x03},  {0x380b, 0xcc},
      {0x3800, 0x00},  {0x3801, 0x08},
      {0x3802, 0x00},  {0x3803, 0x02},
      {0x3804, 0x0a},  {0x3805, 0x37},
      {0x3806, 0x07},  {0x3807, 0xa1},
      {0x4004, 0x02},
#endif
{0x3821,0x07}, {0x3820,0x41}, 
{0x3612,0x59}, {0x3618,0x00}, 
{0x380c,0x07}, {0x380d,0x60}, 
{0x380e,0x03}, {0x380f,0xd8}, 
{0x3814,0x31}, {0x3815,0x31}, 
{0x3708,0x64}, {0x3709,0x52}, 
{0x3808,0x05}, {0x3809,0x10}, 
{0x380a,0x03}, {0x380b,0xcc}, 
{0x3800,0x00}, {0x3801,0x08}, 
{0x3802,0x00}, {0x3803,0x02}, 
{0x3804,0x0a}, {0x3805,0x37}, 
{0x3806,0x07}, 
{0x3807,0xa1}, 
{0x4004,0x02}, 
#else
	{0x303c, 0x11},{0x3821, 0x07},
	{0x3820, 0x41},{0x370c, 0x03},{0x3612, 0x49},{0x3618, 0x00},
	{0x380c, 0x07},{0x380d, 0x60},{0x380e, 0x03},{0x380f, 0xd8},
	{0x3814, 0x31},{0x3815, 0x31},{0x3708, 0x22},{0x3709, 0x52}, 
	{0x3815, 0x31},{0x3808, 0x05},{0x3809, 0x10},{0x380a, 0x03},
	{0x380b, 0xcc},{0x3800, 0x00},{0x3801, 0x08},{0x3802, 0x00},
	{0x3803, 0x02},{0x3804, 0x0a},{0x3805, 0x37},{0x3806, 0x07},
	{0x3807, 0xa1},{0x3a08, 0x01},{0x3a09, 0x27}, {0x3a0a, 0x00},
	{0x3a0b, 0xf6},{0x3a0d, 0x04},{0x3a1e, 0x50}, {0x4004, 0x02},	{0x5000,0x86},
#endif
};

// 2608x1952 to 1296x972 8fps  
#if 1 //// kykim 8fps : Added for later use
static register_address_value_pair ov5647_preview_8fps_array[] =  {	
#ifdef MIPI_IF
{0x3821,0x07}, {0x3820,0x41}, 
{0x3612,0x59}, {0x3618,0x00}, 
{0x3035,0x71},     // kykim 8fps
{0x380c,0x07}, {0x380d,0x60}, 
{0x380e,0x04},     // kykim 8fps 
{0x380f,0x22},     // 8fps
{0x3814,0x31}, {0x3815,0x31}, 
{0x3708,0x64}, {0x3709,0x52}, 
{0x3808,0x05}, {0x3809,0x10}, 
{0x380a,0x03}, {0x380b,0xcc}, 
{0x3800,0x00}, {0x3801,0x08}, 
{0x3802,0x00}, {0x3803,0x02}, 
{0x3804,0x0a}, {0x3805,0x37}, 
{0x3806,0x07}, 
{0x3807,0xa1}, 
{0x4004,0x02}, 
#else
	{0x303c, 0x11},{0x3821, 0x07},
	{0x3820, 0x41},{0x370c, 0x03},{0x3612, 0x49},{0x3618, 0x00},
	{0x380c, 0x07},{0x380d, 0x60},{0x380e, 0x03},{0x380f, 0xd8},
	{0x3814, 0x31},{0x3815, 0x31},{0x3708, 0x22},{0x3709, 0x52}, 
	{0x3815, 0x31},{0x3808, 0x05},{0x3809, 0x10},{0x380a, 0x03},
	{0x380b, 0xcc},{0x3800, 0x00},{0x3801, 0x08},{0x3802, 0x00},
	{0x3803, 0x02},{0x3804, 0x0a},{0x3805, 0x37},{0x3806, 0x07},
	{0x3807, 0xa1},{0x3a08, 0x01},{0x3a09, 0x27}, {0x3a0a, 0x00},
	{0x3a0b, 0xf6},{0x3a0d, 0x04},{0x3a1e, 0x50}, {0x4004, 0x02},	{0x5000,0x86},
#endif
};
#endif

// 1296x972 to 2608x1952, 10.5fps 
static register_address_value_pair ov5647_capture_array[] =  {
#ifdef MIPI_IF
#if 0
        {0x3821, 0x06},
        {0x3820, 0x00}, {0x3612, 0x4b},
        {0x3618, 0x04}, {0x3035, 0x31}/*{0x3035, 0x21}*/,
        {0x3036, 0x23}/*{0x3036, 0x21}*/, {0x380c, 0x0a},
        {0x380d, 0x8c}, {0x380e, 0x07},
        {0x380f, 0xb0}, {0x3814, 0x11},
        {0x3815, 0x11}, {0x3708, 0x64},
        {0x3709, 0x12}, {0x3808, 0x0a},
        {0x3809, 0x30}, {0x380a, 0x07},
        {0x380b, 0xa0}, {0x3800, 0x00},
        {0x3801, 0x04}, {0x3802, 0x00},
        {0x3803, 0x00}, {0x3804, 0x0a},
        {0x3805, 0x3b}, {0x3806, 0x07},
        {0x3807, 0xa3}, {0x4004, 0x04},
#endif
{0x3821, 0x06},
{0x3820, 0x00},
{0x3612, 0x5b},
{0x3618, 0x04},
{0x380c, 0x0a},
{0x380d, 0x8c},
{0x380e, 0x07},
{0x380f, 0xb0},
{0x3814, 0x11},
{0x3815, 0x11},
{0x3708, 0x64},
{0x3709, 0x12},
{0x3808, 0x0a},
{0x3809, 0x30},
{0x380a, 0x07},
{0x380b, 0xa0},
{0x3800, 0x00},
{0x3801, 0x04},
{0x3802, 0x00},
{0x3803, 0x00},
{0x3804, 0x0a},
{0x3805, 0x3b},
{0x3806, 0x07},
{0x3807, 0xa3},
{0x4004, 0x04},
#else
	{0x303c, 0x11},   {0x3821, 0x06},
	{0x3820, 0x00},   {0x370c, 0x00},   {0x3612, 0x4b},   {0x3618, 0x04}, 
	{0x380c, 0x0a},   {0x380d, 0x8c},   {0x380e, 0x07},   {0x380f, 0xb0}, 
	{0x3814, 0x11},   {0x3815, 0x11},   {0x3708, 0x24},   {0x3709, 0x12},
	{0x3815, 0x11},   {0x3808, 0x0a},   {0x3809, 0x30},   {0x380a, 0x07},
	{0x380b, 0xa0},   {0x3800, 0x00},   {0x3801, 0x04},   {0x3802, 0x00},
	{0x3803, 0x00},   {0x3804, 0x0a},   {0x3805, 0x3b},   {0x3806, 0x07},
	{0x3807, 0xa3},   {0x3a08, 0x00},   {0x3a09, 0x4a},   {0x3a0a, 0x00}, 
	{0x3a0b, 0x3d},   {0x3a0d, 0x20},   {0x3a0e, 0x1a},   {0x4004, 0x04}, 	{0x5000,0x86},
#endif
};  

#endif /* CAMSENSOR_OV5647 */

