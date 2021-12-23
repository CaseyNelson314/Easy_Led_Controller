# Easy_Led_Controller

フルカラーLEDの制御を簡単に行えます

複数のLEDを流れるように色相を変化させることができるにょ

プログラム内に多少遅延がある場合も正常に動作します(自動補正)


## 動作イメージ
![](/img/gradation.jpg)

<a href=/sin_wave_version><h2>正弦波バージョン</h2></a>

コンストラクタや関数は同じ

色相の変化をsin波をもとに計算


# constructor
 ```
 LedControl(long CYCLE, int LEDNUM = 1, int LEDGROUPS = 1)
 ```
 
 CYCLE：色相が１周する周期
 
 LEDNUM：LEDの個数
 
 LEDGROUPS：色相の変化はLED何個の間で行うか


# Function list
 setter
 ```
 void SetGroups(int groupSum)       :LEDのグループ数設定(初期値1)
 void SetSpeed(long cycle)          :変化速度設定
 void SetBrightness(byte maxPower)  :最高輝度設定(初期値255)
 ```
 
 getter
 ```
 byte GetR(byte arrayIndex = 0)      :赤　引数に取得したいLEDの番号を指定 [GetR(0):0番目のLEDデータ取得]
 byte GetG(byte arrayIndex = 0)      :緑
 byte GetB(byte arrayIndex = 0)      :青
 ```

# 基本原理

### ↓のこぎり波アジャスト！

![](/img/のこぎり.png)

### ↓ずりずりずりゅりゅ

![](/img/基準ずらし.png)

### ↓絶対値

![](/img/絶対値.png)

### ↓頭をぽい

![](/img/切り捨て.png)

### ↓ぽんっ(X軸をずらす)

![](/img/まじぇまじぇ.png)

### げーみんぐげーみんぐ🎌
