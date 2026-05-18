#pragma once

#include "KamataEngine.h"

class PlayerCar final {

private:

	///---------------------------------------------
	/// 3Dデータ
	///

	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;

	// モデル
	KamataEngine::Model *model_ = nullptr;

	// カメラ
	KamataEngine::Camera *camera_ = nullptr;

	///
	///
	///---------------------------------------------

	///---------------------------------------------
	/// ベクトル
	///

	// 車が向いている方向
	float carRotation_ = 0.0f;

	// ベクトル方向
	float velocityRotation_ = 0.0f;

	// 速度
	float currentSpeed_ = 0.0f;

	// ベクトル
	KamataEngine::Vector3 velocity_ = {};

	///
	///
	///---------------------------------------------

	///---------------------------------------------
	/// プロパティ
	///

	#pragma region properties

	// 最高速度
	float maxSpeed_ = 10.0f;

	// 加速
	float acceleration_ = 0.1f;

	// ブレーキ力
	float brakePower_ = 0.5f;

	// 曲がりやすさ
	float rotationSpeed_ = 0.1f;

	// 滑ることによる速度減衰率
	float slipSpeedLoss_ = 0.08f;

	// ImGui操作するかどうか
	bool isControllingUsingImGui_ = false;

	#pragma endregion

	///
	///
	///---------------------------------------------

	///---------------------------------------------
	/// 操縦
	///

	// アクセル
	float accel_ = 0.0f;

	// ブレーキ
	float brake_ = 0.0f;

	// ステアリング
	float steer_ = 0.0f;

	///
	///
	///---------------------------------------------

	///---------------------------------------------
	/// シングルトン
	///

	// 入力
	KamataEngine::Input *input_ = nullptr;

	///
	///
	///---------------------------------------------

	///---------------------------------------------
	/// 関数
	///

	// 入力
	void Input();

	// 入力モード切り替え
	void ChangeMode();

	// ベクトル更新
	void UpdateVelocity();

	///
	///
	///---------------------------------------------

public:

	// デストラクタ
	~PlayerCar();

	// コンストラクタ
	PlayerCar(KamataEngine::Camera *camera);

	// 更新
	void Update();

	// 描画
	void Draw();

	///---------------------------------------------
	/// アクセッサ
	///

	// ワールド変換データ取得
	const KamataEngine::WorldTransform &GetWorldTransform() const { return worldTransform_; }


	///
	///
	///---------------------------------------------

};