/********************************************************************************
 *   License     : 
 *   Author      : WangJie bluetornado@zju.edu.cn
 *   Description : 
 ********************************************************************************/
_Pragma("once")
#include <stdint.h>
#include <string>
#include <fstream>

enum TiffDataType:uint16_t
{
	TDT_BYTE       =  1   ,  //unsigned byte
	TDT_ASCII      =  2   ,  
	TDT_SHORT      =  3   ,  //unsigned short(16-bit)
	TDT_LONG       =  4   ,  //unsigned (32-bit)
	TDT_RATIONAL   =  5   ,  //two long
	TDT_SBYTE      =  6   ,  //signed
	TDT_UNDEFINED  =  7   ,  
	TDT_SSHORT     =  8   ,  //signed short(16-bit)
	TDT_SLONG      =  9   ,  
	TDT_SRATIONAL  =  10  ,  
	TDT_FLOAT      =  11  ,  
	TDT_DOUBLE     =  12  ,  
	TDT_LONG8      =  16  ,  //being unsigned 8byte integer
	TDT_SLONG8     =  17  ,  //being signed 8byte integer
	TDT_IFD8       =  18  ,  //being a new unsigned 8byte IFD offset.
};
enum TiffImageFileDirectoryID
{
	IFD_NEW_SUB_FILE_TYPE           =  0x00FE  ,  
	IFD_IMAGE_WIDTH                 =  0x0100  ,  
	IFD_IMAGE_LENGTH                =  0x0101  ,  //文件高
	IFD_BITS_PER_SAMPLE             =  0x0102  ,  
	IFD_COMPRESSION                 =  0x0103  ,  
	IFD_PHOTOMETRIC_INTERPRETATION  =  0x0106  ,  
	IFD_SCRIP_OFFSET                =  0x0111  ,  //图像数据启始位置
	IFD_SAMPLES_PER_PIXEL           =  0x0115  ,  
	IFD_ROWS_PER_STRIP              =  0x0116  ,  
	IFD_SCRIP_BYTE_COUNTS           =  0x0117  ,  
	IFD_X_RESOLUTION                =  0x011A  ,  
	IFD_Y_RESOLUTION                =  0x011B  ,  
	IFD_RESOLUTION_UNIT             =  0x0128  ,  
	IFD_TILEWIDTH                   =  322     ,  
	IFD_TILELENGTH                  =  323     ,  
	IFD_TILEOFFSETS                 =  324     ,  
	IFD_TILEBYTECOUNTS              =  325     ,  
	IFD_SUBFILETYPE                 =  254     ,  
	IFD_IMAGEDESCRIPTION            =  270     ,  
	IFD_ORIENTATION                 =  274     ,  
	IFD_XRESOLUTION                 =  282     ,  
	IFD_YRESOLUTION                 =  283     ,  
	IFD_PLANARCONFIG                =  284     ,  
	IFD_PAGENAME                    =  285     ,  
	IFD_RESOLUTIONUNIT              =  296     ,  
	IFD_ARTIST                      =  315     ,  
	IFD_JPEGTABLES                  =  347     ,  
	IFD_IMAGEDEPTH                  =  32997   ,  
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
class WAbstractTIFF
{
	public:
		virtual std::string typeToName(uint32_t type);
		virtual std::string idToName(uint32_t id);
		static std::string toHexString(const unsigned char* data,int size,int unit_nr=8,int column=3);

};
