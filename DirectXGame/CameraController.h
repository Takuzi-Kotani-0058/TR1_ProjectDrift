#pragma once

#include "KamataEngine.h"

//-----------------
// 前方宣言

class PlayerCar;

//
//-----------------

// カメラ制御
class CameraController final {

private:

	//　プレイヤー
	PlayerCar *player_ = nullptr;

	// カメラ
	KamataEngine::Camera *camera_ = nullptr;

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="player"></param>
	/// <param name="camera"></param>
	CameraController(PlayerCar *player, KamataEngine::Camera *camera);

	// 更新
	void Update();

};

