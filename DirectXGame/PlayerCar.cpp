#include "PlayerCar.h"

#include <cmath>
#include <iostream>
#include <algorithm>

#include "MathMatrix4x4.h"
#include "Lerp.h"

using namespace KamataEngine;

PlayerCar::~PlayerCar() {

}

PlayerCar::PlayerCar(Camera *camera) {

	worldTransform_.Initialize();
	worldTransform_.translation_.y = 0.3f;
	model_ = Model::CreateFromOBJ("PlayerCar", true);
	camera_ = camera;

	input_ = Input::GetInstance();

}

void PlayerCar::Input() {

	switch (isControllingUsingImGui_) {

		case false:

			///---------------------------------------
			/// キーボード入力
			///

			#pragma region keyboard

			accel_ = 0.0f;
			brake_ = 0.0f;
			steer_ = 0.0f;

			//----------------------------
			// アクセル, ブレーキ

			if (input_->PushKey(DIK_W) || input_->PushKey(DIK_UP)) {
				accel_ = 1.0f;
			}

			if (input_->PushKey(DIK_S) || input_->PushKey(DIK_DOWN) || input_->PushKey(DIK_SPACE)) {
				brake_ = 1.0f;
			}

			//
			//----------------------------

			//----------------------------
			// ステアリング

			if (input_->PushKey(DIK_A) || input_->PushKey(DIK_LEFT)) {
				steer_ -= 1.0f;
			}

			if (input_->PushKey(DIK_D) || input_->PushKey(DIK_RIGHT)) {
				steer_ += 1.0f;
			}

			//
			//----------------------------

			#pragma endregion

			///
			///
			///--------------------------------------

			break;

		case true:

			///---------------------------------------
			/// ImGui入力
			///

			#ifdef _DEBUG

			ImGui::Begin("CarController");

			ImGui::SliderFloat("Accel", &accel_, 0.0f, 1.0f);
			ImGui::SliderFloat("Brake", &brake_, 0.0f, 1.0f);
			ImGui::SliderFloat("Steer", &steer_, -1.0f, 1.0f);

			ImGui::End();

			#endif

			///
			///
			///--------------------------------------

			break;

	}

}

void PlayerCar::ChangeMode() {

	if (input_->TriggerKey(DIK_P)) {

		if (isControllingUsingImGui_) {
			isControllingUsingImGui_ = false;
		} else {
			isControllingUsingImGui_ = true;
		}

		// 入力状態のリセット
		accel_ = 0.0f;
		brake_ = 0.0f;
		steer_ = 0.0f;

	}

}

void PlayerCar::UpdateVelocity() {

	///----------------------------------
	/// 速度変更
	///

	currentSpeed_ += accel_ * acceleration_;
	currentSpeed_ -= brake_ * brakePower_;

	///
	///
	///----------------------------------

	///----------------------------------
	/// 方向変更
	///

	// 車輌方向更新
	worldTransform_.rotation_.y += steer_ * rotationSpeed_;

	///
	///
	///----------------------------------

	///----------------------------------
	/// ベクトル更新
	///

	//----------------------------
	//
	
	// 角度がついていた場合減速
	currentSpeed_ -= std::fabsf(worldTransform_.rotation_.y - velocityRotation_) * slipSpeedLoss_;

	// clampで最高速調整
	currentSpeed_ = std::clamp(currentSpeed_, 0.0f, maxSpeed_);

	// lerpで慣性をつける
	velocityRotation_ = Lerpf(velocityRotation_, worldTransform_.rotation_.y,(maxSpeed_ - currentSpeed_) / maxSpeed_);

	//
	//----------------------------

	// ベクトル更新
	velocity_.x = std::cosf(velocityRotation_) * currentSpeed_;
	velocity_.z = -std::sinf(velocityRotation_) * currentSpeed_;

	// 座標更新
	worldTransform_.translation_.x += velocity_.x;
	worldTransform_.translation_.z += velocity_.z;

	// 行列転送
	worldTransform_.matWorld_ = MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);
	worldTransform_.TransferMatrix();

	///
	///
	///----------------------------------

}

void PlayerCar::Update() {

	///--------------------------
	/// 入力
	///

	ChangeMode();

	Input();

	///
	///
	///--------------------------

	///--------------------------
	/// 更新
	///

	UpdateVelocity();

	///
	///
	///--------------------------

	#ifdef _DEBUG

	//-----------------------------------
	// 車のプロパティ設定

	ImGui::Begin("CarProperties");

	ImGui::SliderFloat("MaxSpeed", &maxSpeed_, 0.0f, 30.0f);
	ImGui::SliderFloat("Acceleration", &acceleration_, 0.0f, 30.0f);
	ImGui::SliderFloat("BrakePower", &brakePower_, 0.0f, 30.0f);
	ImGui::SliderFloat("RotationSpeed", &rotationSpeed_, 0.0f, 0.2f);
	ImGui::SliderFloat("SlipSpeedLoss", &slipSpeedLoss_, 0.0f, 1.0f);

	ImGui::End();

	//
	//-----------------------------------

	//-----------------------------------
	// 状態出力

	ImGui::Begin("Stats");

	ImGui::SeparatorText("FloatValues");

	ImGui::Text("Speed: %.3f", currentSpeed_);
	ImGui::Text("CarRotation: %.3f", worldTransform_.rotation_.y);
	ImGui::Text("VelocityRotation: %.3f", velocityRotation_);

	ImGui::SeparatorText("Velocity");

	ImGui::Text("Velocity: { X: %.3f, Y: %.3f, Z: %.3f }", velocity_.x, velocity_.y, velocity_.z);

	ImGui::SeparatorText("Debug");

	ImGui::Text("IsControllingUsingImGui: %d", isControllingUsingImGui_);

	ImGui::End();

	//
	//-----------------------------------

	//-----------------------------------
	// 入力状態の出力

	ImGui::Begin("Input");

	ImGui::SeparatorText("CarControl");

	ImGui::Text("Accel: %.3f", accel_);
	ImGui::Text("Brake: %.3f", brake_);
	ImGui::Text("Steer: %.3f", steer_);

	ImGui::End();

	//
	//-----------------------------------

	#endif

}

void PlayerCar::Draw() {

	model_->Draw(worldTransform_, *camera_);

}