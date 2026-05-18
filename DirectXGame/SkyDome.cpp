#include "SkyDome.h"

using namespace KamataEngine;

SkyDome::~SkyDome() {

	delete model_;
	camera_ = nullptr;

}

SkyDome::SkyDome(Camera *camera) {

	worldTransform_.Initialize();
	camera_ = camera;

	model_ = Model::CreateFromOBJ("SkyDome", true);

}

void SkyDome::Draw() {

	model_->Draw(worldTransform_, *camera_);

}