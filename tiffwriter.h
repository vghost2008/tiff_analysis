/********************************************************************************
 *   License     : 
 *   Author      : WangJie bluetornado@zju.edu.cn
 *   Description : 
 ********************************************************************************/
_Pragma("once")
#include <stdint.h>
#include <QString>
#include <QFile>
enum TiffDataType:uint16_t
{
	TDT_BYTE        =   1    ,   //unsigned byte
	TDT_ASCII       =   2    ,   
	TDT_SHORT       =   3    ,   //unsigned short(16-bit)
	TDT_LONG        =   4    ,   //unsigned (32-bit)
	TDT_RATIONAL    =   5    ,   //two long
	TDT_SBYTE       =   6    ,   //signed
	TDT_UNDEFINED   =   7    ,   
	TDT_SSHORT      =   8    ,   //signed short(16-bit)
	TDT_SLONG       =   9    ,   
	TDT_SRATIONAL   =   10   ,   
	TDT_FLOAT       =   11   ,   
	TDT_DOUBLE      =   12   ,   
};
enum TiffImageFileDirectoryID
{
	IFD_NEW_SUB_FILE_TYPE            =   0x00FE,
	IFD_IMAGE_WIDTH                  =   0x0100,
	IFD_IMAGE_LENGTH                 =   0x0101, //文件高
	IFD_BITS_PER_SAMPLE              =   0x0102,
	IFD_COMPRESSION                  =   0x0103,
	IFD_PHOTOMETRIC_INTERPRETATION   =   0x0106,
	IFD_SCRIP_OFFSET                 =   0x0111, //图像数据启始位置
	IFD_SAMPLES_PER_PIXEL            =   0x0115,
	IFD_ROWS_PER_STRIP               =   0x0116,
	IFD_SCRIP_BYTE_COUNTS            =   0x0117,
	IFD_X_RESOLUTION                 =   0x011A,
	IFD_Y_RESOLUTION                 =   0x011B,
	IFD_RESOLUTION_UNIT              =   0x0128,
};
enum TiffImageFileDirectoryIDIndex
{
	IFDI_NEW_SUB_FILE_TYPE            ,   
	IFDI_IMAGE_WIDTH                  ,   
	IFDI_IMAGE_LENGTH                 ,   
	IFDI_BITS_PER_SAMPLE              ,   
	IFDI_COMPRESSION                  ,   
	IFDI_PHOTOMETRIC_INTERPRETATION   ,   
	IFDI_SCRIP_OFFSET                 ,   
	IFDI_SAMPLES_PER_PIXEL            ,   
	IFDI_ROWS_PER_STRIP               ,   
	IFDI_SCRIP_BYTE_COUNTS            ,   
	IFDI_X_RESOLUTION                 ,   
	IFDI_Y_RESOLUTION                 ,   
	IFDI_RESOLUTION_UNIT              ,   
	IFDI_NR                           ,   
};
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
struct TiffIFD //准确的说这是DE而不是IFD
{
    uint16_t tag;
    uint16_t type;
    uint32_t count;             //count of type (if type is ascii, count include nullptr)
    uint32_t value_or_offset;
};
#pragma pack(0)
enum {
	TW_SEEK_FAILD          =   0x00000001,
	TW_ERROR_IMAGE_WIDTH   =   0x00000002,
	TW_OPEN_FILE_FAILD     =   0x00000004,
};
enum TiffImageType
{
	TIT_GRAYSCALE        ,   
	TIT_RGB_FULL_COLOR   ,   
};
class WTiffWriter
{
	public:
		WTiffWriter();
		/*
		 * 在open之前必须调用
		 * @image_width:指定图像宽度
		 * @image_type:指定图像类型
		 */
		int setOption(unsigned image_width,TiffImageType image_type=TIT_GRAYSCALE);
		int open(const QString& file_path);
		size_t write(const char* data,size_t size);
		int close();
		inline QString fileName()const { return file_name_; }
		inline bool isOpen()const { return file_.isOpen(); }
		inline unsigned imageWidth()const { return image_width_; }
	private:
		QFile         file_;
		unsigned      image_width_;
		TiffImageType image_type_;
		size_t        pure_data_size_;
		QString       file_name_;
	private:
		int writeDirectory(const TiffIFD& ifd,const unsigned index);
		int writeResolution();
		int writeScripOffset();
		int writeBitsPerSample();
		int writeSamplePerPixel();
};
