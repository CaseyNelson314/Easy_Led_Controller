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
        unsigned long nowTime = time - lastTime + cycle * j / ledGroups;
        for (int i = 0; i < 3; i++) {
          nowTime += cycle / 3;                                                //色相をずらす
          int sawtoothWave = (float)(nowTime % cycle) * maxPower * 3 / cycle;  //色相からRGBデータへ
          sawtoothWave %= maxPower * 3;                                        //のこぎり波変換
          sawtoothWave -= maxPower * 3 / 2;                                    //基準点ずらし
          ledData[j][i] = constrain(abs(sawtoothWave), 0, maxPower);           //三角波&台形波変換
        }
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

    byte GetR(byte arrayIndex = 0) {
      return ledData[arrayIndex][0];
    }
    byte GetG(byte arrayIndex = 0) {
      return ledData[arrayIndex][1];
    }
    byte GetB(byte arrayIndex = 0) {
      return ledData[arrayIndex][2];
    }

};
