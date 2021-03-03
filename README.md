#README

## Build

```
make
```

## Usage

```
./tiff_analysis file_path
```

## Example

./tiff_analysis 03-1095695-1_hp_003.svs

output:
```
HEAD, 49 49 2b 00 08 00 00 00 , ifd offset=8
HEAD, 49 49 2b 00 08 00 00 00     3a 24 00 00 00 00 00 00 , ifd offset=9274
BigTIFF
IFD DE nr: 19
DE, name=IFD_NEW_SUB_FILE_TYPE, type=DT_LONG, count=1, value_or_offset=1|
DE, name=IFD_IMAGE_WIDTH, type=DT_SHORT, count=1, value_or_offset=20480|
DE, name=IFD_IMAGE_LENGTH, type=DT_SHORT, count=1, value_or_offset=61440|
DE, name=IFD_BITS_PER_SAMPLE, type=DT_SHORT, count=3, value_or_offset=34360262664|
DE, name=IFD_COMPRESSION, type=DT_SHORT, count=1, value_or_offset=7|
DE, name=IFD_PHOTOMETRIC_INTERPRETATION, type=DT_SHORT, count=1, value_or_offset=2|
DE, name=IFD_IMAGEDESCRIPTION, type=DT_ASCII, count=111, value=Aperio Format Scanned By UNIC
20480x61440 [0,0 20480x61440 ] (512x512), JPEG/RGB Q=20|AppMag = 40|MPP = 0.344|
DE, name=IFD_SAMPLES_PER_PIXEL, type=DT_SHORT, count=1, value_or_offset=3|
DE, name=IFD_ROWS_PER_STRIP, type=DT_SHORT, count=1, value_or_offset=61440|
DE, name=IFD_X_RESOLUTION, type=DT_RATIONAL, count=1, value_or_offset=634568533082111|
DE, name=IFD_Y_RESOLUTION, type=DT_RATIONAL, count=1, value_or_offset=634568533082111|
DE, name=IFD_PLANARCONFIG, type=DT_SHORT, count=1, value_or_offset=1|
DE, name=IFD_PAGENAME, type=DT_ASCII, count=7, value=Layer0|
DE, name=IFD_RESOLUTION_UNIT, type=DT_SHORT, count=1, value_or_offset=3|
DE, name=IFD_TILEWIDTH, type=DT_SHORT, count=1, value_or_offset=512|
DE, name=IFD_TILELENGTH, type=DT_SHORT, count=1, value_or_offset=512|
DE, name=IFD_TILEOFFSETS, type=DT_LONG8, count=4800, value_or_offset=28870|
DE, name=IFD_TILEBYTECOUNTS, type=DT_LONG, count=4800, value_or_offset=9670|
DE, name=IFD_JPEGTABLES, type=DT_UNDEFINED, count=289, value_or_offset=67270|
IFD DE nr: 12
DE, name=IFD_IMAGE_WIDTH, type=DT_SHORT, count=1, value_or_offset=467|
DE, name=IFD_IMAGE_LENGTH, type=DT_SHORT, count=1, value_or_offset=1440|
DE, name=IFD_BITS_PER_SAMPLE, type=DT_SHORT, count=3, value_or_offset=34360262664|
DE, name=IFD_COMPRESSION, type=DT_SHORT, count=1, value_or_offset=7|
DE, name=IFD_PHOTOMETRIC_INTERPRETATION, type=DT_SHORT, count=1, value_or_offset=2|
DE, name=IFD_IMAGEDESCRIPTION, type=DT_ASCII, count=25, value=UNIC
thumbnail 467x1440|
DE, name=IFD_SCRIP_OFFSET, type=DT_LONG8, count=1, value_or_offset=339659702|
DE, name=IFD_SAMPLES_PER_PIXEL, type=DT_SHORT, count=1, value_or_offset=3|
DE, name=IFD_ROWS_PER_STRIP, type=DT_SHORT, count=1, value_or_offset=1440|
DE, name=IFD_SCRIP_BYTE_COUNTS, type=DT_LONG8, count=1, value_or_offset=123546|
DE, name=IFD_PLANARCONFIG, type=DT_SHORT, count=1, value_or_offset=1|
DE, name=IFD_JPEGTABLES, type=DT_UNDEFINED, count=289, value_or_offset=651162|
IFD DE nr: 15
DE, name=IFD_NEW_SUB_FILE_TYPE, type=DT_LONG, count=1, value_or_offset=1|
DE, name=IFD_IMAGE_WIDTH, type=DT_SHORT, count=1, value_or_offset=10240|
DE, name=IFD_IMAGE_LENGTH, type=DT_SHORT, count=1, value_or_offset=30720|
DE, name=IFD_BITS_PER_SAMPLE, type=DT_SHORT, count=3, value_or_offset=34360262664|
DE, name=IFD_COMPRESSION, type=DT_SHORT, count=1, value_or_offset=7|
DE, name=IFD_PHOTOMETRIC_INTERPRETATION, type=DT_SHORT, count=1, value_or_offset=2|
DE, name=IFD_SAMPLES_PER_PIXEL, type=DT_SHORT, count=1, value_or_offset=3|
DE, name=IFD_ROWS_PER_STRIP, type=DT_SHORT, count=1, value_or_offset=30720|
DE, name=IFD_PLANARCONFIG, type=DT_SHORT, count=1, value_or_offset=1|
DE, name=IFD_PAGENAME, type=DT_ASCII, count=7, value=Layer1|
DE, name=IFD_TILEWIDTH, type=DT_SHORT, count=1, value_or_offset=512|
DE, name=IFD_TILELENGTH, type=DT_SHORT, count=1, value_or_offset=512|
DE, name=IFD_TILEOFFSETS, type=DT_LONG8, count=1200, value_or_offset=665846|
DE, name=IFD_TILEBYTECOUNTS, type=DT_LONG, count=1200, value_or_offset=661046|
DE, name=IFD_JPEGTABLES, type=DT_UNDEFINED, count=289, value_or_offset=675446|
IFD DE nr: 15
DE, name=IFD_NEW_SUB_FILE_TYPE, type=DT_LONG, count=1, value_or_offset=1|
DE, name=IFD_IMAGE_WIDTH, type=DT_SHORT, count=1, value_or_offset=5120|
DE, name=IFD_IMAGE_LENGTH, type=DT_SHORT, count=1, value_or_offset=15360|
DE, name=IFD_BITS_PER_SAMPLE, type=DT_SHORT, count=3, value_or_offset=34360262664|
DE, name=IFD_COMPRESSION, type=DT_SHORT, count=1, value_or_offset=7|
DE, name=IFD_PHOTOMETRIC_INTERPRETATION, type=DT_SHORT, count=1, value_or_offset=2|
DE, name=IFD_SAMPLES_PER_PIXEL, type=DT_SHORT, count=1, value_or_offset=3|
DE, name=IFD_ROWS_PER_STRIP, type=DT_SHORT, count=1, value_or_offset=15360|
DE, name=IFD_PLANARCONFIG, type=DT_SHORT, count=1, value_or_offset=1|
DE, name=IFD_PAGENAME, type=DT_ASCII, count=7, value=Layer2|
DE, name=IFD_TILEWIDTH, type=DT_SHORT, count=1, value_or_offset=512|
DE, name=IFD_TILELENGTH, type=DT_SHORT, count=1, value_or_offset=512|
DE, name=IFD_TILEOFFSETS, type=DT_LONG8, count=300, value_or_offset=825364|
DE, name=IFD_TILEBYTECOUNTS, type=DT_LONG, count=300, value_or_offset=824164|
DE, name=IFD_JPEGTABLES, type=DT_UNDEFINED, count=289, value_or_offset=827764|
IFD DE nr: 15
DE, name=IFD_NEW_SUB_FILE_TYPE, type=DT_LONG, count=1, value_or_offset=1|
DE, name=IFD_IMAGE_WIDTH, type=DT_SHORT, count=1, value_or_offset=2560|
DE, name=IFD_IMAGE_LENGTH, type=DT_SHORT, count=1, value_or_offset=7680|
DE, name=IFD_BITS_PER_SAMPLE, type=DT_SHORT, count=3, value_or_offset=34360262664|
DE, name=IFD_COMPRESSION, type=DT_SHORT, count=1, value_or_offset=7|
DE, name=IFD_PHOTOMETRIC_INTERPRETATION, type=DT_SHORT, count=1, value_or_offset=2|
DE, name=IFD_SAMPLES_PER_PIXEL, type=DT_SHORT, count=1, value_or_offset=3|
DE, name=IFD_ROWS_PER_STRIP, type=DT_SHORT, count=1, value_or_offset=7680|
DE, name=IFD_PLANARCONFIG, type=DT_SHORT, count=1, value_or_offset=1|
DE, name=IFD_PAGENAME, type=DT_ASCII, count=7, value=Layer3|
DE, name=IFD_TILEWIDTH, type=DT_SHORT, count=1, value_or_offset=512|
DE, name=IFD_TILELENGTH, type=DT_SHORT, count=1, value_or_offset=512|
DE, name=IFD_TILEOFFSETS, type=DT_LONG8, count=75, value_or_offset=865698|
DE, name=IFD_TILEBYTECOUNTS, type=DT_LONG, count=75, value_or_offset=865398|
DE, name=IFD_JPEGTABLES, type=DT_UNDEFINED, count=289, value_or_offset=866298|
```
