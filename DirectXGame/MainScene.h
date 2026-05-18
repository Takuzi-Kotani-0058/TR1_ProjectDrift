#pragma once

#include "KamataEngine.h"

#include "PlayerCar.h"
#include "Field.h"
#include "Axis.h"
#include "ControlInformation.h"
#include "CameraController.h"

class MainScene final {

private:

	///----------------------------------------------
	///
	///

	// カメラ
	KamataEngine::Camera camera_;

	// カメラコントローラ
	CameraController *cameraController_ = nullptr;

	///
	///
	///----------------------------------------------

	///----------------------------------------------
	/// オブジェクト
	///
	  
	// プレイヤーカー
	PlayerCar *playerCar_ = nullptr;

	// 地面
	Field *field_ = nullptr;

	// 軸方向表示
	Axis *axis_ = nullptr;

	// 操作説明用のImGui表示
	ControlInformation *controlInfo = nullptr;

	///
	///
	///----------------------------------------------

public:

	// デストラクタ
	~MainScene();

	// コンストラクタ
	MainScene();

	// 更新
	void Update();

	// 描画
	void Draw();

};