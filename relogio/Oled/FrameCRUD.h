#ifndef FRAME_CRUD_H
#define FRAME_CRUD_H

#include <vector>
#include "OLEDDisplayUi.h"

class FrameCRUD
{
public:
  void addFrame(FrameCallback frame);
  void updateFrame(int index, FrameCallback frame);
  FrameCallback getFrame(int index);
  void deleteFrame(int index);

private:
  std::vector<FrameCallback> frames;
  int frameCount = 0;
};

extern FrameCRUD frameCrud;

#endif // FRAME_CRUD_H
