#include "MainScene.h"

using namespace KamataEngine;

MainScene::~MainScene() {

	delete playerCar_;

	delete axis_;

	delete controlInfo;
	
	delete field_;

	delete cameraController_;

}

MainScene::MainScene() {

	camera_.Initialize();

	camera_.translation_ = { 0.0f,10.0f,0.0f };
	camera_.rotation_ = { 0.0f,0.0f,0.0f};
	camera_.UpdateMatrix();

	///-------------------------------------------
	/// オブジェクト
	///

	playerCar_ = new PlayerCar(&camera_);

	field_ = new Field(&camera_);

	axis_ = new Axis(&camera_);

	controlInfo = new ControlInformation();

	cameraController_ = new CameraController(playerCar_, &camera_);

	///
	///
	///-------------------------------------------

}

void MainScene::Update() {

	playerCar_->Update();

	axis_->Update();
	controlInfo->Update();

	cameraController_->Update();

}

void MainScene::Draw() {

	Model::PreDraw();

	playerCar_->Draw();

	field_->Draw();

	axis_->Draw();

	Model::PostDraw();

}