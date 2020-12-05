#include <iostream>
#include "wtiff.h"
#include "wbigtiff.h"

using namespace std;

int main(int argc,char** argv)
{
	if(1==argc) {
		cout<<"Usage ./run svs_path.svs"<<endl;
		return 0;
	}

	if(TIFF::detection(argv[1])) {
		TIFF tiff(argv[1]);
		tiff.showInfo();
	} else {
		BigTIFF tiff(argv[1]);
		tiff.showInfo();
	}

	return 0;
}
