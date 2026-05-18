#pragma once

#include "KamataEngine.h"

class SkyDome final {

private:

	///---------------------------------------------
	///
	///

	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;

	// カメラ
	KamataEngine::Camera *camera_;

	///
	///
	///---------------------------------------------

	// モデル
	KamataEngine::Model *model_ = nullptr;

public:

	// デストラクタ
	~SkyDome();

	// コンストラクタ
	SkyDome(KamataEngine::Camera *camera);

	// 描画
	void Draw();

};