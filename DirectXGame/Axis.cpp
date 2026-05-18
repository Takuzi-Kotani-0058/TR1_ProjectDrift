#include "Axis.h"

using namespace KamataEngine;

Axis::~Axis() {

}

Axis::Axis(Camera *camera) {

	axis_ = AxisIndicator::GetInstance();
	camera_ = camera;

	axis_->SetTargetCamera(camera_);
	axis_->SetVisible(isVisible_);

}

void Axis::Update() {

	#ifdef _DEBUG

	if (Input::GetInstance()->TriggerKey(DIK_0)) {

		if (isVisible_) {
			isVisible_ = false;
		} else {
			isVisible_ = true;
		}
		
		axis_->SetVisible(isVisible_);

	}

	ImGui::Begin("Stats");

	ImGui::Text("isVisibleAxis: %d", isVisible_);

	ImGui::End();

	#endif

}

void Axis::Draw() {

	#ifdef _DEBUG

	if (isVisible_) {
		axis_->Draw();
	}

	#endif

}