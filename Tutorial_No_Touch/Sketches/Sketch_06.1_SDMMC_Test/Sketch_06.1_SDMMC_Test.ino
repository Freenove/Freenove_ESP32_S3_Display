/*
* @ File:   Sketch_06.1_SDMMC_Test.ino
* @ Author: [Eason Shen]
* @ Date:   [2026-05-15]
*/

#include "driver_sdmmc.h"

#define FNK0104AB_2P8_240x320_ILI9341
//#define FNK0104N_3P5_320x480_ST77922
//#define FNK0104S_4P0_320x480_ST7796

#ifdef FNK0104N_3P5_320x480_ST77922
 #define SD_MMC_CMD 4  // Please do not modify it.
 #define SD_MMC_CLK 5  // Please do not modify it.
 #define SD_MMC_D0  6  // Please do not modify it.
 #define SD_MMC_D1  7  // Please do not modify it.
 #define SD_MMC_D2  2  // Please do not modify it.
 #define SD_MMC_D3  3  // Please do not modify it.
#else
 #define SD_MMC_CMD 40  // Please do not modify it.
 #define SD_MMC_CLK 38  // Please do not modify it.
 #define SD_MMC_D0  39  // Please do not modify it.
 #define SD_MMC_D1  41  // Please do not modify it.
 #define SD_MMC_D2  48  // Please do not modify it.
 #define SD_MMC_D3  47  // Please do not modify it.
#endif
void setup() {
  // Initialize serial communication at 115200 bits per second
  Serial.begin(115200);
  delay(3000);

  // Initialize the SDMMC interface with the specified pins
  sdmmc_init(SD_MMC_CLK, SD_MMC_CMD, SD_MMC_D0, SD_MMC_D1, SD_MMC_D2, SD_MMC_D3);

  // List files in the root directory and print them
  std::list<File_Entry> fileList = list_dir("/", 0);
  print_file_list(fileList);

  // Create a new directory and list files again
  create_dir("/mydir");
  fileList = list_dir("/", 0);
  print_file_list(fileList);

  // Remove the directory and list files again
  remove_dir("/mydir");
  fileList = list_dir("/", 2);
  print_file_list(fileList);

  // Write text to a new file
  const char* text = "Hello ";
  write_file("/foo.txt", (const uint8_t*)text, strlen(text));

  // Append text to the existing file
  text = "World!\n";
  append_file("/foo.txt", (const uint8_t*)text, strlen(text));

  // Read the file content into a buffer and print it
  uint8_t buffer[100];
  read_file("/foo.txt", buffer, sizeof(buffer));
  Serial.write(buffer, strlen((char*)buffer));

  // Rename the file and read the new file content
  rename_file("/foo.txt", "/hello.txt");
  read_file("/hello.txt", buffer, sizeof(buffer));
  Serial.write(buffer, strlen((char*)buffer));

  // Print SD card information
  Serial.println("\r\nSD card info:");
  Serial.printf("Total space: %lluMB\r\n", SD_MMC.totalBytes() / (1024 * 1024));
  Serial.printf("Used space: %lluMB\r\n", SD_MMC.usedBytes() / (1024 * 1024));
}

void loop() {
  // Delay for 10 seconds before the next iteration
  delay(10000);
}
