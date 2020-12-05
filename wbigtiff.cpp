#include "wbigtiff.h"
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>

using namespace std;

BigTIFF::BigTIFF(const std::string& path)
:file_(path,ios_base::in|ios::binary)
{
	file_.seekg(0,ios::end);
	file_size_ = file_.tellg();
}
BigTIFF::~BigTIFF()
{
	file_.close();
}
void BigTIFF::showInfo()
{
	uint64_t ifd_offset;
	readHead(ifd_offset);
	readAllIFDS(ifd_offset);
}
bool BigTIFF::readHead(uint64_t& ifd_offset)
{
    file_.seekg(0);
    BigTiffHead head;
    file_.read((char*)&head,sizeof(head));

    auto v = toHexString((const unsigned char*)&head,sizeof(head),8,3);

    cout<<"HEAD, "<<v<<", ifd offset="<<head.ifd_offset<<endl;
    ifd_offset = head.ifd_offset;

    if((head.version != 0x2b)
            || (head.id  != 0x08)
            || (head.zeros != 0x00))
        return false;
	cout<<"BigTIFF"<<endl;
    return true;
}
bool BigTIFF::readIFD(uint64_t offset,uint64_t& next_ifd_offset,int max_show_nr)
{
	uint64_t de_nr;
	file_.seekg(offset);
	file_.read((char*)&de_nr,sizeof(de_nr));
	cout<<"IFD DE nr: "<<de_nr<<endl;
	
	for(auto i=0; i<de_nr; ++i) {
		BigTiffDE de;
		file_.read((char*)&de,sizeof(de));
		if(i<max_show_nr)
			showDE(de);
	}
	file_.read((char*)&next_ifd_offset,sizeof(next_ifd_offset));
}
void BigTIFF::showDE(const BigTiffDE& de)
{
	const auto name = idToName(de.tag);
	const auto type = typeToName(de.type);

	if(TDT_ASCII == de.type) {
		string value;
		if(de.count>8) {
			auto c_value = shared_ptr<char>(new char[de.count]);
			auto pos = file_.tellg();
			file_.seekg(de.value_or_offset);
			file_.read(c_value.get(),de.count);
			file_.seekg(pos);
			value = c_value.get();
		} else {
			value = (char*)(&de.value_or_offset);
		}
		cout<<"DE, name="<<name<<", type="<<type<<", count="<<de.count<<", value="<<value<<"|"<<endl;
    } else {
		cout<<"DE, name="<<name<<", type="<<type<<", count="<<de.count<<", value_or_offset="<<de.value_or_offset<<"|"<<endl;
	}
}
bool BigTIFF::readAllIFDS(uint64_t offset)
{
	uint64_t next_offset;

	do {
		if(offset>=file_size_) {
			cout<<"ERROR IFD OFFSET "<<offset<<", file size "<<file_size_<<endl;
			break;
		}
		readIFD(offset,next_offset);
		offset = next_offset;
	} while(offset>0);
}
bool BigTIFF::detection(const std::string& path)
{
	BigTIFF tiff(path);
	uint64_t offset;
	return tiff.readHead(offset);
}
