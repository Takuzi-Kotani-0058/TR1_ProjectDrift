#include "ControlInformation.h"

void ControlInformation::Update() {

	#ifdef _DEBUG

	ImGui::Begin("Control");

	ImGui::SeparatorText("Car");

	ImGui::Text("W / Up key: Accel");
	ImGui::Text("S / Down / Space key: Brake");
	ImGui::Text("A / Left / key: Steer Left");
	ImGui::Text("D / Right / key: Steer Right");

	ImGui::SeparatorText("Debug");
	ImGui::Text("0 key: Visible / Unvisible Axis");
	ImGui::Text("P key: Change car control mode");


	#endif

}
