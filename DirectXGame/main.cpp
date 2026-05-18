#include <Windows.h>

#include "KamataEngine.h"
using namespace KamataEngine;

#include "MainScene.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	
	///---------------------------------------------------------------------
	/// 初期化
	///

	// DxC
	DirectXCommon *dxC = DirectXCommon::GetInstance();

	// ImGuiマネージャ
	ImGuiManager *imguiManager = ImGuiManager::GetInstance();

	// エンジン
	Initialize(L"LE2B_13_コタニ_タクジ_TR1");

	// シーン
	MainScene *scene = new MainScene();

	///
	///
	///---------------------------------------------------------------------

	///---------------------------------------------------------------------
	/// ループ
	///

	while (true) {

		// エンジン
		if (Update()) {
			break;
		}

		///---------------------------------------
		/// 更新
		///

		// ImGui受付
		imguiManager->Begin();

		scene->Update();

		// ImGui受付終了
		imguiManager->End();

		///
		///
		///---------------------------------------

		///---------------------------------------
		/// 描画
		///

		// 開始
		dxC->PreDraw();

		// メインシーン
		scene->Draw();

		// ImGui
		imguiManager->Draw();

		// 終了
		dxC->PostDraw();

		///
		///
		///---------------------------------------

		// ESCキーで閉じる
		if (Input::GetInstance()->TriggerKey(DIK_ESCAPE)) {
			break;
		}

	}

	///
	///
	///---------------------------------------------------------------------

	///---------------------------------------------------------------------
	/// 終了
	///

	delete scene;

	// エンジン
	Finalize();

	///
	///
	///---------------------------------------------------------------------

	return 0;
}
