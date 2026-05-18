#pragma once

#include "KamataEngine.h"

class Field final {

private:

	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;

	// モデル
	KamataEngine::Model *model_ = nullptr;

	//　カメラ
	KamataEngine::Camera *camera_ = nullptr;

public:

	// デストラクタ
	~Field();

	// コンストラクタ
	Field(KamataEngine::Camera *camera);

	// 描画
	void Draw();

};