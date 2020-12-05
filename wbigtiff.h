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
 * https://www.awaresystems.be/imaging/tiff/bigtiff.html
 */
struct BigTiffHead 
{
    uint16_t bytes_order;
    uint16_t version; //0x2b
    uint16_t id; //=0x08
    uint16_t zeros; //=0x00
    uint64_t ifd_offset;
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
struct BigTiffDE 
{
    uint16_t tag;
    uint16_t type;
    uint64_t count;             //count of type (if type is ascii, count include nullptr)
    uint64_t value_or_offset;
};
#pragma pack(0)
class BigTIFF:public WAbstractTIFF
{
	public:
		BigTIFF(const std::string& path);
		~BigTIFF();
		void showInfo();
        static bool detection(const std::string& path);
	private:
		bool readHead(uint64_t& ifd_offset);
		bool readAllIFDS(uint64_t offset);
		bool readIFD(uint64_t offset,uint64_t& next_ifd_offset,int max_show_nr=100);
		bool readDE(uint64_t offset,int nr);
		bool readStrip(uint64_t offset,size_t size);
		void showDE(const BigTiffDE& de);
	private:
		std::ifstream file_;
		uint64_t file_size_ = 0;
};
