#ifndef USBREADER_H
#define USBREADER_H

void printCommandHeader(String header);
void checkConnection(byte value);
void set_USB_Mode (byte value);
void resetALL();
void readFile(String fileName);
void writeFile(String fileName, String data);
void appendFile(String fileName, String data);
void setFileName(String fileName);
void diskConnectionStatus();
void fileOpen();
void USBdiskMount();
boolean setByteRead(byte numBytes);
int getFileSize();
void fileRead();
void fileWrite(String data);
boolean continueRead();
boolean fileCreate();
void fileDelete(String fileName);
void filePointer(boolean fileBeginning);
void fileClose(byte closeCmd);
boolean waitForResponse(String errorMsg);
byte getResponseFromUSB();
void blinkLED();

#endif //USBREADER_H
