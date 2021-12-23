/*
        @file   LedControl.h
        @brief  LEDコントローラー
        @author CaseyNelson314
        @date   2021/12/22
*/
#pragma once

class LedControl {
    long cycle;
    int  ledNum;
    int  ledGroups;
    byte maxPower = 255;
    byte **ledData;
    unsigned int time, lastTime;

  public:
    LedControl(long CYCLE, int LEDNUM = 1, int LEDGROUPS = 1):
      cycle(CYCLE), ledNum(LEDNUM), ledGroups(LEDGROUPS) {
      ledData = new byte*[ledNum];
      for (int i = 0; i < ledNum; i++)
        ledData[i] = new byte[3];
      for (int j = 0; j < ledNum; j++)
        for (int i = 0; i < 3; i++)
          ledData[j][i] = 0;
    }
    ~LedControl() {
      for (int i = 0; i < ledNum; i++)
        delete[] ledData[i];
      delete[] ledData;
    }

    void Update() {
      if ((time = millis()) - lastTime > cycle)
        lastTime = time;
      for (int j = 0; j < ledNum; j++) {
        float nowTime = (time - lastTime) * (float)2 / cycle - (float)j * 2 / ledGroups;
        for (int i = 0; i < 3; i++)
          ledData[j][i] = maxPower * (sin(fmod(nowTime - (float)i * 2 / 3, 2) * PI) + 1) / 2;
      }
    }

    void SetGroups(int groupSum) {
      ledGroups = groupSum;
    }
    void SetSpeed(long cycle) {
      this->cycle = cycle;
    }
    void SetBrightness(byte maxPower) {
      this->maxPower = maxPower;
    }

    int GetR(byte arrayIndex = 0) {
      return ledData[arrayIndex][0];
    }
    byte GetG(byte arrayIndex = 0) {
      return ledData[arrayIndex][1];
    }
    byte GetB(byte arrayIndex = 0) {
      return ledData[arrayIndex][2];
    }

};
