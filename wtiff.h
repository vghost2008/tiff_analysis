/********************************************************************************
 *   License     : 
 *   Author      : WangJie bluetornado@zju.edu.cn
 *   Description : 
 ********************************************************************************/
_Pragma("once")
#include <stdint.h>
#include <string>
#include <fstream>
#include "wabstracttiff.h"

#pragma pack(1)
/*
 *  文件头在每一个文件的开始位置
 * FH的构成：
 * Byte 0-1: 字节顺序标志位， 值为II或者MM。II表示小字节在前， 又称为little-endian。MM表示大字节在前，又成为big-endian。
 * Byte 2-3: TIFF的标志位，一般都是42(0x2a)
 * Byte 4-7: 第一个IFD的偏移量。可以在任意位置， 但必须是在一个字的边界，也就是说必须是2的整数倍
 */
struct TiffHead 
{
    uint16_t bytes_order;
    uint16_t version;
    uint32_t ifd_offset;
};
/*
 * 每个文件包含多个Image File Directory(IFD)
 * Byte 0-1: 表示此IFD包含了多少个DE，假设数目为n
 * Byte 2-(n*12+1): n个DE
 * Byte (n*12+2)-(n*12+5): 下一个IFD的偏移量，如果没有则置为0
 */
 /*
  * DE的构成：
  * Byte 0-1: 此TAG的唯一标识
  * Byte 2-3: 数据类型。
  * Byte 4-7: 数量。通过类型和数量可以确定存储此TAG的数据需要占据的字节数
  * Byte 8-11: 如果占用的字节数少于4， 则数据直接存于此。 如果超过4个，则这里存放的是指向实际数据的指针 
  */
struct TiffDE 
{
    uint16_t tag;
    uint16_t type;
    uint32_t count;             //count of type (if type is ascii, count include nullptr)
    uint32_t value_or_offset;
};
#pragma pack(0)

class TIFF:public WAbstractTIFF
{
	public:
		TIFF(const std::string& path);
		~TIFF();
		void showInfo();
        static bool detection(const std::string& path);
	private:
		bool readHead(uint32_t& ifd_offset);
		bool readAllIFDS(uint32_t offset);
		bool readIFD(size_t offset,uint32_t& next_ifd_offset,int max_show_nr=100);
		bool readDE(size_t offset,int nr);
		bool readStrip(size_t offset,size_t size);
		void showDE(const TiffDE& de);
	private:
		std::ifstream file_;
		size_t file_size_ = 0;
};
