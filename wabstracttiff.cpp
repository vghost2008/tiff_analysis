#include "wabstracttiff.h"
#include <iomanip>
#include <map>

using namespace std;

string WAbstractTIFF::typeToName(uint32_t type)
{
    const map<int,string> type_to_name = {{TDT_BYTE        ,"DT_BYTE"},        
        {TDT_ASCII       ,"DT_ASCII"},       
        {TDT_SHORT       ,"DT_SHORT"},       
        {TDT_LONG        ,"DT_LONG"},        
        {TDT_RATIONAL    ,"DT_RATIONAL"},    
        {TDT_SBYTE       ,"DT_SBYTE"},       
        {TDT_UNDEFINED   ,"DT_UNDEFINED"},   
        {TDT_SSHORT      ,"DT_SSHORT"},      
        {TDT_SLONG       ,"DT_SLONG"},       
        {TDT_SRATIONAL   ,"DT_SRATIONAL"},   
        {TDT_FLOAT       ,"DT_FLOAT"},       
        {TDT_DOUBLE      ,"DT_DOUBLE"},
        {TDT_LONG8,"DT_LONG8"},
        {TDT_SLONG8,"DT_SLONG8"},
        {TDT_IFD8,"IFD8"},
    };

	string type_name;
	if(type_to_name.find(type) != type_to_name.end()) {
		type_name = type_to_name.at(type);
	} else {
		type_name = to_string(type);
	}
	return type_name;
}
string WAbstractTIFF::idToName(uint32_t id)
{
	const map<int,string> id_to_name = {
		{IFD_NEW_SUB_FILE_TYPE            ,"IFD_NEW_SUB_FILE_TYPE"},            
		{IFD_IMAGE_WIDTH                  ,"IFD_IMAGE_WIDTH"},                  
		{IFD_IMAGE_LENGTH                 ,"IFD_IMAGE_LENGTH"},                 
		{IFD_BITS_PER_SAMPLE              ,"IFD_BITS_PER_SAMPLE"},              
		{IFD_COMPRESSION                  ,"IFD_COMPRESSION"},                  
		{IFD_PHOTOMETRIC_INTERPRETATION   ,"IFD_PHOTOMETRIC_INTERPRETATION"},   
		{IFD_SCRIP_OFFSET                 ,"IFD_SCRIP_OFFSET"},                 
		{IFD_SAMPLES_PER_PIXEL            ,"IFD_SAMPLES_PER_PIXEL"},            
		{IFD_ROWS_PER_STRIP               ,"IFD_ROWS_PER_STRIP"},               
		{IFD_SCRIP_BYTE_COUNTS            ,"IFD_SCRIP_BYTE_COUNTS"},            
		{IFD_X_RESOLUTION                 ,"IFD_X_RESOLUTION"},                 
		{IFD_Y_RESOLUTION                 ,"IFD_Y_RESOLUTION"},                 
		{IFD_RESOLUTION_UNIT              ,"IFD_RESOLUTION_UNIT"},
		{IFD_TILEWIDTH                   ,"IFD_TILEWIDTH"},                   
		{IFD_TILELENGTH                  ,"IFD_TILELENGTH"},                  
		{IFD_TILEOFFSETS                 ,"IFD_TILEOFFSETS"},                 
		{IFD_TILEBYTECOUNTS              ,"IFD_TILEBYTECOUNTS"},              
		{IFD_SUBFILETYPE                 ,"IFD_SUBFILETYPE"},                 
		{IFD_IMAGEDESCRIPTION            ,"IFD_IMAGEDESCRIPTION"},            
		{IFD_XRESOLUTION                 ,"IFD_XRESOLUTION"},                 
		{IFD_YRESOLUTION                 ,"IFD_YRESOLUTION"},                 
		{IFD_ORIENTATION                 ,"IFD_ORIENTATION"},
		{IFD_PAGENAME                    ,"IFD_PAGENAME"},                    
		{IFD_RESOLUTIONUNIT              ,"IFD_RESOLUTIONUNIT"},
	    {IFD_PLANARCONFIG                ,"IFD_PLANARCONFIG"},
		{IFD_IMAGEDEPTH, "IFD_IMAGEDEPTH"},
	    {IFD_ARTIST,"IFD_ARTIST"},
		{IFD_JPEGTABLES ,"IFD_JPEGTABLES"}};
	string name;
	if(id_to_name.find(id) != id_to_name.end()) {
		name = id_to_name.at(id);
	} else {
		name = toHexString((const unsigned char*)&id,sizeof(id),8,1)+"\\"+to_string(id);
	}
	return name;
}
std::string WAbstractTIFF::toHexString(const unsigned char* data,int size,int unit_nr,int column)
{
	int          i;
	int          j;
	stringstream ret_val;
	const int    elements_every_row = unit_nr *column; //每行的字符数

	ret_val<<setfill('0')<<hex;
	for(i=0; i<size;) {
		for(j=0; j<elements_every_row&&i<size; ++j,++i) {
			if(j%unit_nr== 0 && j) ret_val<<"    ";
			ret_val<<setw(2)<<((uint)data[i])<<" ";
		}
		if(i<size)
			ret_val<<"\n";
	}
	return ret_val.str();
}
