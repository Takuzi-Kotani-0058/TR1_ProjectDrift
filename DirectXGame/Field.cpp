#include "Field.h"

using namespace KamataEngine;

Field::~Field() {

	delete model_;
	camera_ = nullptr;

}

Field::Field(Camera *camera) {

	worldTransform_.Initialize();
	model_ = Model::CreateFromOBJ("Field", false);

	camera_ = camera;

}

void Field::Draw() {

	model_->Draw(worldTransform_, *camera_);

}
