#pragma once

#include "KamataEngine.h"

using namespace KamataEngine;

///-------------------------------------------------------------------------------------------------------------------
/// 計算関数
///

/// <summary>
/// 4x4行列の加算
/// </summary>
/// <param name="m1">4x4行列1</param>
/// <param name="m2">4x4行列2</param>
/// <returns>加算された4x4行列</returns>
Matrix4x4 Add(const Matrix4x4 &m1, const Matrix4x4 &m2);

/// <summary>
/// 4x4行列の減算
/// </summary>
/// <param name="m1">4x4行列1</param>
/// <param name="m2">4x4行列2</param>
/// <returns>減算された4x4行列</returns>
Matrix4x4 Subtract(const Matrix4x4 &m1, const Matrix4x4 &m2);

/// <summary>
/// 4x4行列の乗算
/// </summary>
/// <param name="m1">4x4行列1</param>
/// <param name="m2">4x4行列2</param>
/// <returns>乗算された4x4行列</returns>
Matrix4x4 Multiply(const Matrix4x4 &m1, const Matrix4x4 &m2);

///
/// 
///-------------------------------------------------------------------------------------------------------------------

///-------------------------------------------------------------------------------------------------------------------
/// 
///

Matrix4x4 MakeTranslateMatrix4x4(const Vector3 translate);

Matrix4x4 MakeScaleMatrix(const Vector3 scale);

Matrix4x4 MakeRotateXMatrix(const float radian);

Matrix4x4 MakeRotateYMatrix(const float radian);

Matrix4x4 MakeRotateZMatrix(const float radian);

Matrix4x4 MakeRotateMatrix(const Vector3 rotate);

/// <summary>
/// アフィン変換行列作成
/// </summary>
/// <param name="scale">大きさ</param>
/// <param name="rotate">角度</param>
/// <param name="translate">座標</param>
/// <returns>4x4アフィン行列</returns>
Matrix4x4 MakeAffineMatrix(const Vector3 scale, const Vector3 rotate, const Vector3 translate);

///
/// 
///-------------------------------------------------------------------------------------------------------------------