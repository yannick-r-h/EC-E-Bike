#include <SPI.h>
#include <SD.h>
#include "variables.h"

bool sdSetup(){
  SD.begin(chipSelect);
}
