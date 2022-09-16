#include "Image.h"
#include "StickerSheet.h"

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  Image bunny; bunny.readFromFile("/workspaces/CS225/release-f22/mp_stickers/myImage.png");
  Image butterfly; butterfly.readFromFile("/workspaces/CS225/release-f22/mp_stickers/butterflies.png");
  StickerSheet sheet(bunny, 5);
  sheet.addSticker(butterfly, 20, 200);
  sheet.addSticker(butterfly, 40, 500);
  sheet.addSticker(butterfly, 40, 800);
  Image output = sheet.render();
  output.writeToFile("../myImage.png");
  return 0;
}
