#include "MathMatrix4x4.h"

///-------------------------------------------------------------------------------------------------------------------
/// 計算関数
///

Matrix4x4 Add(const Matrix4x4 &m1, const Matrix4x4 &m2) {

	// 戻り値
	Matrix4x4 add{};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			add.m[i][j] = m1.m[i][j] + m2.m[i][j];

		}
	}

	return add;
}

Matrix4x4 Subtract(const Matrix4x4 &m1, const Matrix4x4 &m2) {

	// 戻り値
	Matrix4x4 sub{};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			sub.m[i][j] = m1.m[i][j] - m2.m[i][j];

		}
	}

	return sub;
}

Matrix4x4 Multiply(const Matrix4x4 &m1, const Matrix4x4 &m2) {

	// 戻り値
	Matrix4x4 multiply{};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			multiply.m[i][j] = (m1.m[i][0] * m2.m[0][j]) + (m1.m[i][1] * m2.m[1][j]) + (m1.m[i][2] * m2.m[2][j]) + (m1.m[i][3] * m2.m[3][j]);

		}
	}

	return multiply;
}

///
/// 
///-------------------------------------------------------------------------------------------------------------------

Matrix4x4 MakeTranslateMatrix4x4(const Vector3 translate) {

	// 戻り値用変数
	Matrix4x4 translated{};

	// 1.0fの配置
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			if (i == j) {
				translated.m[i][j] = 1.0f;
			}

		}
	}

	translated.m[3][0] = translate.x;
	translated.m[3][1] = translate.y;
	translated.m[3][2] = translate.z;

	return translated;

}

Matrix4x4 MakeScaleMatrix(const Vector3 scale) {

	// 戻り値
	Matrix4x4 scaled{};

	scaled.m[0][0] = scale.x;
	scaled.m[1][1] = scale.y;
	scaled.m[2][2] = scale.z;
	scaled.m[3][3] = 1.0f;

	return scaled;
}

Matrix4x4 MakeRotateXMatrix(const float radian) {

	// 計算結果
	Matrix4x4 rotateX{};

	rotateX.m[0][0] = 1.0f;

	rotateX.m[1][1] = std::cos(radian);
	rotateX.m[1][2] = std::sin(radian);
	rotateX.m[2][1] = -std::sin(radian);
	rotateX.m[2][2] = std::cos(radian);

	rotateX.m[3][3] = 1.0f;

	return rotateX;

}

Matrix4x4 MakeRotateYMatrix(const float radian) {

	// 計算結果
	Matrix4x4 rotateY{};

	rotateY.m[0][0] = std::cos(radian);
	rotateY.m[0][2] = -std::sin(radian);

	rotateY.m[1][1] = 1.0f;

	rotateY.m[2][0] = std::sin(radian);
	rotateY.m[2][2] = std::cos(radian);

	rotateY.m[3][3] = 1.0f;

	return rotateY;

}

Matrix4x4 MakeRotateZMatrix(const float radian) {

	// 計算結果
	Matrix4x4 rotateZ{};

	rotateZ.m[0][0] = std::cos(radian);
	rotateZ.m[0][1] = std::sin(radian);
	rotateZ.m[1][0] = -std::sin(radian);
	rotateZ.m[1][1] = std::cos(radian);

	rotateZ.m[2][2] = 1.0f;
	rotateZ.m[3][3] = 1.0f;

	return rotateZ;

}

Matrix4x4 MakeRotateMatrix(const Vector3 rotate) {

	// 戻り値
	Matrix4x4 rotateXYZ{};

	Matrix4x4 x = MakeRotateXMatrix(rotate.x);
	Matrix4x4 y = MakeRotateYMatrix(rotate.y);
	Matrix4x4 z = MakeRotateXMatrix(rotate.z);

	rotateXYZ = Multiply(x, Multiply(y, z));

	return rotateXYZ;
}

Matrix4x4 MakeAffineMatrix(const Vector3 scale, const Vector3 rotate, const Vector3 translate) {

	// 戻り値
	Matrix4x4 affine{};

	Matrix4x4 S = MakeScaleMatrix(scale);
	Matrix4x4 R = MakeRotateMatrix(rotate);
	Matrix4x4 T = MakeTranslateMatrix4x4(translate);

	affine = Multiply(S, R);
	affine = Multiply(affine, T);

	return affine;
}