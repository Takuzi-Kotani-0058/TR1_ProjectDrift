#pragma once

#include "KamataEngine.h"

class Axis final {

private:

	// 軸表示のクラス
	KamataEngine::AxisIndicator *axis_ = nullptr;

	// カメラ
	KamataEngine::Camera *camera_ = nullptr;

	// 状態
	bool isVisible_ = true;

public:

	// デストラクタ
	~Axis();

	// コンストラクタ
	Axis(KamataEngine::Camera *camera);

	// 更新
	void Update();

	// 描画
	void Draw();

};

