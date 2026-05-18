#include "CameraController.h"

#include <numbers>

#include "PlayerCar.h"

using namespace KamataEngine;

CameraController::CameraController(PlayerCar *player, Camera *camera) {

	player_ = player;
	camera_ = camera;

}

void CameraController::Update() {

	// 座標更新
	camera_->translation_.x = player_->GetWorldTransform().translation_.x;
	camera_->translation_.y = 100.0f;
	camera_->translation_.z = player_->GetWorldTransform().translation_.z - 30.0f;
	camera_->rotation_ = { 4.0f / float(std::numbers::pi),0.0f,0.0f};

	camera_->UpdateMatrix();
	camera_->TransferMatrix();

}