#include "FrameCRUD.h"

void FrameCRUD::addFrame(FrameCallback frame)
{
  frames.push_back(frame);
  frameCount++;
}

void FrameCRUD::updateFrame(int index, FrameCallback frame)
{
  if (index >= 0 && index < frameCount)
  {
    frames[index] = frame;
  }
}

FrameCallback FrameCRUD::getFrame(int index)
{
  if (index >= 0 && index < frameCount)
  {
    return frames[index];
  }
  return nullptr;
}

void FrameCRUD::deleteFrame(int index)
{
  if (index >= 0 && index < frameCount)
  {
    frames.erase(frames.begin() + index);
    frameCount--;
  }
}

FrameCRUD frameCrud;
